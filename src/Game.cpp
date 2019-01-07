#include "Game.h"
#include "Map.h"

game::game(bool robotAvance, bool vueTerrain):
    d_map{},
    d_robot{d_map.getD_posXRobot(),d_map.getD_posYRobot()}
{}

