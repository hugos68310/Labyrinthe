#include <RobotAvance.h>
#include <Game.h>
#include <iostream>

#include "Game.h"
#include "Map.h"
#include "graphics.h"

#define KEY_Z       122
#define KEY_A       97
#define KEY_Q       113
#define KEY_D       100
#define KEY_E       101
#define KEY_S       115
#define KEY_ESCAPE  27

game::game(string mapFile, bool robotAvanceBool, bool vueTerrain) :
        d_robotAvance{robotAvanceBool},
        d_vueTerrain{vueTerrain}
        {
            d_map = new map(mapFile);
            if (d_robotAvance){
                d_robot = new robotAvance{d_map->getD_posXRobot(),d_map->getD_posYRobot(),d_map};
            } else d_robot = new robot{d_map->getD_posXRobot(),d_map->getD_posYRobot(),d_map};
        }

bool game::isFinish() const {
    return d_robot->getD_posX() == d_map->getD_posXFin() &&
    d_robot->getD_posY()==d_map->getD_posYFin();
}

void game::message(string message) {
    cout<<message<<endl;
}

void game::controles(char pressedTouch) {

    switch(pressedTouch){

        case KEY_ESCAPE:
            cout << "Sortie du jeu" << endl;
            break;

        case KEY_Z:
            cout << "Regarde s'il y a un mur devant" << endl;
            break;

        case KEY_Q:
            cout << "Tourne à gauche" << endl;
            break;

        case KEY_S:
            cout << "Avancer" << endl;
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

}

void game::openWindow() {
    opengraphsize(1000, 1000);
}

void game::closeWindow() {
    closegraph();
}
