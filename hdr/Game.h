#ifndef LABYRINTHE_GAME_H
#define LABYRINTHE_GAME_H

#include "Robot.h"
#include "Maps.h"
#include <string>

using namespace std;

class game {
public:
    game(string mapFile, bool robotAvanceBool = false, bool vueTerrain = true);
    void run();
    void printMap();
    bool isFinish() const;
    static void messageBox(string message);
    void controles(char pressedTouch);
    void openWindow();
    void closeWindow();
    void mainDroite();
    void pledge();
    robot *getD_robot() const;
    bool isD_robotAvance() const;

private:
    maps* d_map;
    robot* d_robot;
    bool d_robotAvance, d_vueTerrain;
    // Si d_vue Terrain=false alors on a une vue Robot
};


#endif //LABYRINTHE_GAME_H
