
#include <Game.h>

#include "Game.h"
#include "Map.h"

game::game(bool robotAvance, bool vueTerrain):
    d_map{},
    d_robot{d_map.getD_posXRobot(),d_map.getD_posYRobot(),d_map}
{}

bool game::isFinish() const {
    return d_robot.getD_posX() == d_map.getD_posXFin() &&
    d_robot.getD_posY()==d_map.getD_posYFin();
}

