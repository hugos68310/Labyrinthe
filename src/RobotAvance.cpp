#include <RobotAvance.h>
#include <Maps.h>
#include <Game.h>

robotAvance::robotAvance(int posX, int posY,maps* map) : robot(posX, posY, map) {}

bool robotAvance::wallRight() {
    turnRight();
    if (wallFront()){
        turnLeft();
        game::messageBox("Pas de mur a droite !");
        return true;
    }
    game::messageBox("Mur a droite !");
    turnLeft();
    return false;
}

bool robotAvance::wallLeft() {
    turnLeft();
    if (wallFront()){
        turnRight();
        game::messageBox("Pas de mur a gauche !");
        return true;
    }
    game::messageBox("Mur a gauche !");
    turnRight();
    return false;
}