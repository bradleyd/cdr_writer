#ifndef WEBPOST_H
#define WEBPOST_H
#define OPTION_TRUE = 1;
#define URL_BUFFER = 41;
#define CONFIG_FILE "/usr/lib/mysql/plugin/cdr_writer.cfg"

extern const char *str;

char * parse_cfg(char *def);
void PostCall(char *vals);
void LogMe(char *type, char *log);
#endif



