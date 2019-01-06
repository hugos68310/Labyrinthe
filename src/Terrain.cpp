#include <fstream>
#include <iostream>
#include "Terrain.h"

using namespace std;

Terrain::Terrain():
    map{}
{
    //création du tableau 2D 16*16 du terrain qui representera la carte
    map = new int*[16];
    for(int i = 0; i < 16; ++i)
        map[i] = new int[16];

    //Ouverture d'un fichier txt qui contiendra la carte du jeu en valeurs INT
    fstream myFile("../prodFiles/map.txt");

    if(!myFile) //Si le fichier ne s'est pas ouvert
        cout << "Erreur : impossible d'ouvrir la carte" << endl;

    else{
        int value;
        vector<int> tempTab; //création d'un vecteur temporaire pour stocker les données
        while(myFile >> value){ //tant qu'on a une valeur
            tempTab.push_back(value);
        }

        int index = 0; //index du vecteur temporaire
        for (int i = 0; i < 16; ++i) { //On ajoute au tableau 2D les valeurs collectées
            for (int j = 0; j < 16; ++j) {
                map[i][j] = tempTab[index];
                index++;
            }
        }

        for (int k = 0; k < 16; ++k) {
            for (int i = 0; i < 16; ++i) {
                cout << " " << map[k][i];
            }
            cout << endl;
        }
    }



}