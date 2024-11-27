#include "Gui.hpp"
#include "../Gotoxy/gotoxy.hpp"

Gui::Gui(){
    std::setlocale(LC_CTYPE, ".UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    currentLanguaje = reader.activeLan();
    languaje = reader.setlanguaje(currentLanguaje, 10);
}

void Gui::cofigureLan(int langu){
    languaje = reader.setlanguaje(langu, currentLanguaje);
    currentLanguaje = langu;
    clear(); 
}

void Gui::drawScreen(){

    for(int x = 1; x <= 100; x++){
        gotoxy(x,0, BLACK, RED); std::cout << "═";
        gotoxy(x,14, BLACK, RED); std::cout << "═";
    }
    
    gotoxy(0,0, BLACK, RED); std::cout << "╔";
    gotoxy(100,0, BLACK, RED); std::cout << "╗";
    
    for(int y = 1; y <= 13; y++){
        gotoxy(0,y, BLACK, RED); std::cout << "║";
        gotoxy(100,y, BLACK, RED); std::cout << "║";
    }

    gotoxy(0,14, BLACK, RED); std::cout << "╚";
    gotoxy(100,14, BLACK, RED); std::cout << "╝";

}

void Gui::Menu(){

    gotoxy(40, 2, BLACK, GREEN); std::cout << languaje[0];
    gotoxy(40, 4, BLACK, GREEN); std::cout << languaje[1];
    gotoxy(40, 5, BLACK, GREEN); std::cout << languaje[2];
    gotoxy(40, 6, BLACK, GREEN); std::cout << languaje[3];

}

void Gui::Languaje(){

    gotoxy(40, 2, BLACK, GREEN); std::cout << languaje[2];
    gotoxy(40, 4, BLACK, GREEN); std::cout << "Español";
    gotoxy(40, 5, BLACK, GREEN); std::cout << "English";
    gotoxy(40, 6, BLACK, GREEN); std::cout << "日本語";
    gotoxy(40, 7, BLACK, GREEN); std::cout << languaje[3];
}

void Gui::SysInformation(){

    gotoxy(30, 1, BLACK, GREEN);  std::cout << languaje[1];  
    gotoxy(15, 3, BLACK, GREEN);  std::cout << languaje[4];    
    gotoxy(15, 4, BLACK, GREEN);  std::cout << languaje[5];   
    gotoxy(15, 5, BLACK, GREEN);  std::cout << languaje[6];  
    gotoxy(15, 6, BLACK, GREEN);  std::cout << languaje[7];  
    gotoxy(15, 7, BLACK, GREEN);  std::cout << languaje[8];  
    gotoxy(15, 8, BLACK, GREEN);  std::cout << languaje[9];  
    gotoxy(15, 9, BLACK, GREEN);  std::cout << languaje[10]; 
    gotoxy(15, 10, BLACK, GREEN); std::cout << languaje[11]; 
    gotoxy(15, 11, BLACK, GREEN); std::cout << languaje[12];
    gotoxy(45, 3, BLACK, GREEN); std::cout << languaje[13]; 
    gotoxy(45, 4, BLACK, GREEN); std::cout << languaje[14]; 
    gotoxy(45, 5, BLACK, GREEN); std::cout << languaje[15]; 
    gotoxy(45, 6, BLACK, GREEN); std::cout << languaje[16]; 
    //gotoxy(45, 7, BLACK, GREEN); std::cout << languaje[16]; 
    gotoxy(15, 13, BLACK, GREEN); std::cout << languaje[3];
    
    gotoxy(35, 3, BLACK, GREEN);  std::cout << getter.getUserName();
    gotoxy(35, 4, BLACK, GREEN);  std::cout << getter.getPCName();
    gotoxy(35, 5, BLACK, GREEN); std::cout << getter.getSysT();
    gotoxy(35, 6, BLACK, GREEN); std::cout << getter.getLocT();
    gotoxy(35, 7, BLACK, GREEN); std::cout << getter.getCPUIM();
    gotoxy(35, 8, BLACK, GREEN); std::cout << getter.getCPUI();
    gotoxy(35, 9, BLACK, GREEN); std::cout << getter.getCPUNC();
    gotoxy(35, 10, BLACK, GREEN); std::cout << getter.getPhisRAM();
    gotoxy(35, 11, BLACK, GREEN); std::cout << getter.getPorUsedRAM();
    gotoxy(65, 3, BLACK, GREEN); std::cout << getter.getFreePhisRAM();
    gotoxy(65, 4, BLACK, GREEN); std::cout << getter.getIPV4();
    gotoxy(65, 5, BLACK, GREEN); std::cout << getter.getGaWay();
    gotoxy(65, 6, BLACK, GREEN); std::cout << getter.getCPLoad();
    gotoxy(65, 7, BLACK, GREEN); std::cout << getter.getWinver();

}

void Gui::USysInf(){
    getter.Update();
    gotoxy(35, 5, BLACK, GREEN); std::cout << getter.getSysT();
    gotoxy(35, 6, BLACK, GREEN); std::cout << getter.getLocT();
    gotoxy(35, 11, BLACK, GREEN); std::cout << getter.getPorUsedRAM();
    gotoxy(65, 3, BLACK, GREEN); std::cout << getter.getFreePhisRAM();
    gotoxy(65, 6, BLACK, GREEN); std::cout << getter.getCPLoad();
}

void Gui::Cursor(int x, int y, int type){

    if(type == 0) gotoxy(x, y, BLACK, GREEN);
    if(type == 1) gotoxy(x, y, BLACK, BLACK);

}

void Gui::clear(){
    for(int y = 1; y <= 13; y++){
        for(int x = 1; x < 81; x++){
            gotoxy(x, y, BLACK, BLACK); std::cout << " ";
        }
    }
}

Gui::~Gui(){}
