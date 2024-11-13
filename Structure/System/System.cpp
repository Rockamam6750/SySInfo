#include "System.hpp"
#include <conio.h>
#include <iostream>

#define es 0
#define en 1
#define nh 2

int System::control(int _xpos, int min, int opt){
    bool exec = true;

    int coordY = min;
    int minY = min;
    int maxY = minY + (opt - 1);
    
    int maxopt = opt - 1;
    int currentOpt = 0;
    int retOpt = 0;

    while (exec != false){

        gui.Cursor(_xpos, coordY, 0); 
        std::cout << "*";

        if(kbhit){
            switch (getch()){
            case UP:
                gui.Cursor(_xpos, coordY, 1); std::cout << " ";
                if(coordY == minY){
                    currentOpt = maxopt;
                    coordY = maxY;
                }else{
                    coordY--;
                    currentOpt--;
                }
                break;
            case Down:
                gui.Cursor(_xpos, coordY, 1); std::cout << " ";
                if(coordY == maxY){
                    currentOpt = 0;
                    coordY = minY;
                }else{
                    coordY++;
                    currentOpt++;
                }
                break;
            case Enter:
                retOpt = currentOpt;
                gui.Cursor(_xpos, coordY, 1); std::cout << " ";
                exec = false;
                break;
            default:
                break;
            }
        }
    }
    return retOpt;
}

System::System(std::string title){
    SetConsoleTitleA(title.c_str());
}

void System::MenuSyst(){
    bool run = true;
    int x = 0;

    gui.drawScreen();

    gui.Menu();

    while(run != false){
        x = control(27, 4, 3);
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
    }
}

void System::SystemInfoI(){

    bool run = true;

    gui.clear();

    gui.SysInformation();

    while(run != false){
        int x = control(14, 13, 1);
        switch(x){
        case 0:
            run = false;
            break;
        default:
            break;
        }
    }
    gui.clear();
}

void System::SystemLanguaje(){
    bool run = true;
    int opt = 0;

    gui.clear();

    gui.Languaje();

    while(run != false){
        opt = control(27, 4, 4);
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
    }
    gui.clear();
}

System::~System() {}
