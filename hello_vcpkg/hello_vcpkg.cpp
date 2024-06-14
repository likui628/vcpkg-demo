#include <string>
#include <fmt/core.h>
#include <curl/curl.h>
#include <cryptopp/cryptlib.h>

#define CRYPTOPP_ENABLE_NAMESPACE_WEAK 1
#include <cryptopp/md5.h>

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
	curl_easy_setopt(conn, CURLOPT_URL, "http://jsonplaceholder.typicode.com/posts/1");
	curl_easy_setopt(conn, CURLOPT_ERRORBUFFER, errorBuffer);
	curl_easy_setopt(conn, CURLOPT_WRITEFUNCTION, writer);
	curl_easy_setopt(conn, CURLOPT_WRITEDATA, &buffer);

	CURLcode res = curl_easy_perform(conn);
	if (res != CURLE_OK) {
		fmt::print("Failed to get: {}\n", errorBuffer);
	}
	else {
		fmt::print("Response Data: {}\n", buffer);
	}
	curl_easy_cleanup(conn);
}

void crypto_test() {
	using namespace CryptoPP;

	Weak::MD5 hash;
	fmt::print("Name: {}\n", hash.AlgorithmName());
	fmt::print("Digest size: {}\n", hash.DigestSize());
	fmt::print("Block size: {}\n", hash.BlockSize());
}

int main()
{
	curl_test();
	crypto_test();
}