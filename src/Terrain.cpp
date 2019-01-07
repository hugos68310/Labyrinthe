#include <fstream>
#include <iostream>
#include "Terrain.h"

using namespace std;

Terrain::Terrain():
    d_map{}
{
    init(); //initialisation du tableau 2D "map" 16*16 du terrain qui representera la carte
    readFile();//Ouverture d'un fichier txt qui contiendra la carte du jeu en valeurs INT
}

void Terrain::init() {
    d_map = new int*[16];
    for(int i = 0; i < 16; ++i)
        d_map[i] = new int[16];
}

void Terrain::readFile(){

    fstream myFile("../prodFiles/map.txt");

    if(!myFile) //Si le fichier ne s'est pas ouvert
        cout << "Erreur : impossible d'ouvrir la carte" << endl;

    else{

        int value;
        for (int i = 0; i < 16; ++i) { //On ajoute au tableau 2D les valeurs collectées
            for (int j = 0; j < 16; ++j) {
                myFile >> value;
                d_map[i][j] = value;
            }
        }

        afficheTerrainBinaire();

    }

}

void Terrain::afficheTerrainBinaire() { //affiche le terrain sous forme du fichier .txt

    for (int k = 0; k < 16; ++k) {
        for (int i = 0; i < 16; ++i) {
            cout << " " << d_map[k][i];
        }
        cout << endl;
    }

}

int **Terrain::getMap() const {
    return d_map;
}
