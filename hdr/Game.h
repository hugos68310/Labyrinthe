#ifndef LABYRINTHE_GAME_H
#define LABYRINTHE_GAME_H

#include "Robot.h"
#include "Map.h"
#include <string>

using namespace std;

class game {
public:
    game(bool robotAvance=false,bool vueTerrain=true);
    void vueGame();
    void mainDroite();
    void pledge();
private:
    bool d_robotAvance, d_vueTerrain; // Si d_vueTerrain=false alors on a une vue Robot
    map d_map;
    robot d_robot;
};


#endif //LABYRINTHE_GAME_H
