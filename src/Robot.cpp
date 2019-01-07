#include <Robot.h>
#include <Maps.h>
#include <Game.h>

robot::robot(int posX, int posY, maps* map):
    d_posX{posX},
    d_posY{posY},
    d_map{},
    d_direction{0}
{d_map=map;}

bool robot::wallFront(bool move) const {
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
    if (!move) {
        game::messageBox("Il n'y a pas de mur en face !");
        return false;
    }
}

void robot::turnLeft() {
    d_direction = (d_direction+3)%4;
}

void robot::turnRight() {
    d_direction = (d_direction+1)%4;
}

bool robot::move() {
    if (!wallFront(true)) {
        switch (d_direction) {
            case 0: d_posY--;
                break;
            case 1: d_posX++;
                break;
            case 2: d_posY++;
                break;
            case 3: d_posX--;
                break;
        }
        game::messageBox(" ");
        return true;
    }
    return false;
}

int robot::getD_posX() const {
    return d_posX;
}

int robot::getD_posY() const {
    return d_posY;
}

bool robot::wallRight() {
    game::messageBox("Vous n'avez pas cette capacite !");
    return false;
}

bool robot::wallLeft() {
    game::messageBox("Vous n'avez pas cette capacite !");
    return false;
}

int robot::getD_direction() const {
    return d_direction;
}

