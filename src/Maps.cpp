#include <fstream>
#include <iostream>
#include <Maps.h>
#include <Game.h>

#include "Maps.h"

using namespace std;

maps::maps(string mapFile,game* game) :
    d_binaryMap{}
{
    d_game = game;
    initBinaryMap(); //initialisation du tableau 2D "maps" 16*16 du terrain qui representera la carte
    readFile(mapFile);//Ouverture d'un fichier txt qui contiendra la carte du jeu en valeurs INT
    printBinaryMap();
    initMap();
    refreshRobot(d_posXRobot,d_posYRobot);
}

void maps::initBinaryMap() {
    d_binaryMap = new int*[16];
    for(int i = 0; i < 16; ++i)
        d_binaryMap[i] = new int[16];
}

void maps::readFile(string mapFile) {
    fstream myFile("../mapFiles/"+mapFile);
    if(!myFile) //Si le fichier ne s'est pas ouvert
        game::messageBox("Erreur : impossible d'ouvrir la carte");
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

void maps::initMap() {

    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            switch (d_binaryMap[i][j]){
                case 0: d_map.push_back(cases{200+i*38,400+j*38,0});
                    break;
                case 1: d_map.push_back(cases{200+i*38,400+j*38,1});
                    break;
                case 2: d_map.push_back(cases{200+i*38,400+j*38,0});
                    break;
                case 3: d_map.push_back(cases{200+i*38,400+j*38,3});
                    break;
            }
        }
    }
    d_map.push_back(cases{0,0,2,d_game});
}

void maps::refreshRobot(int posX, int posY) {
    d_map.back().setD_left(posX*38+419);
    d_map.back().setD_top(posY*38+219);
}

void maps::printBinaryMap() { //affiche le terrain sous forme du fichier .txt

    for (int k = 0; k < 16; ++k) {
        for (int i = 0; i < 16; ++i) {
            cout << " " << d_binaryMap[k][i];
        }
        cout << endl;
    }

}

void maps::setXYRobot(int posX,int posY){
    d_posXRobot=posX;
    d_posYRobot=posY;
}

void maps::setXYFin(int posX, int posY) {
    d_posXFin=posX;
    d_posYFin=posY;
}

int maps::getD_posXFin() const {
    return d_posXFin;
}

int maps::getD_posYFin() const {
    return d_posYFin;
}

int maps::getD_posXRobot() const {
    return d_posXRobot;
}

int maps::getD_posYRobot() const {
    return d_posYRobot;
}

int ** maps::getD_binaryMap() const {
    return d_binaryMap;
}

const vector<cases> maps::getD_map() const {
    return d_map;
}
