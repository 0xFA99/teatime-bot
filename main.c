#include <stdio.h>
#include <assert.h>

#include "concord/discord.h"
#include "concord/log.h"

#define COMMANDS_IMPLEMENTATION
#include "commands.h"

u64snowflake g_app_id;

void on_ready(struct discord *client, const struct discord_ready *event);

int
main(int argc, char *argv[])
{
	const char *config_file;
	if (argc > 1) config_file = argv[1];
	else config_file = "config.json";

	ccord_global_init();

	struct discord *client = discord_config_init(config_file);
	assert(NULL != client && "Couldn't initialize client");

	discord_add_intents(client, DISCORD_GATEWAY_MESSAGE_CONTENT);

	discord_set_on_ready(client, &on_ready);

	create_command_interaction(client, g_app_id);

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

	// PRESENCES
	struct discord_activity activities[] = {
		{
			.name = "Mocca :3",
			.type = DISCORD_ACTIVITY_LISTENING,
			.details = "Waiting some order!"
		}
	};

	struct discord_presence_update status = {
		.activities =
			&(struct discord_activities) {
				.size = sizeof(activities) / sizeof *activities,
				.array = activities
			},
		.status = "online",
		.afk = false,
		.since = discord_timestamp(client)
	};

	discord_update_presence(client, &status);
}

