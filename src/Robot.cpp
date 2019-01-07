#include <Robot.h>
#include <Map.h>
#include <Game.h>

robot::robot(int posX, int posY, map* map):
    d_posX{posX},
    d_posY{posY},
    d_map{},
    d_direction{0}
{d_map=map;}

bool robot::wallFront() const {
    bool mur = false;
    switch (d_direction) {
        case 0: if(d_map->getD_binaryMap()[d_posY-1][d_posX]==1) mur = true;
            break;
        case 1: if(d_map->getD_binaryMap()[d_posY][d_posX+1]==1) mur = true;
            break;
        case 2: if(d_map->getD_binaryMap()[d_posY+1][d_posX]==1) mur = true;
            break;
        case 3: if(d_map->getD_binaryMap()[d_posY][d_posX-1]==1) mur = true;
            break;
    }
    if (mur){
        game::messageBox("Il y a un mur en face !");
        return true;
    }
    game::messageBox("Il n'y a pas de mur en face !");
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
    } else game::messageBox("Il y a un mur devant !");
}

int robot::getD_posX() const {
    return d_posX;
}

int robot::getD_posY() const {
    return d_posY;
}

bool robot::wallRight() {
    game::messageBox("Vous n'avez pas le droit d'utiliser cette fonction ici !");
    return false;
}

bool robot::wallLeft() {
    return wallRight();
}

