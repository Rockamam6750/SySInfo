#include "System.hpp"
#include <conio.h>
#include <thread>
#include <chrono>

#include <iostream>

#define ctrpv -1 //control flag

#define es 0
#define en 1
#define nh 2

System::System(std::string title){
    SetConsoleTitleA(title.c_str());

    for(int x = 0; x < 3; x++){
        Control tm;
        vc.push_back(tm);
    }

    vc[0].InitControl(39, 4, 3);
    vc[1].InitControl(14, 13, 1);
    vc[2].InitControl(27, 4, 4);

}

void System::MenuSyst(){
    bool run = true;
    int x = ctrpv;

    gui.drawScreen();
    gui.Menu();

    while(run != false){
        vc[0].ControlUnit(&x);
        switch(x){
            case 0:
                SystemInfoI();
                gui.Menu();
            break;
            case 1:
                SystemLanguaje();
                gui.Menu();
            break;
            case 2:
                run = false;
            break;
        default:
            break;
       }
       Sleeper(15);
    }
}

void System::Sleeper(int miliseconds){
    std::this_thread::sleep_for(std::chrono::milliseconds(miliseconds));
}

void System::SystemInfoI(){

    bool run = true;
    int x = ctrpv;

    gui.clear();
    gui.SysInformation();

    while(run != false){
        //gui.SysInformation();
        gui.USysInf();
        vc[1].ControlUnit(&x);
        switch(x){
        case 0:
            run = false;
            break;
        default:
            break;
        }
        Sleeper(15);
    }
    gui.clear();
}

void System::SystemLanguaje(){
    bool run = true;
    int opt = ctrpv;

    gui.clear();
    gui.Languaje();

    while(run != false){
        vc[2].ControlUnit(&opt);
        switch(opt){
        case 0:
            gui.cofigureLan(es);
            gui.Languaje();
            break;
        case 1:
            gui.cofigureLan(en);
            gui.Languaje();
            break;
        case 2:
            gui.cofigureLan(nh);
            gui.Languaje();
            break;
        case 3:
            run = false;
            break;
        default:
            break;
        }
        Sleeper(10);
    }
    gui.clear();
}

System::~System() {}
