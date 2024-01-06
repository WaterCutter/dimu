/*
    author: watercutter
    date: 20240103
    brief:
    
    date        editor              desc
    ---------------------------------------------------------------------
    20240103    watercutter         merge to dimu
*/
#include <stdio.h>
#include <fstream>
#include <cstring>
#include <iostream>

using namespace std;
/*
    @brief 
        useless, for static lib test
*/
void printThanks()
{   
    printf("thanks for using this lib\n");
}

/* 
    @brief
        set _refId(pin to target reg) as _regVal 
    @param
        _regId: which reg to set, should be [a,h]
        _regVal: pin output status, 0-low, 1-high
 */
void setRegVal(int _regId, int _regVal)
{
    std::ios_base::sync_with_stdio(false);
    // get status form file
    std::ifstream ifp("../../../../vcc.txt");
    std::string vccStatus, tmp("00000000\0");
    std::getline(ifp,vccStatus);
    ifp.close();
    
    // last status
    if(vccStatus.size() == 8){
        tmp = vccStatus;
    }
   
    // set status to file
    std::ofstream ofp("../../../../vcc.txt");
    tmp.at(_regId) = (_regVal == 0)?'0':'1';
    cout<<"vcc:"<<tmp<<endl;
    ofp << tmp; 
    ofp.flush();
    ofp.close();
}

/* 
    @brief
        c-style implement of setRegVal, abandoned
*/
void setRegValx(int _regId, int _regVal)
{
    // get status form file
    std::ifstream ifp("vcc.txt");
    std::string vccStatus;
    std::getline(ifp,vccStatus);
    ifp.close();
    
    // last status
    char tmp[9] = {'0','0','0','0','0','0','0','0','\0'};
    if(strlen( vccStatus.c_str()) == 8 ){
        // if vcc.txt is not empty|corrupt
        cout<< "got vcc status"<<endl;
        strcpy(tmp, vccStatus.c_str());
    }
   
    // set status to file
    std::ofstream ofp("vcc.txt");
    tmp[_regId] = (_regVal == 0)?'0':'1';
    cout<<"vcc:"<<tmp<<endl;
    ofp << tmp; 
    ofp.close();
}