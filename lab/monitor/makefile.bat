:: generating object file
g++ -c ./mmonitor.c -o ./mmonitor.o
:: pack as static lib
ar -rcs ./mmonitor.a ./mmonitor.o