#ifndef DISK_H
#define DISK_H

#include "../userinterface.h"

class Disk {
private:
    bool isWhite;
    int x, y;

public:
    Disk(bool isWhite);
    void turn(UserInterface *UserInt);
    bool getIsWhite(){ return isWhite; }
    void setY(int x , int y, UserInterface *UserInt);
    virtual ~Disk() {

    }
};



#endif // DISK_H
