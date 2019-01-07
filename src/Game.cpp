#include <RobotAvance.h>
#include <Game.h>
#include <iostream>

#include "Game.h"
#include "Map.h"

game::game(string mapFile, bool robotAvanceBool, bool vueTerrain) :
        d_robotAvance{robotAvanceBool},
        d_vueTerrain{vueTerrain}
        {
            d_map = new map(mapFile);
            if (d_robotAvance){
                d_robot = new robotAvance{d_map->getD_posXRobot(),d_map->getD_posYRobot(),d_map};
            } else d_robot = new robot{d_map->getD_posXRobot(),d_map->getD_posYRobot(),d_map};
        }

bool game::isFinish() const {
    return d_robot->getD_posX() == d_map->getD_posXFin() &&
    d_robot->getD_posY()==d_map->getD_posYFin();
}

void game::message(string message) {
    cout<<message<<endl;
}

