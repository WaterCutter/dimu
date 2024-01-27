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
    
    for(int j=0;j<5;j++)
        setSpecifiedDigitalStatus(j,0);

    setSpecifiedDigitalStatus(0,0x76);//Sleep(20);~
    setSpecifiedDigitalStatus(1,0x79);//Sleep(20);~
    setSpecifiedDigitalStatus(2,0x38);//Sleep(20);~
    setSpecifiedDigitalStatus(3,0x38);//Sleep(20);~
    setSpecifiedDigitalStatus(4,0x3f);//Sleep(20);~

    return 0;
}