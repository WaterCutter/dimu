g++ -c ../../src/lib.c -o ../../src/lib.o
ar -rcs ../../lib/liblib.a ../../src/lib.o

g++ example.c -o main -L ../../lib -llib 
