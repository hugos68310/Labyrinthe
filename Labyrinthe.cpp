#include <iostream>
#include "hdr/Map.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>

#define KEY_ESCAPE  27
#define KEY_Z       122
#define KEY_A       97
#define KEY_Q       113
#define KEY_D       100
#define KEY_E       101
#define KEY_S       115


int main() {

    map map{"map.txt"};

    char c;

    int poly[8];

    poly[0] = 20;
    poly[1] = 20;
    poly[2] = 20;
    poly[3] = 40;
    poly[4] = 40;
    poly[5] = 40;
    poly[6] = 40;
    poly[7] = 20;


    opengraphsize(1920, 1080);

    setcolor(16777215);
    fillpoly(4, poly);

    do{

        c = (char) getch();

            switch(c){

                case KEY_ESCAPE:
                    cout << "Sortie du jeu" << endl;
                    break;

                case KEY_Z:
                    cout << "Avance" << endl;
                    break;

                case KEY_Q:
                    cout << "Tourne à gauche" << endl;
                    break;

                case KEY_S:
                    cout << "Touche S" << endl;
                    break;

                case KEY_D:
                    cout << "Tourne à droite" << endl;
                    break;

                case KEY_E:
                    cout << "Regarde s'il y a un mur à droite" << endl;
                    break;

                case KEY_A:
                    cout << "regarde s'il ya un mur à gauche" << endl;
                    break;

                default:
                    cout << "commande inconnue" << endl;
                    break;
            }

    }while (c != KEY_ESCAPE);

    closegraph();

    return 0;
    //TODO Faire une fonction de message fenetre;
}