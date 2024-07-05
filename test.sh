gcc -g -O0 -c -I./include/ simple-curl.c
./libtool --mode=link --tag=CC gcc -g -o performance simple-curl.o ./lib/libcurl.la
./performance
