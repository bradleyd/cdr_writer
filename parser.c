#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <libconfig.h>
#include "webpost.h"


char * parse_cfg(char *def) {
  config_t cfg;
	config_init(&cfg);
	const char *str;
	char *results=malloc(41);
	/*check for null pointer */
  if (results == NULL) {
	   LogMe("CDR_ERROR", "Results err: No memory allocated");	
		 exit(1);
	}
  /*check if file exists */
  if(! config_read_file(&cfg, CONFIG_FILE)) {
    /*fprintf(stderr, "%s:%d - %s\n", config_error_file(&cfg),
            config_error_line(&cfg), config_error_text(&cfg)); */
		//fprintf(stderr, "no config file name %s\n", CONFIG_FILE);
		LogMe("CDR_ERROR", "Cant find config file");
    config_destroy(&cfg);
    //return(EXIT_FAILURE);
		exit(1);
  }
  /* get values from url */
	int i;
	char *buff;
	buff=malloc(100);
	/*check for null pointer */
	if(buff == NULL) {
		LogMe("CDR_ERROR", "Buffer err: No memory allocated");
		exit(1);
	}
  /* build string for config header */
  i=snprintf(buff,100,"app.%s", def);
  if(config_lookup_string(&cfg, buff, &str)) {
    /*clears block every time called */
		bzero(results,41);
		strcpy(results,str);
    //LogMe("IN_PARSER",str);		
  } else {
    //fprintf(stderr, "No '%s' setting in configuration file.\n", def);
		LogMe("CDR_ERROR", "No setting in configuration file");
  }
  config_destroy(&cfg);
	free(buff);
	return results;

}

