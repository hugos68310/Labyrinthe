#ifndef LABYRINTHE_TERRAIN_H
#define LABYRINTHE_TERRAIN_H

#include <vector>

using namespace std;

class Terrain {
public:
    Terrain();

private:
    int** map; //preparation d'un tableau 2D qui sera créer dans le constructeur
    void init();
    void readFile();
    void afficheTerrainBinaire();
};


#endif //LABYRINTHE_TERRAIN_H
