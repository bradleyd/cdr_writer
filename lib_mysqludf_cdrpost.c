#ifdef STANDARD
/* STANDARD is defined, don't use any mysql functions */
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifdef __WIN__
typedef unsigned __int64 ulonglong;	/* Microsofts 64 bit types */
typedef __int64 longlong;
#else
typedef unsigned long long ulonglong;
typedef long long longlong;
#endif /*__WIN__*/
#else
#include <my_global.h>
#include <my_sys.h>
#if defined(MYSQL_SERVER)
#include <m_string.h>		/* To get strmov() */
#else
/* when compiled as standalone */
#include <string.h>
#endif
#endif
#include <mysql.h>
#include <ctype.h>
#include "webpost.h"

#ifdef HAVE_DLOPEN
#define MAXMETAPH 8

static pthread_mutex_t LOCK_hostname;

//preprocessor
my_bool cdr_post_init(UDF_INIT *initid, UDF_ARGS *args, char *message);

void cdr_post_deinit(UDF_INIT *initid); 

char *cdr_post(UDF_INIT *initid, UDF_ARGS *args, char *result,
			   unsigned long *length, char *null_value,
			   char *error);

//function prototypes
my_bool cdr_post_init(UDF_INIT *initid, UDF_ARGS *args,
				  char *message)
{
  int i;  
  size_t bytes = 0;
  for(i=0;i < args->arg_count; i++){
    args->arg_type[i] = STRING_RESULT;
    bytes += args->lengths[i];
  }
	
	//itoa(bytes,bffer,10);
  //bytes = args->lengths[0];
  if(!(initid->ptr = malloc(bytes))){
    strcpy(message, "Error allocating memory.");
    return 1;
  } else {
    return 0;
  }

}

void cdr_post_deinit(UDF_INIT *initid) 
{ 
	//if(initid->ptr) 
	free(initid->ptr); 
} 

char *cdr_post(UDF_INIT *initid __attribute__((unused)),
                           UDF_ARGS *args, char *result,
                           unsigned long *length, char *null_value,
                           char *error __attribute__((unused)))
{
	//LogMe("Me", args->args[0]);
  int i;
  char *buff = initid->ptr;
  *length = 0;
  for(i=0;i < args->arg_count; i++){
    if(args->args[i]==NULL){
      *null_value = 1;
			
     break;
    } else {
      //memcpy(buff, args->args[i], args->lengths[i]);
			buff=args->args[i];
      *length += args->lengths[i];
    }
  }
  LogMe("CDR_POST", buff);
  //LogMe((char*)*length);
	PostCall(buff); //call to libcurl--see webpost.h
  return buff;
  //return result;
}


#endif /* HAVE_DLOPEN */
