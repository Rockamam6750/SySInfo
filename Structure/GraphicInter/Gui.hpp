#ifndef Gui_hpp
#define Gui_hpp

#include <vector>
#include <windows.h>
#include <iostream>
#include "../Reader/Reader.hpp"
#include "../Getteres/Getter.hpp" 

struct Net{
    std::string Ip;
    std::string Gateway;
    std::string AdpaIf;
};

struct CPU{
    std::string _CPU;
    std::string _Vendor;
    std::string _Cores;
};

class Gui{
private:
    std::vector<std::string> languaje;
    struct CPU c;
    struct Net n;
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
    void USysInf();
    void Cursor(int x, int y, int type);
    void clear();

    ~Gui();
};


#endif