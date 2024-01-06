#include <stdio.h>
#include "../../src/lib.h"
#include <windows.h>
int main(int argc, char* argv[])
{
    printf("hello dimu\n");
    printThanks();
    setRegVal(1,1);
    int tic=1, val=1;
    for(int i=0;i<8;i+=tic)
        setRegVal(i,0);
    for(int i=0;i<8;i+=tic){
        setRegVal(i,val);
        Sleep(300);
        if(i==7){
            i=0;
            val = (val==0)?1:0;
        }
    }
    return 0;
}