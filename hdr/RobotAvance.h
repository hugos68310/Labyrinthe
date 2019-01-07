#ifndef LABYRINTHE_ROBOTAVANCE_H
#define LABYRINTHE_ROBOTAVANCE_H

#include <Robot.h>
#include "Maps.h"


class robotAvance : public robot{
public:
    robotAvance(int posX, int posY,maps* map);
    bool wallRight() override;
    bool wallLeft() override;

};


#endif //LABYRINTHE_ROBOTAVANCE_H
