#include <graphics.h>
#include <Cases.h>

#include "Cases.h"

cases::cases(int top, int left, int typeCase):
    d_top{top},
    d_left{left},
    d_typeCase{typeCase},
    d_game{0}
{}

cases::cases(int top, int left, int typeCase, game *game):
    d_top{top},
    d_left{left},
    d_typeCase{typeCase},
    d_game{game}
{}

void cases::printCases() {
    int rayonRobot=0,rayonFinish=0,decalageRobot=0,decalageCase=0,decalageDirection=0;
    if (d_game->isD_vueTerrain()){
        decalageCase=38;
        decalageRobot=19;
        rayonFinish=13;
        rayonRobot=8;
        decalageDirection=10;
    } else{
        decalageCase=200;
        decalageRobot=100;
        rayonFinish=75;
        rayonRobot=50;
        decalageDirection=60;
    }
    if (d_typeCase==2){
        setcolor(RED);
        fillellipse(d_left,d_top,rayonRobot,rayonRobot);
        setcolor(BLUE);
        switch (d_game->getD_robot()->getD_direction()){
            case 0:line(d_left,d_top,d_left,d_top-decalageDirection);
                break;
            case 1:line(d_left,d_top,d_left+decalageDirection,d_top);
                break;
            case 2:line(d_left,d_top,d_left,d_top+decalageDirection);
                break;
            case 3:line(d_left,d_top,d_left-decalageDirection,d_top);
                break;
        }
    } else{
        int poly[8];
        poly[0] = d_left;
        poly[1] = d_top;
        poly[2] = d_left+decalageCase;
        poly[3] = d_top;
        poly[4] = d_left+decalageCase;
        poly[5] = d_top+decalageCase;
        poly[6] = d_left;
        poly[7] = d_top+decalageCase;
        if(d_typeCase==3) {
            setcolor(LIGHTGRAY);
            fillpoly(4,poly);
            setcolor(BROWN);
            circle(d_left+decalageRobot,d_top+decalageRobot,rayonFinish);
        } else if (d_typeCase==0){
            setcolor(LIGHTGRAY);
            fillpoly(4,poly);
        } else{
            setcolor(LIGHTGREEN);
            fillpoly(4,poly);
        }
    }
}


void cases::setD_top(int d_top) {
    cases::d_top = d_top;
}

void cases::setD_left(int d_left) {
    cases::d_left = d_left;
}

