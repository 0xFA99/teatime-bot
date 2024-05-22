#include <stdio.h>
#include <stdlib.h>

#include "concord/discord.h"
#include "concord/log.h"

#define WEATHER_IMPLEMENTATION
#include "weather.h"

u64snowflake g_app_id;

void on_ready(struct discord *client, const struct discord_ready *event);
void on_slash_command_create(struct discord *client, const struct discord_message *event);
void on_interaction_create(struct discord *client, const struct discord_interaction *event);

int
main(int argc, char *argv[])
{
	const char *config_file;
	if (argc > 1) config_file = argv[1];
	else config_file = "config.json";

	ccord_global_init();

	struct discord *client = discord_config_init(config_file);

	discord_set_on_command(client, "!weather_create", &on_slash_command_create);
	discord_set_on_ready(client, &on_ready);
	discord_set_on_interaction_create(client, &on_interaction_create);

	discord_run(client);

	ccord_global_cleanup();

	return 0;
}

void
on_ready(struct discord *client, const struct discord_ready *event)
{
	log_info("Bot Successfully connected to Discod as %s#%s!",
			event->user->username, event->user->discriminator);

	g_app_id = event->application->id;
}

void
on_slash_command_create(struct discord *client, const struct discord_message *event)
{
	if (event->author->bot) return;

	struct discord_application_command_option options[] = {
		{
			.type			= DISCORD_APPLICATION_OPTION_STRING,
			.name			= "city_id",
			.description	= "example_param",
			.required		= true
		},
		{
			.type			= DISCORD_APPLICATION_OPTION_STRING,
			.name			= "weather_api",
			.description	= "weather_api_fill",
			.required		= false
		}
	};

	struct discord_create_guild_application_command params = {
		.name				= "fill-param",
		.description		= "example fill params",
		.default_permission	= true,
		.options 			=
			&(struct discord_application_command_options) {
				.size	= sizeof(options) / sizeof *options,
				.array	= options
			}
	};

	discord_create_guild_application_command(client, g_app_id, event->guild_id,
			&params, NULL);
}

void
on_interaction_create(struct discord *client, const struct discord_interaction *event)
{
	if (event->type != DISCORD_INTERACTION_APPLICATION_COMMAND) return;
	if (!event->data || !event->data->options) return;

	struct WeatherApi	*wa = (struct WeatherApi *)malloc(sizeof(struct WeatherApi));
	wa->api = NULL;

	struct WeatherData	*wd = (struct WeatherData *)malloc(sizeof(struct WeatherData));

	for (int i = 0; i < event->data->options->size; ++i) {
		char *name	= event->data->options->array[i].name;
		char *value	= event->data->options->array[i].value;

		if (0 == strcmp(name, "city_id")) {
			wa->city = value;
		}
		else if (0 == strcmp(name, "weather_api")) {
			wa->api = value;
		}
	}

	if (parsingWeatherData(wa, wd) != 0) {
		wd->country = (char *)"Blank";
		wd->city = (char *)"Blank";
		wd->main = (char *)"Blank";
		wd->description = (char *)"Blank";
	}

	char buff[DISCORD_MAX_MESSAGE_LEN] = "";
	snprintf(buff, sizeof(buff),
			"Country: %s\n"
			"City: %s\n"
			"Weather: %s\n"
			"Description: %s\n",
			wd->country, wd->city, wd->main, wd->description);

	struct discord_interaction_response params = {
		.type	= DISCORD_INTERACTION_CHANNEL_MESSAGE_WITH_SOURCE,
		.data	= &(struct discord_interaction_callback_data) {
					.content = buff
				}
	};

	discord_create_interaction_response(client, event->id, event->token,
			&params, NULL);

	free((void *)wa);
	free((void *)wd);
}

