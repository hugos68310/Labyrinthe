#ifndef LABYRINTHE_TERRAIN_H
#define LABYRINTHE_TERRAIN_H

#include <vector>
#include <string>
#include "Cases.h"

using namespace std;

class map {
public:
    map(string mapFile);
    void setXYRobot(int posX,int posY);
    void setXYFin(int posX,int posY);
    int getD_posXFin() const;
    int getD_posYFin() const;
    int getD_posXRobot() const;
    int getD_posYRobot() const;
    int ** getD_binaryMap() const;
    void refreshRobot(int posX,int posY);
    const vector<cases> &getD_map() const;

private:
    int** d_binaryMap;
    vector<cases> d_map;
    void initBinaryMap();
    void initMap();
    void readFile(string mapFile);
    void printBinaryMap();
    int d_posXFin,d_posYFin,d_posXRobot,d_posYRobot;
};


#endif //LABYRINTHE_TERRAIN_H
