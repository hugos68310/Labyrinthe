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
    if (d_typeCase==2){
        setcolor(RED);
        fillellipse(d_left,d_top,8,8);
        if (d_game->isD_robotAvance()){
            setcolor(BLUE);
        } else setcolor(RED);
        switch (d_game->getD_robot()->getD_direction()){
            case 0:line(d_left,d_top,d_left,d_top-10);
            case 1:line(d_left,d_top,d_left,d_top+10);
            case 2:line(d_left,d_top,d_left+10,d_top);
            case 3:line(d_left,d_top,d_left,d_top-10);
        }
    } else{
        int poly[8];
        poly[0] = d_left;
        poly[1] = d_top;
        poly[2] = d_left+38;
        poly[3] = d_top;
        poly[4] = d_left+38;
        poly[5] = d_top+38;
        poly[6] = d_left;
        poly[7] = d_top+38;
        if(d_typeCase==3) {
            setcolor(BROWN);
            fillpoly(4,poly);
            setcolor(YELLOW);
            circle(d_left+19,d_top+19,13);
        } else if (d_typeCase==0){
            setcolor(BROWN);
            fillpoly(4,poly);
        } else{
            setcolor(GREEN);
            fillpoly(4,poly);
        }
    }
}


int cases::getTypeCase() const {
    return d_typeCase;
}

void cases::setD_top(int d_top) {
    cases::d_top = d_top;
}

void cases::setD_left(int d_left) {
    cases::d_left = d_left;
}

