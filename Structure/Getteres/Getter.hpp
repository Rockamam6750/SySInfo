#ifndef Getter_hpp
#define Getter_hpp
#pragma once 

#include <windows.h>
#include <iostream>
#include <string>
#include <vector>

class Getter{
private:
    SYSTEMTIME syst, loct;
    std::string LTF, TMF;
    std::string _CPU, _Marc, _NCORES;
    std::string _PhisRAM, _PorUsedRAM, _FreePhisRAM; 
    std::string _USERNAME;

public:
    Getter();
    
    void Init();

    void CPU();
    void RAM();
    void Profile();
    void SysT();
    void LocT();

    std::string const getSysT(){return TMF;}
    std::string const getLocT(){return LTF;}
    std::string const getCPUI(){return _CPU;}
    std::string const getCPUIM(){return _Marc;}
    std::string const getCPUNC(){return _NCORES;}
    std::string const getPhisRAM(){return _PhisRAM;}
    std::string const getPorUsedRAM(){return _PorUsedRAM;}
    std::string const getFreePhisRAM(){return _FreePhisRAM;}
    std::string const getUserName(){return _USERNAME;}

    ~Getter();
};

#endif //Getter_hpp