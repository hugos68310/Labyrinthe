#ifndef LABYRINTHE_CASE_H
#define LABYRINTHE_CASE_H

#include <iostream>
#include "Robot.h"
#include "Game.h"

using namespace std;

class cases {
public:
    cases(int top, int left, int typeCase);
    cases(int top, int left, int typeCase, game *game);
    void printCases();
    int getTypeCase() const;
    void setD_top(int d_top);
    void setD_left(int d_left);

private:
    int d_top,d_left;
    game* d_game;
    int d_typeCase; //0=sol 1=mur 2=robot 3=finish

};


#endif //LABYRINTHE_CASE_H
