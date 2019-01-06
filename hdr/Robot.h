#ifndef LABYRINTHE_ROBOT_H
#define LABYRINTHE_ROBOT_H

#include <vector>

class robot{
public:
    robot(int posX, int posY);
    bool wallFront() const;
    void move() ;
    void turnLeft() ;
    void turnRight() ;

private:
    int d_posX,d_posY;
    //Pour la direction 0=Nord 1=Est 2=Sud 3=Ouest
    int d_direction;
};

#endif //LABYRINTHE_ROBOT_H
