#ifndef Reader_hpp
#define Reader_hpp

#include <sstream>
#include <fstream>
#include <string>
#include <vector>

class Reader{
private:
    
public:
    Reader();

    int activeLan();
    std::vector<std::string> setlanguaje(int opt, int act);
    void changeMLang(int lang);

    ~Reader();
};

#endif