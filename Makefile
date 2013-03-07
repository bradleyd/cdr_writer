#brad smith 08/01/10

SOURCE = lib_mysqludf_cdrpost.c curlme.c parser.c 
HEADERS = parseme.h webpost.h

.PREFIXES = .c .o
OBJECTS   = ${SOURCE:.c=.o}                              
CC        = gcc
CFLAGS    = -lcurl -I/usr/include/mysql -I. -lconfig -shared
RM        = /usr/bin/rm -f                            
MV        = /usr/bin/mv -f                            
CP        = /usr/bin/cp -f                             

.c.o:                                                 
	    ${CC} -c ${CFLAGS} $<                              

lib_mysqludf_cdrpost.so: ${OBJECTS}
	${CC} -o $@ ${OBJECTS} -lm

all: lib_mysqludf_cdrpost.so

clean:                                                 
	    -${RM} lib_mysqludf_cdrpost.so *.o core                             
				
#install: lib_mysqludf_cdrpost.so
#	    ${MV} lib_mysqludf_cdrpost.so /usr/lib/mysql/plugin                         		${CP} ${HEADERS} /usr/local/include                
#			@echo "mysql udf cdr wirter is ready!"                       
#
#gcc -Wall -o lib_mysqludf_cdrpost.so lib_mysqludf_cdrpost.c curlme.c parser.c -lcurl -I/usr/include/mysql -I. -lconfig -shared
#cp lib_mysqludf_cdrpost.so /usr/lib/mysql/plugin/
