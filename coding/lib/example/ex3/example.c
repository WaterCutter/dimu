#include <stdio.h>
#include "../../src/lib.h"
#include <windows.h>

unsigned int tics = 0;
int main(int argc, char* argv[])
{
    printf("hello dimu\n");
    printThanks();
    // for(int i=0;i<1;i++)
    //     setSpecifiedDigitalRegVal(0,1,1);
    int tic=1, val=1;
    for(int i=0;i<8;i+=tic)
        for(int j=0;j<4;j++)
            setSpecifiedDigitalRegVal(j,i,0);

    for(int i=0;i<8;i+=tic){
        for(int j=0;j<4;j++)
            setSpecifiedDigitalRegVal(j,i,val);//Sleep(20);
    
        Sleep(400);
        if(i==7){
            i=0;
            val = (val==0)?1:0;
        }
        printf("%d # ", tics++);
        
    }
    
    return 0;
}