#ifndef LABYRINTHE_ROBOTAVANCE_H
#define LABYRINTHE_ROBOTAVANCE_H

#include <Robot.h>
#include "Map.h"


class robotAvance : public robot{
public:
    robotAvance(int posX, int posY,map map);
    bool wallRight() ;
    bool wallLeft() ;

};


#endif //LABYRINTHE_ROBOTAVANCE_H
