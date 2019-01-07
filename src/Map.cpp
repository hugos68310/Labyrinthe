#include <fstream>
#include <iostream>
#include <Map.h>
#include <Game.h>

#include "Map.h"

using namespace std;

map::map(string mapFile) :
    d_binaryMap{}
{
    initBinaryMap(); //initialisation du tableau 2D "map" 16*16 du terrain qui representera la carte
    readFile(mapFile);//Ouverture d'un fichier txt qui contiendra la carte du jeu en valeurs INT
    printBinaryMap();
}

void map::initBinaryMap() {
    d_binaryMap = new int*[16];
    for(int i = 0; i < 16; ++i)
        d_binaryMap[i] = new int[16];
}

void map::readFile(string mapFile) {
    fstream myFile("../mapFiles/"+mapFile);
    if(!myFile) //Si le fichier ne s'est pas ouvert
        game::message("Erreur : impossible d'ouvrir la carte");
    else{
        int value;
        for (int i = 0; i < 16; ++i) { //On ajoute au tableau 2D les valeurs collectées
            for (int j = 0; j < 16; ++j) {
                myFile >> value;
                if(value==2){
                    setXYRobot(j,i);
                }
                if(value==3){
                    setXYFin(j,i);
                }
                d_binaryMap[i][j] = value;
            }
        }
    }
}

void map::printBinaryMap() { //affiche le terrain sous forme du fichier .txt

    for (int k = 0; k < 16; ++k) {
        for (int i = 0; i < 16; ++i) {
            cout << " " << d_binaryMap[k][i];
        }
        cout << endl;
    }

}

void map::setXYRobot(int posX,int posY){
    d_posXRobot=posX;
    d_posYRobot=posY;
}

void map::setXYFin(int posX, int posY) {
    d_posXFin=posX;
    d_posYFin=posY;
}

int map::getD_posXFin() const {
    return d_posXFin;
}

int map::getD_posYFin() const {
    return d_posYFin;
}

int map::getD_posXRobot() const {
    return d_posXRobot;
}

int map::getD_posYRobot() const {
    return d_posYRobot;
}

int **map::getD_map() const {
    return d_binaryMap;
}
