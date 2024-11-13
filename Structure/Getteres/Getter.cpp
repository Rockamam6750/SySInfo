#include "Getter.hpp"
#include <intrin.h>
#include <cstring>
#include <array>
#include <lmcons.h>

#define usebyt 1024

Getter::Getter(){
    Profile();
    CPU();
    RAM();
    SysT();
    LocT();
}

void Getter::Init(){
    RAM();
    SysT();
    LocT();
}

void Getter::CPU(){

    std::vector<std::array<int, 4>>hi = {};
    std::array<int, 4> integerbuffer = {};
    constexpr size_t sizeofIntegerBuffer = sizeof(int) * integerbuffer.size();

    std::array<char, 64> McharBuffer = {};
    std::array<char, 32> LcharBuffer = {};

    constexpr unsigned int IDG = 0x1B;
    constexpr std::array<unsigned int, 3> functionIDs = {
        0x8000'0002,
        0x8000'0003,
        0x8000'0004
    };

//Marck
    for(unsigned int y = 0; y <= IDG; y++){
        __cpuidex(integerbuffer.data(), y, 0);
        hi.emplace_back(integerbuffer);
    }
    
    *reinterpret_cast<int*>(LcharBuffer.data()) = hi[0][1];
    *reinterpret_cast<int*>(LcharBuffer.data() + 4) = hi[0][3];
    *reinterpret_cast<int*>(LcharBuffer.data() + 8) = hi[0][2];
    _Marc.append(std::string(LcharBuffer.data()));

// Processor example: intel i...
    for(int id : functionIDs){
        __cpuid(integerbuffer.data(), id);
        memcpy(McharBuffer.data(), integerbuffer.data(), sizeofIntegerBuffer);
        _CPU.append(McharBuffer.data());
    }

    SYSTEM_INFO sysinfo;
    GetSystemInfo(&sysinfo);
    _NCORES.append(std::to_string(sysinfo.dwNumberOfProcessors));
    
}

void Getter::RAM(){

    MEMORYSTATUSEX state;
    state.dwLength = sizeof(state);
    GlobalMemoryStatusEx(&state);

    _PhisRAM = std::to_string(((state.ullTotalPhys / usebyt)/ usebyt)) + "MB";
    _FreePhisRAM = std::to_string((state.ullAvailPhys/ usebyt)/usebyt) + "MB";
    _PorUsedRAM = std::to_string(state.dwMemoryLoad).append("%");

}

void Getter::Profile(){

    char name[UNLEN + 1];
    DWORD size = UNLEN;
    
    GetUserNameA(name, &size);
    
    _USERNAME = std::string(name);

}

void Getter::SysT(){
    GetSystemTime(&syst);
    
    std::string sh;
    std::string sm;
    std::string ss;

    int h = syst.wHour;
    int m = syst.wMinute;
    int s = syst.wSecond;


    if(h < 10 || h == 0){
        sh = "0" + std::to_string(h);
    }else{
        sh = std::to_string(h);
    }

    if(m < 10 || m == 0){
        sm = "0" + std::to_string(m);
    }else{
        sm = std::to_string(m);
    }

    if(s < 10 || s == 0){
        ss = "0" + std::to_string(s);
    }else{
        ss = std::to_string(s);
    }

    TMF =  sh + ":" + sm + ":" + ss;
}

void Getter::LocT(){
    GetLocalTime(&loct);
    std::string sh;
    std::string sm;
    std::string ss;

    int h = loct.wHour;
    int m = loct.wMinute;
    int s = loct.wSecond;


    if(h < 10 || h == 0){
        sh = "0" + std::to_string(h);
    }else{
        sh = std::to_string(h);
    }

    if(m < 10 || m == 0){
        sm = "0" + std::to_string(m);
    }else{
        sm = std::to_string(m);
    }

    if(s < 10 || s == 0){
        ss = "0" + std::to_string(s);
    }else{
        ss = std::to_string(s);
    }

    LTF =  sh + ":" + sm + ":" + ss;
}

Getter::~Getter() {}

