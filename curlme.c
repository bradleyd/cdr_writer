#include <stdio.h>
#include <stdlib.h>
#include <curl/curl.h>
#include "webpost.h"
#include <string.h>
#include <syslog.h>

void PostCall(char *vals) {
  CURL *curl;
  CURLcode res;
  int ret;
  char params[900];
  //char *url_p="http://10.0.1.95:3000/cdr_insert/insert";
  char *url_p=(char*)malloc(41);
	//url_p=parse_cfg("url");
	bzero(url_p,41);
	strcpy(url_p,parse_cfg("url")); 
  //LogMe("CDR", parse_cfg("url")); /*log the url for debuggin */
	ret=snprintf(params,sizeof(params),"cdr_value=%s",vals); /*copy val into params char */
  curl = curl_easy_init();

  if(curl) {
		curl_easy_setopt(curl, CURLOPT_NOPROGRESS , 1 );
		curl_easy_setopt(curl, CURLOPT_VERBOSE, 1 );
    //curl_easy_setopt(curl, CURLOPT_URL, "http://10.0.1.95:3000/cdr_insert/insert");
    curl_easy_setopt(curl, CURLOPT_URL, url_p);
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, params);

    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);

    /* always cleanup */
    curl_easy_cleanup(curl);
		free(url_p);
  }
}

void LogMe(char *type, char *log) {
	openlog (type, LOG_PID|LOG_CONS, LOG_USER);
	syslog (LOG_INFO, log);
	closelog ();
}

