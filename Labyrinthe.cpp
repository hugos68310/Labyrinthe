#include <iostream>
#include "hdr/Map.h"
#include <iostream>
#include <graphics.h>

#define KEY_ESCAPE  27
#define KEY_Z       122
#define KEY_A       97
#define KEY_RIGHT   77
#define KEY_LEFT    75
#define KEY_UP      72


int main() {
    std::cout << "Hello, World!" << std::endl;
    map map{};

    char c;

    opengraphsize(1920, 1080);

    do{

        c = (char) getch();

        if(c != 0){

            switch(c){
                case KEY_ESCAPE:
                    cout << "Sortie du jeu" << endl;
                    break;

                case KEY_Z:
                    cout << "regarde si il y a un mur à droite" << endl;
                    break;

                case KEY_A:
                    cout << "regarde s'il ya un mur à gauche" << endl;
                    break;

                default:
                    cout << "commande inconnue" << endl;
                    break;
            }

        }

        else{ //Si on utilise des fleches, le code ASCII retourné en premier est égal à 0, il faut donc refaire un getch pour avoir le code d'une fleche

            c = (char) getch();

            switch (c) {

                case KEY_RIGHT:
                    cout << "tourne à droite" << endl;
                    break;

                case KEY_LEFT:
                    cout << "tourne à gauche" << endl;
                    break;

                case KEY_UP:
                    cout << "Avance" << endl;
                    break;

                default:
                    cout << "commande inconnue" << endl;
                    break;
            }
        }



    }
    while (c != KEY_ESCAPE);

    closegraph();

    return 0;
    //TODO Faire une fonction de message fenetre;
}