#ifndef _DIMU_LIB_H
#define _DIMU_LIB_H

void printThanks();
void setRegVal(int _regId, int _regVal);
void setSpecifiedDigitalRegVal(
    unsigned int _digi,
    int _regId, 
    int _regVal);
void setSpecifiedDigitalStatus(
    unsigned int _digi,
    unsigned int _stat);
#endif
