#include <string>
#include <fmt/core.h>
#include <curl/curl.h>

static char errorBuffer[CURL_ERROR_SIZE];
static std::string buffer;

static int writer(char* data, size_t size, size_t nmemb, std::string* writerData)
{
	if (writerData == NULL)
		return 0;

	writerData->append(data, size * nmemb);

	return size * nmemb;
}


void curl_test() {
	CURL* conn = curl_easy_init();
	curl_easy_setopt(conn, CURLOPT_URL, "https://jsonplaceholder.typicode.com/posts/1");
	curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);

	CURLcode res = curl_easy_perform(conn);
	if (res != CURLE_OK) {
		fmt::format("Failed to get '%s'\n", errorBuffer);
		exit(EXIT_FAILURE);
	}
	else {
		fmt::print("Response Data: {}\n", buffer);
	}
	curl_easy_cleanup(conn);
}

int main()
{
	curl_test();
}