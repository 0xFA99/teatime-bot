#ifndef HTTP_REQUEST_H
#define HTTP_REQUEST_H

#include <stdlib.h>
#include <string.h>

#include <curl/curl.h>

char *http_request(const char *url);
char *http_request_with_api(const char *url, const char *api);

#ifdef HTTP_REQUEST_IMPLEMENTATION

static const char*
create_api_header_str(const char *api)
{
	char *newApi = (char *)malloc(strlen("X-Api-Key: ") + strlen(api) + 1);

	strcpy(newApi, "X-Api-Key: ");
	strcat(newApi, api);

	return newApi;
}

static size_t
write_callback(void *ptr, size_t size, size_t nmemb, char *data)
{
	size_t realsize = size * nmemb;
	memcpy(data, ptr, realsize);

	return realsize;
}

char*
http_request(const char *url)
{
	CURL *curl;
	CURLcode res;
	char *data = (char *)malloc(4096);

	if (!data) {
		fprintf(stderr, "[ERROR] Memory allocation failed!\n");
		return NULL;
	}

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if (curl) {
		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);

		res = curl_easy_perform(curl);

		if (res != CURLE_OK) {
			fprintf(stderr, "[ERROR] Curl - Perform failed: %s.\n",
					curl_easy_strerror(res));

			free(data);
			return NULL;;
		}

		curl_easy_cleanup(curl);

	} else {
		fprintf(stderr, "[Error] Curl - Failed to initialized curl!\n");
		free(data);
		return NULL;
	}

	curl_global_cleanup();

	return data;
}

char*
http_request_with_api(const char *url, const char *api)
{
	CURL *curl;
	CURLcode res;
	char *data = (char *)malloc(4096);

	if (!data) {
		fprintf(stderr, "[ERROR] Memory allocation failed!\n");
		return NULL;
	}

	curl_global_init(CURL_GLOBAL_ALL);
	curl = curl_easy_init();

	if (curl) {
		struct curl_slist *headers = NULL;

		const char *apiStr = create_api_header_str(api);

		headers = curl_slist_append(headers, apiStr);

		curl_easy_setopt(curl, CURLOPT_URL, url);
		curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
		curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, write_callback);
		curl_easy_setopt(curl, CURLOPT_WRITEDATA, data);

		res = curl_easy_perform(curl);

		free((void *)apiStr);

		if (res != CURLE_OK) {
			fprintf(stderr, "[ERROR] Curl - Perform failed: %s\n",
					curl_easy_strerror(res));

			free(data);
			return NULL;
		}

		curl_easy_cleanup(curl);

	} else {
		fprintf(stderr, "[ERROR] Curl - Failed to initialized curl!\n");

		free((void *)data);
		return NULL;
	}

	curl_global_cleanup();

	return data;
}

#endif
#endif

