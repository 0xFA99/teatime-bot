#ifndef WEATHER_H
#define WEATHER_H

#include <string.h>
#include <stdlib.h>
#include <json-c/json.h>

#define HTTP_REQUEST_IMPLEMENTATION
#include "http_request.h"

#define WEATHER_DEFAULT_CITY_ID "1850144"
#define WEATHER_URL_FORMAT "https://api.openweathermap.org/data/2.5/weather?id=%s&appid=%s&unit=metric"
#define WEATHER_API_KEY "0755c771fe75b0120ec32ae2e76d84e7"

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
	char *newURL = (char *)malloc(127);
	if (newURL == NULL) {
		fprintf(stderr, "[ERROR] Failed to allocation memory.\n");
		return NULL;
	}

	snprintf(newURL, 127, WEATHER_URL_FORMAT, api->city, api->api);

	return (const char *)newURL;
}

static void
parsingJsonWeather(json_object *json, struct WeatherData *WData)
{
	struct json_object *object_array;
	struct json_object *object_entry;
	struct json_object *object_value;

	json_object_object_get_ex(json, "name", &object_value);
	WData->city = (char *)json_object_get_string(object_value);

	json_object_object_get_ex(json, "sys", &object_array);
	json_object_object_get_ex(object_array, "country", &object_value);
	WData->country = (char *)json_object_get_string(object_value);

	json_object_object_get_ex(json, "weather", &object_array);
	object_entry = json_object_array_get_idx(object_array, 0);

	json_object_object_get_ex(object_entry, "main", &object_value);
	WData->main = (char *)json_object_get_string(object_value);

	json_object_object_get_ex(object_entry, "description", &object_value);
	WData->description = (char *)json_object_get_string(object_value);
}

int
parsingWeatherData(struct WeatherApi *WApi, struct WeatherData *WData)
{
	// Create Weather API URL
	if (WApi->city == NULL) WApi->city = (char *)WEATHER_DEFAULT_CITY_ID;
	if (WApi->api == NULL) WApi->api = (char *)WEATHER_API_KEY;

	const char *Url = createWeatherApiURL(WApi);
	if (Url == NULL) return 1;

	// Get Json Weather
	char *json_weather = http_request(Url);

	free((void*)Url);

	if (json_weather == NULL) return 1;

	// Parsing Json
	struct json_object *root = json_tokener_parse(json_weather);

	parsingJsonWeather(root, WData);

	json_object_put(root);
	free(json_weather);
	
	return 0;
}

#endif
#endif
