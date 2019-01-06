#include <robot.h>

robot::robot(int posX, int posY):
    d_posX{posX},
    d_posY{posY},
    d_direction{0}
{}

bool robot::wallFront() const {
    //TODO faire la fonction une fois le terrain crée
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
    };
    //TODO message Contact avec mur echecs du Move
}

