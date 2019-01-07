#include <Robot.h>
#include <Map.h>

robot::robot(int posX, int posY, map map):
    d_posX{posX},
    d_posY{posY},
    d_map{},
    d_direction{0}
{d_map=&map;}

bool robot::wallFront() const {
    switch (d_direction) {
        case 0: if(d_map->getD_map()[d_posY-1][d_posX]==1) return true;
            break;
        case 1: if(d_map->getD_map()[d_posY][d_posX+1]==1) return true;
            break;
        case 2: if(d_map->getD_map()[d_posY+1][d_posX]==1) return true;
            break;
        case 3: if(d_map->getD_map()[d_posY][d_posX-1]==1) return true;
            break;
    }
    return false;
}

void robot::turnLeft() {
    d_direction = (d_direction+1)%4;
}

void robot::turnRight() {
    d_direction = (d_direction+3)%4;
}

void robot::move() {
    if (!wallFront()) {
        switch (d_direction) {
            case 0: d_posY++;
                break;
            case 1: d_posX++;
                break;
            case 2: d_posY--;
                break;
            case 3: d_posX--;
                break;
        }
    }
}

int robot::getD_posX() const {
    return d_posX;
}

int robot::getD_posY() const {
    return d_posY;
}

