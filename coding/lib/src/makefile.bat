:: generating object file
g++ -c ./lib.c -o ./lib.o
:: pack as static lib
ar -rcs ./liblib.a ./lib.o
