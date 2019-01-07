#include <RobotAvance.h>
#include <Map.h>

robotAvance::robotAvance(int posX, int posY,map map) : robot(posX, posY, map) {}

bool robotAvance::wallRight() {
    turnRight();
    if (wallFront()){
        turnLeft();
        return true;
    }
    turnLeft();
    return false;
}

bool robotAvance::wallLeft() {
    turnLeft();
    if (wallFront()){
        turnRight();
        return true;
    }
    turnRight();
    return false;
}
