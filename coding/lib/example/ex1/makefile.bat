:: generating object file
g++ -c ../../src/lib.c -o ../../src/lib.o
:: pack as static lib
ar -rcs ../../lib/liblib.a ../../src/lib.o

:: complie and link as application
g++ example.c -o main -L ../../lib -llib 
