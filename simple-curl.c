#include <curl/curl.h>
#include <stdio.h>
#include <stdlib.h>

void doit(CURLSH* share, char *url)  {
  struct curl_slist *headers = NULL;
  headers = curl_slist_append(headers, "Connection: close");
  headers = curl_slist_append(headers, "Host: hashcode.theinnovationlab.in");

  CURL* curl = curl_easy_init();
  curl_easy_setopt(curl, CURLOPT_URL, url);
  curl_easy_setopt(curl, CURLOPT_HTTPGET, 1L);
  curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
  curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
  curl_easy_setopt(curl, CURLOPT_SSL_OPTIONS, CURLSSLOPT_EARLYDATA);
  curl_easy_setopt(curl, CURLOPT_HTTP_VERSION, CURL_HTTP_VERSION_1_1);
  curl_easy_setopt(curl, CURLOPT_SHARE, share);

  curl_easy_perform(curl);
  curl_easy_cleanup(curl);
}
int main(void) {
  CURLSH* share = curl_share_init();
  curl_share_setopt(share, CURLSHOPT_SHARE, CURL_LOCK_DATA_SSL_SESSION);

  doit(share, "https://hashcode.theinnovationlab.in/");
  doit(share, "https://hashcode.theinnovationlab.in/register");
  return 0;
}
