#include <RobotAvance.h>
#include <Game.h>
#include <iostream>

#include "Game.h"
#include "Maps.h"
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
        d_vueTerrain{vueTerrain},
        d_map{},
        d_robot{}
        {
            d_map = new maps(mapFile,this);
            if (d_robotAvance){

                d_robot = new robotAvance{d_map->getD_posXRobot(),d_map->getD_posYRobot(),d_map};
            } else d_robot = new robot{d_map->getD_posXRobot(),d_map->getD_posYRobot(),d_map};
        }

void game::run() {
    char pressedTouch;
    openWindow();

    while(!isFinish()){
        printMap();
        pressedTouch = (char) getch();
        controles(pressedTouch);
    }
}

bool game::isFinish() const {
    return d_robot->getD_posX() == d_map->getD_posXFin() &&
    d_robot->getD_posY()==d_map->getD_posYFin();
}

void game::messageBox(string message) {
    char text[message.size()];
    for(int i = 0; i < message.size(); i++)
        text[i] = message[i];
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(20, 20, text);
}

void game::controles(char pressedTouch) {

    switch(pressedTouch){

        case KEY_ESCAPE:
            cout << "Sortie du jeu" << endl;
            closeWindow();
            break;

        case KEY_Z:
            cout << "Regarde s'il y a un mur devant" << endl;
            d_robot->wallFront();
            break;

        case KEY_Q:
            cout << "Tourne à gauche" << endl;
            d_robot->turnLeft();
            break;

        case KEY_S:
            cout << "Avancer" << endl;
            d_robot->move();
            break;

        case KEY_D:
            cout << "Tourne à droite" << endl;
            d_robot->turnRight();
            break;

        case KEY_E:
            cout << "Regarde s'il y a un mur à droite" << endl;
            if(d_robotAvance)
                d_robot->wallRight();
            break;

        case KEY_A:
            cout << "regarde s'il ya un mur à gauche" << endl;
            if(d_robotAvance)
                d_robot->wallLeft();
            break;

        default:
            cout << "commande inconnue" << endl;
            break;
    }

    d_map->refreshRobot(d_robot->getD_posX(), d_robot->getD_posY());

}

void game::openWindow() {
    opengraphsize(1000, 1000);
}

void game::closeWindow() {
    closegraph();
}

void game::printMap() {
    for(cases cases : d_map->getD_map())
        cases.printCases();
}

robot *game::getD_robot() const {
    return d_robot;
}

bool game::isD_robotAvance() const {
    return d_robotAvance;
}
