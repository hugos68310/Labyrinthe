#ifndef LABYRINTHE_ROBOTAVANCE_H
#define LABYRINTHE_ROBOTAVANCE_H

#include <robot.h>

class robotAvance : public robot{
public:
    robotAvance(int posX, int posY);
    bool wallRight() const;
    bool wallLeft() const;

};


#endif //LABYRINTHE_ROBOTAVANCE_H
