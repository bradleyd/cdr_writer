gcc -Wall -o lib_mysqludf_cdrpost.so lib_mysqludf_cdrpost.c curlme.c parser.c -lcurl -I/usr/include/mysql -I. -lconfig -shared
cp lib_mysqludf_cdrpost.so /usr/lib/mysql/plugin/
