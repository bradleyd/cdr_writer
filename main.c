#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parseme.h"


int main(void) {
	char *ptr =(char *) malloc(100);
  int i,j;
	char *a[] = {"url", "uname"};
	parse_cfg("url");
	//for(j=0; j< 2; j++) {
	//	  printf("arr:%s\n", a[j]);
  //    t=parse_cfg(a[j]);
	//    printf("after:%s\n", t);
	//	  //i=snprintf(ptr, strlen(t), "post: %s", parse_cfg(a[j]));
	//    //printf("%s\n", ptr);
	//		t= NULL;
	//}
  
	//printf("%s\n", t);
	//free(ptr);
	//free(t);
	return 0;
}

