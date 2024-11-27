#ifndef Control_hpp
#define Control_hpp

#include <conio.h>

class Control{
private:
    int x_pos;
    int y_pos, y_Cpos;

    int optnum;
    int currentopt;
    
public:
    Control();
    void InitControl(int x, int y, int opt);
    void ControlUnit(int *p);
    ~Control();

};

#endif //Control_pp