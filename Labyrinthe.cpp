#include <iostream>
#include "hdr/Map.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "hdr/Game.h"

#define KEY_ESCAPE  27

int main() {

    game game{"map.txt"};

    char pressedTouch;

    int poly[8];

    poly[0] = 20;
    poly[1] = 20;
    poly[2] = 20;
    poly[3] = 40;
    poly[4] = 40;
    poly[5] = 40;
    poly[6] = 40;
    poly[7] = 20;

    game.openWindow();

    setcolor(16777215);
    fillpoly(4, poly);

    do{

        pressedTouch = (char) getch();

        game.controles(pressedTouch);

    }while (pressedTouch != KEY_ESCAPE);

    game.closeWindow();

    return 0;
    //TODO Faire une fonction de message fenetre;
}