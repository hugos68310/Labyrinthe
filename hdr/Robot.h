#ifndef LABYRINTHE_ROBOT_H
#define LABYRINTHE_ROBOT_H

#include <vector>
#include "Map.h"

class robot{
public:
    robot(int posX, int posY, map* map );
    bool wallFront() const;
    void move() ;
    void turnLeft() ;
    void turnRight() ;
    int getD_posX() const;
    int getD_posY() const;
    virtual bool wallRight() ;
    virtual bool wallLeft() ;

private:
    int d_posX,d_posY;
    map* d_map;
    //Pour la direction 0=Nord 1=Est 2=Sud 3=Ouest
    int d_direction;
};

#endif //LABYRINTHE_ROBOT_H
