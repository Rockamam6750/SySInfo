#include "Reader.hpp"
#include <locale>
#include <iostream>
#include <codecvt>

#define Es "data/languajes/es_cr.txt"
#define En "data/languajes/en_us.txt"
#define Nh "data/languajes/nh_jap.txt"

Reader::Reader(){}

int Reader::activeLan(){

    std::fstream file("data/conf/conf.conf", std::ios::in);

    if(!file.is_open()){
        std::cerr << "Error ocurrent file cant open";
        return EXIT_FAILURE;
    }

    char simb = ' ';

    file.get(simb);

    int ret = simb - '0';

    file.close();

    return ret;
}

std::vector<std::string> Reader::setlanguaje(int opt, int act){
    std::string dir = " ";
    
    std::vector<std::string> temp;

    if(opt != act){
        changeMLang(opt);
    }

    if(opt == 0){
        dir = Es;
    }else if(opt == 1){
        dir = En;
    }else if(opt == 2){
        dir = Nh;
    }

    std::ifstream file(dir, std::ios::in);

    if(!file.is_open()){
        std::cerr << "Error the system cant read the dictionary";
    }

    std::string linea;

    while(getline(file, linea)){
        temp.push_back(linea);
    }

    file.close();

    return temp;
}

void Reader::changeMLang(int lang){

    std::fstream file("data/conf/conf.conf", std::ios::out);

    char option = lang + '0';

    if(file.is_open()){
        file << option;
    }

    file.close();

}

Reader::~Reader(){}
