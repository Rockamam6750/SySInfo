#include "Control.hpp"
#include "../Gotoxy/gotoxy.hpp"
#include <iostream>

//Key Values
#define UP 72
#define Right 77
#define Left 75
#define Down 80
#define Enter 13

Control::Control(){}

void Control::InitControl(int x, int y, int opt){
    //Vars 
    x_pos = x;
    y_pos = y;
    optnum = opt;
    y_Cpos = y;
    currentopt = 0;
}

void Control::ControlUnit(int *p){

    int max_ypos = y_pos + (optnum - 1);  

    int min_ypos = y_pos; 
    int maxopt = optnum - 1; 
    bool ret = false; // flag in case the user press enter

    gotoxy(x_pos, y_Cpos, BLACK, GREEN); std::cout << "*";

    if(kbhit()){ 
        switch (getch()){ 
        case UP:
            gotoxy(x_pos, y_Cpos, BLACK, GREEN); std::cout << " ";
            if(y_Cpos == min_ypos){
                currentopt = maxopt;
                y_Cpos = max_ypos;
            }else{
                y_Cpos--;
                currentopt--;
            }
        break;
        case Down:
        gotoxy(x_pos, y_Cpos, BLACK, GREEN); std::cout << " "; 
            if(y_Cpos == max_ypos){
                currentopt = 0;
                y_Cpos = min_ypos;
            }else{
                y_Cpos++;
                currentopt++;
            }
        break;
        case Enter:
            *p = currentopt;
            ret = true;
            gotoxy(x_pos, y_Cpos, BLACK, GREEN); std::cout << " ";        
        break;
        default:
        break;
        }
    }
    //gotoxy(0, 21, BLACK, GREEN); std::cout << currentopt;       
    if(ret != true) *p = -1;
}

Control::~Control(){}
