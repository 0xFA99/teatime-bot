#ifndef WEATHER_H
#define WEATHER_H

#include <string.h>
#include <stdlib.h>

#include "http_request.h"

#define PARSING_JSON_IMPLEMENTATION
#include "parsing_json.h"

#define WEATHER_URL_FORMAT "https://api.openweathermap.org/data/2.5/weather?id=%s&appid=%s&unit=metric"
#define WEATHER_API_KEY "0755c771fe75b0120ec32ae2e76d84e7"
#define WEATHER_ARRAY_CAP 24

#define LINK_MAX 127

struct WeatherApi {
	char *city;
	char *api;
};

struct WeatherData {
	char *country;
	char *description;
	char *city;
	char *main;
};

int parsingWeatherData(struct WeatherApi *WApi, struct WeatherData *WData);

#ifdef WEATHER_IMPLEMENTATION

static const char*
createWeatherApiURL(struct WeatherApi *api)
{
	char *newURL = (char *)malloc(LINK_MAX);
	if (newURL == NULL) {
		fprintf(stderr, "[ERROR] Failed to allocation memory.\n");
		return NULL;
	}

	snprintf(newURL, LINK_MAX, WEATHER_URL_FORMAT, api->city, api->api);

	return (const char *)newURL;
}

int
parsingWeatherData(struct WeatherApi *WApi, struct WeatherData *WData)
{
	// Create Weather API URL
	if (WApi->api == NULL) {
		WApi->api = (char *)WEATHER_API_KEY;
	}

	const char *Url = createWeatherApiURL(WApi);
	if (Url == NULL) return 1;

	// Get Json Weather
	char *json_weather = http_request(Url);

	free((void*)Url);

	if (json_weather == NULL) return 1;

	// Parsing Json
	// Root
	struct json_object *root = json_tokener_parse(json_weather);

	// Object
	struct json_object *sys;
	if (!json_object_object_get_ex(root, "sys", &sys) ||
		!json_object_is_type(sys, json_type_object)) {

		fprintf(stderr, "[ERROR] Parsing json failed to get sys array\n");
		json_object_put(root);
		return 1;
	}

	// Array
	struct json_object *weather;
	if (!json_object_object_get_ex(root, "weather", &weather) ||
		!json_object_is_type(weather, json_type_array)) {

		fprintf(stderr, "[ERROR] Parsing json failed to get weather array\n");
		return 1;
	}

	// String value
	WData->country = json_object_value(sys, "country");
	WData->city = json_object_value(root, "name");

	char *keyList[WEATHER_ARRAY_CAP] = { NULL };
	keyList[0] = "main";
	keyList[1] = "description";

	if (json_array_object_value(root, keyList, "weather") != 0) {
		return 1;
	}

	WData->main = keyList[0];
	WData->description = keyList[1];

	free(json_weather);
	
	return 0;
}

#endif
#endif
