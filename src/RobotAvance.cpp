#include <RobotAvance.h>
#include <Map.h>
#include <Game.h>

robotAvance::robotAvance(int posX, int posY,map* map) : robot(posX, posY, map) {}

bool robotAvance::wallRight() {
    turnRight();
    if (wallFront()){
        turnLeft();
        game::message("Pas de mur à droite !");
        return true;
    }
    game::message("Mur à droite !");
    turnLeft();
    return false;
}

bool robotAvance::wallLeft() {
    turnLeft();
    if (wallFront()){
        turnRight();
        game::message("Pas de mur à gauche !");
        return true;
    }
    game::message("Mur à gauche !");
    turnRight();
    return false;
}