#ifndef System_hpp
#define System_hpp

#define UP 72
#define Down 80
#define Enter 13

#include "../Reader/Reader.hpp"
#include "../Control/Control.hpp"
#include "../GraphicInter/Gui.hpp"

#include <string>
#include <windows.h>


class System{
private:
    Reader read;
    Gui gui;
    std::vector<Control> vc;
    void Sleeper(int miliseconds);
    void SystemInfoI();
    void SystemLanguaje();
public:
    System(std::string title);
    void MenuSyst();
    ~System();
};

#endif