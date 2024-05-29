#ifndef PARSING_JSON_H
#define PARSING_JSON_H

#define JSON_ARRAY_CAP 10

#include <json-c/json.h>

char *json_object_value(struct json_object *json, const char *key);
int json_array_object_value(struct json_object *json, char *keyList[],
							const char *arrayName);

#ifdef PARSING_JSON_IMPLEMENTATION

char*
json_object_value(struct json_object *json, const char *key)
{
	struct json_object *keyObject;

	if (!json_object_object_get_ex(json, key, &keyObject) &&
		!json_object_is_type(keyObject, json_type_string)) {

		return NULL;
	}

	const char *keyValue = json_object_get_string(keyObject);

	return (char *)keyValue;
}

int
json_array_object_value(struct json_object *json, char *keyList[],
						const char *arrayName)
{
	struct json_object *arrayObject;

	if (!json_object_object_get_ex(json, arrayName, &arrayObject) ||
		!json_object_is_type(arrayObject, json_type_array)) {

		fprintf(stderr, "[ERROR] Failed to get JSON Array!\n");
		return 1;
	}

	int arrayLen = json_object_array_length(arrayObject);

	for (int i = 0; i < arrayLen; i++) {

		struct json_object *arrayEntry = json_object_array_get_idx(arrayObject, i);
		struct json_object *mainObject;
		struct json_object *descriptionObject;

		if (json_object_object_get_ex(arrayEntry, keyList[0], &mainObject) &&
			json_object_is_type(mainObject, json_type_string)) {

			printf("%d\n", i);
			const char *mainValue = json_object_get_string(mainObject);
			keyList[0] = (char *)mainValue;
		}

		if (json_object_object_get_ex(arrayEntry, keyList[1], &descriptionObject) &&
			json_object_is_type(descriptionObject, json_type_string)) {

			printf("%d\n", i);
			const char *descriptionValue = json_object_get_string(descriptionObject);
			keyList[1] = (char *)descriptionValue;
		}
	}

	return 0;
}

#endif
#endif

