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
#define KEY_M       109
#define KEY_P       112
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

    afficheCommandes();

    while(pressedTouch != KEY_ESCAPE) {

        printMap();

        if (isFinish()) {
            messageBox("Felicitations vous avez trouve la sortie !");
            pressedTouch = (char) getch();
        }else {
            pressedTouch = (char) getch();
            controles(pressedTouch);
        }
    }
}

void game::mainDroite() {
    while(!isFinish()){
        d_robot->turnRight();
        printMap();
        delay(100);
        while (d_robot->wallFront()){
            d_robot->turnLeft();
            printMap();
            delay(100);
        }
        d_robot->move();
        d_map->refreshRobot(d_robot->getD_posX(), d_robot->getD_posY());
        printMap();
        delay(100);
    }
}

void game::pledge() {
    while(!isFinish()){
        while (!d_robot->wallFront() && !isFinish()){
            d_robot->move();
            d_map->refreshRobot(d_robot->getD_posX(), d_robot->getD_posY());
            printMap();
            delay(100);
        }
        if (!isFinish()) {


            int temp = 0;
            d_robot->turnLeft();
            printMap();
            delay(100);
            d_robot->move();
            d_map->refreshRobot(d_robot->getD_posX(), d_robot->getD_posY());
            printMap();
            delay(100);
            temp++;
            while (temp != 0 && !isFinish()) {
                d_robot->turnRight();
                temp--;
                printMap();
                delay(100);
                while (d_robot->wallFront()) {
                    d_robot->turnLeft();
                    temp++;
                    printMap();
                    delay(100);
                }
                d_robot->move();
                d_map->refreshRobot(d_robot->getD_posX(), d_robot->getD_posY());
                printMap();
                delay(100);
            }
        }
    }
}

bool game::isFinish() const {
    return d_robot->getD_posX() == d_map->getD_posXFin() &&
    d_robot->getD_posY()==d_map->getD_posYFin();
}

void game::messageBox(string message) {
    outtextxy(515, 870, "                                                                                                                                                              ");
    char text[message.size()];
    for(int i = 0; i <= message.size(); i++)
        text[i] = message[i];
    setcolor(LIGHTBLUE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    outtextxy(515, 870, text);
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
        case KEY_M:
            cout << "Mode Main Droite activé" << endl;
            mainDroite();
            break;
        case KEY_P:
            cout << "Mode Pledge activé" << endl;
            pledge();
            break;
        default:
            cout << "commande inconnue" << endl;
            break;
    }

    d_map->refreshRobot(d_robot->getD_posX(), d_robot->getD_posY());

}

void game::afficheCommandes(){

    setcolor(LIGHTBLUE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 2);
    string test;

    test = "|Z| Avancer";
    outtextxy(20, 200, test.c_str());

    test = "|Q| Tourner à gauche";
    outtextxy(20, 250, test.c_str());

    test = "|D| Tourner à droite";
    outtextxy(20, 300, test.c_str());

    test = "|A| Regarder à gauche";
    outtextxy(20, 350, test.c_str());

    test = "|E| Regarder à droite";
    outtextxy(20, 400, test.c_str());

    test = "|M| Mode main droite";
    outtextxy(20, 450, test.c_str());

    test = "|P| Mode Pledge";
    outtextxy(20, 500, test.c_str());
}

void game::openWindow() {
    opengraphsize(1400, 1000);
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
