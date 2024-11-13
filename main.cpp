#include "Structure/System/System.hpp"

int main(){

    std::setlocale(LC_CTYPE, ".UTF-8");
    SetConsoleOutputCP(CP_UTF8);
    SetConsoleCP(CP_UTF8);
    
    System sistem("SySInfo");

    sistem.MenuSyst();

    return EXIT_SUCCESS;
}

