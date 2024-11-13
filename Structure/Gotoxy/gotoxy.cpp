#include "gotoxy.hpp"

void gotoxy(int x, int y, int backC, int ForGC){
    HANDLE hCon;
    hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD cord;
    cord.X = x;
    cord.Y = y;
    SetConsoleCursorPosition(hCon, cord);

    int New_Color= ForGC + (backC * 16);
    SetConsoleTextAttribute(hCon, New_Color);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 100;
    cci.bVisible = FALSE;
    
    SetConsoleCursorInfo(hCon, &cci);
}

