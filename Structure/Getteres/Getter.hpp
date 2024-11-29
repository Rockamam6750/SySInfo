#ifndef Getter_hpp
#define Getter_hpp
#define _WIN32_WINNT _WIN32_WINNT_WIN10

#include <winsock2.h>
#include <windows.h>
#include <iostream>
#include <string>
#include <vector>
#include <pdh.h>

class Getter{
private:
    SYSTEM_INFO sys;
    SYSTEMTIME syst, loct;
    MEMORYSTATUSEX state;
    HANDLE self;
    ULARGE_INTEGER lastcpu, lastsysc, lastusc;
    int procen;
    
public:
    Getter();

    void IPV(std::string *IPv4, std::string *Gate, std::string *Adap);
    void calc();

    void getCPUI(std::string *_CPU, std::string *_Vend, std::string *_Cores);

    std::string const getSysT();
    std::string const getLocT();
    std::string const Profile();
    std::string const getPCName();
    
    std::string const getPhisRAM();
    std::string const getPorUsedRAM();
    std::string const getFreePhisRAM();
    std::string const getCPLoad();
    std::string const getWinver();

    ~Getter();
};

#endif //Getter_hpp