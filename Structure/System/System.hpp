#ifndef System_hpp
#define System_hpp

#define UP 72
#define Down 80
#define Enter 13

#include "../Reader/Reader.hpp"
#include "../GraphicInter/Gui.hpp"

#include <string>
#include <windows.h>


class System{
private:
    Reader read;
    Gui gui;
    
    int control(int _xpos, int min, int opt);
    void SystemInfoI();
    void SystemLanguaje();
public:
    System(std::string title);
    void MenuSyst();
    ~System();
};

#endif