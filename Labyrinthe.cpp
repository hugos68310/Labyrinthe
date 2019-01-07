#include <iostream>
#include "Maps.h"
#include <iostream>
#include <graphics.h>
#include <conio.h>
#include "hdr/Game.h"

#define KEY_ESCAPE  27

int main() {

    game game{"map1.txt", true};

    game.run();

    return 0;
}