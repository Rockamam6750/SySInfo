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
    SYSTEMTIME syst, loct;
    std::string LTF, TMF;
    std::string _CPU, _Marc, _NCORES, _CPULOAD;
    std::string _PhisRAM, _PorUsedRAM, _FreePhisRAM; 
    std::string _USERNAME, _PCNAME;
    std::string Winver;
    std::string IPV4, IPV6, GATEWAY, ADAPTNAME;
    int procen;
    HANDLE self;
    ULARGE_INTEGER lastcpu, lastsysc, lastusc;
    SYSTEM_INFO sys;
public:
    Getter();

    void CPU();
    void RAM();
    void Profile();
    void SysT();
    void LocT();
    void IPV();
    void PCName();
    void CPULoad();
    void Update();
    void calc();
    void getopv();

    std::string const getSysT(){return TMF;}
    std::string const getLocT(){return LTF;}
    std::string const getCPUI(){return _CPU;}
    std::string const getCPUIM(){return _Marc;}
    std::string const getCPUNC(){return _NCORES;}
    std::string const getPhisRAM(){return _PhisRAM;}
    std::string const getPorUsedRAM(){return _PorUsedRAM;}
    std::string const getFreePhisRAM(){return _FreePhisRAM;}
    std::string const getUserName(){return _USERNAME;}
    std::string const getPCName(){return _PCNAME;}
    std::string const getIPV4(){return IPV4;}
    std::string const getGaWay(){return GATEWAY;}
    std::string const getAdapN(){return ADAPTNAME;}
    std::string const getCPLoad(){return _CPULOAD;}
    std::string const getWinver(){return Winver;}

    ~Getter();
};

#endif //Getter_hpp