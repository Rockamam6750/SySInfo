#include "Getter.hpp"
#include <intrin.h>
#include <cstring>
#include <array>
#include <lmcons.h>
#include <ws2def.h>
#include <ws2tcpip.h>
#include <iphlpapi.h>

#include "../Gotoxy/gotoxy.hpp"

#define usebyt 1024

void Getter::calc(){

    FILETIME ft, fs, fu;

    GetSystemInfo(&sys);
    procen = sys.dwNumberOfProcessors;

    GetSystemTimeAsFileTime(&ft);
    memcpy(&lastcpu, &ft, sizeof(FILETIME));

    self = GetCurrentProcess();

    GetProcessTimes(self, &ft, &ft, &fs, &fu);
    memcpy(&lastsysc, &fs, sizeof(FILETIME));
    memcpy(&lastusc, &fu, sizeof(FILETIME));

}

std::string const Getter::getWinver(){
    
    OSVERSIONINFOEX info;
    ZeroMemory(&info, sizeof(OSVERSIONINFOEX));
    info.dwOSVersionInfoSize = sizeof(OSVERSIONINFOEX);
    GetVersionEx((LPOSVERSIONINFO)&info);//info requires typecasting

    return std::string(std::to_string(info.dwMajorVersion).append(".").append(std::to_string(info.dwMinorVersion)));
}

Getter::Getter(){      
    calc(); 
}

std::string const Getter::getPCName(){
    char name[256];
    DWORD len = sizeof(name);
    GetComputerNameA(name, &len);
    
    return std::string(name);
}

std::string const Getter::getPhisRAM(){
    
    state.dwLength = sizeof(state);
    GlobalMemoryStatusEx(&state);
    
    return std::to_string(((state.ullTotalPhys / usebyt) / usebyt)) + "MB";
}

std::string const Getter::getPorUsedRAM(){
    
    state.dwLength = sizeof(state);
    GlobalMemoryStatusEx(&state);

    return std::to_string(state.dwMemoryLoad).append("%");
}

std::string const Getter::getFreePhisRAM(){
    
    state.dwLength = sizeof(state);
    GlobalMemoryStatusEx(&state);
    
    return std::to_string((state.ullAvailPhys/ usebyt) /usebyt) + "MB";
}

std::string const Getter::getCPLoad(){ // This is not my own code, I took it from
//https://www.reddit.com/r/learnprogramming/comments/nbxhsn/heres_how_to_get_cpu_usage_percentage_of_current/?tl=es-es
//
    FILETIME ftime, fsys, fuser;
    ULARGE_INTEGER now, sys, user;
    double percent;

    GetSystemTimeAsFileTime(&ftime);
    memcpy(&now, &ftime, sizeof(FILETIME));

    GetProcessTimes(self, &ftime, &ftime, &fsys, &fuser);
    memcpy(&sys, &fsys, sizeof(FILETIME));
    memcpy(&user, &fuser, sizeof(FILETIME));
    percent = (sys.QuadPart - lastsysc.QuadPart) +
        (user.QuadPart - lastusc.QuadPart);
    percent /= (now.QuadPart - lastcpu.QuadPart);
    percent /= procen;
    lastcpu = now;
    lastusc = user;
    lastsysc = sys;
    return std::to_string(percent * 100);
}

void Getter::getCPUI(std::string *_CPU, std::string *_Vend, std::string *_Cores){
    std::string cpub;
    std::array<int, 4> data = {};
    std::array<int, 3> keys = {1,3,2};
    std::array<int, 4> integerbuffer = {};
    constexpr size_t sizeofIntegerBuffer = sizeof(int) * integerbuffer.size();

    std::array<char, 64> McharBuffer = {};
    std::array<char, 16> LcharBuffer = {};

    constexpr std::array<unsigned int, 3> functionIDs = {
        0x8000'0002,
        0x8000'0003,
        0x8000'0004
    };

//Marck
     __cpuid(data.data(), 0);

    for(int x = 0; x < 3; x++) reinterpret_cast<int *>(LcharBuffer.data())[x] = data[keys[x]];

    *_Vend = std::string(LcharBuffer.data());

// Processor example: intel i...
    for(int id : functionIDs){
        __cpuid(integerbuffer.data(), id);
        memcpy(McharBuffer.data(), integerbuffer.data(), sizeofIntegerBuffer);
        cpub.append(McharBuffer.data());
    }
    *_CPU = cpub;
    
    GetSystemInfo(&sys);
    *_Cores = std::to_string(sys.dwNumberOfProcessors);
    
}

std::string const Getter::Profile(){
    char name[UNLEN + 1];
    DWORD size = UNLEN;
    
    GetUserNameA(name, &size);
    
    return std::string(name);
}

std::string const Getter::getSysT(){
    GetSystemTime(&syst);
    std::string TMF;
    std::string sh;
    std::string sm;
    std::string ss;

    int h = syst.wHour;
    int m = syst.wMinute;
    int s = syst.wSecond;

    if(h < 10){
        sh = "0" + std::to_string(h);
    }else sh = std::to_string(h);

    if(m < 10){
        sm = "0" + std::to_string(m);
    }else sm = std::to_string(m);

    if(s < 10){
        ss = "0" + std::to_string(s);
    }else ss = std::to_string(s);

    TMF =  sh + ":" + sm + ":" + ss;
    return TMF;
}

std::string const Getter::getLocT(){
    GetLocalTime(&loct);
    std::string LTF;

    std::string sh;
    std::string sm;
    std::string ss;

    int h = loct.wHour;
    int m = loct.wMinute;
    int s = loct.wSecond;

    if(h < 10 ){
        sh = "0" + std::to_string(h);
    }else sh = std::to_string(h);

    if(m < 10){
        sm = "0" + std::to_string(m);
    }else sm = std::to_string(m);

    if(s < 10){
        ss = "0" + std::to_string(s);
    }else ss = std::to_string(s);

    LTF =  sh + ":" + sm + ":" + ss;
    return LTF;
}

void Getter::IPV(std::string *IPv4, std::string *Gate, std::string *Adap){
    
    IP_ADAPTER_INFO *padpi;
    ULONG ulOub;
    DWORD retval;

    padpi = (IP_ADAPTER_INFO *) malloc(sizeof(IP_ADAPTER_INFO));

    ulOub = sizeof(IP_ADAPTER_INFO);

    if(GetAdaptersInfo(padpi, &ulOub) != ERROR_SUCCESS){
        free(padpi);
        padpi = (IP_ADAPTER_INFO*)malloc(ulOub);
    }

    if((retval = GetAdaptersInfo(padpi, &ulOub)) != ERROR_SUCCESS){
        *IPv4 = "NULL";
        *Gate = "NULL";
        *Adap = "NULL";
        return;
    }

    PIP_ADAPTER_INFO padap = padpi;
    std::string g, objt = "192.168";
    
    while(padap){
        g = padap->IpAddressList.IpAddress.String;
        if((objt.compare(0, 6, g, 0, 6)) == 0){
            *Adap = padap->AdapterName;
            *IPv4 = padap->IpAddressList.IpAddress.String;
            *Gate = padap->GatewayList.IpAddress.String;
        }
        padap = padap->Next;
    }   
    if(padpi){
        free(padpi);
    }
    
}


Getter::~Getter() {}

