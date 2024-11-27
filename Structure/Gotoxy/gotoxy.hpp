#ifndef GOTOXY_HPP
#define GOTOXY_HPP
enum Colors { BLACK = 0, BLUE = 1, GREEN = 2, CYAN = 3, RED = 4, MAGENTA = 5, BROWN = 6, LGREY = 7, DGREY = 8, LBLUE = 9, LGREEN = 10, LCYAN = 11, LRED = 12, LMAGENTA = 13, YELLOW = 14, WHITE = 15};
#include <windows.h>

void gotoxy(int x, int y, int backC, int ForGC);



#endif