#ifndef Gui_hpp
#define Gui_hpp

#include <vector>
#include <windows.h>
#include <iostream>
#include "../Reader/Reader.hpp"
#include "../Getteres/Getter.hpp" 

class Gui{
private:
    std::vector<std::string> languaje;
    int currentLanguaje;
    Getter getter;
    Reader reader;
public:
    Gui();

    void cofigureLan(int Langu);
    void drawScreen();
    void Menu();
    void Languaje();
    void SysInformation();
    void Cursor(int x, int y, int type);
    void clear();

    ~Gui();
};


#endif