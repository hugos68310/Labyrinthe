#include"Launcher.h"
#include"graphics.h"
#include"Game.h"

#define KEY_SPACE   32
#define KEY_R       114
#define KEY_M       109
#define KEY_V       118
#define KEY_ESCAPE  27

int numeroMap = 1;

launcher::launcher():
    d_robotAvance{false},
    d_mapFile{"map1.txt"},
    d_vueTerrain{true}
{

}

void launcher::run() {

    char pressedTouch;
    opengraphsize(1400, 1000);

    messageRobot("Normal");
    messageMap(d_mapFile);
    messageVue("Vue Terrain");

    while(true){

        pressedTouch = (char) getch();

        controles(pressedTouch);

        if(pressedTouch == KEY_ESCAPE)
            break;

    }

    closegraph();

}

void launcher::controles(char pressedTouch){

    switch(pressedTouch) {

        default:
            cout << "touche incorrecte" <<endl;
            break;

        case KEY_R:
            cout << "Changement du robot" << endl;
            d_robotAvance = !d_robotAvance;
            if(!d_robotAvance)
                messageRobot("Normal");
            else
                messageRobot("Avance");
            break;

        case KEY_M:
            cout << "Changement de map" << endl;
            numeroMap += 1;
            if(numeroMap == 4)
                numeroMap = 1;

            d_mapFile = "map" + to_string(numeroMap) + ".txt";

            messageMap(d_mapFile);
            break;

        case KEY_V:
            cout << "changement de vue" << endl;
            d_vueTerrain = !d_vueTerrain;
            if(d_vueTerrain)
                messageVue("Vue Terrain");
            else
                messageVue("Vue Robot");
            break;

        case KEY_ESCAPE:
            cout << "Sortie du launcher" <<endl;
            break;

        case KEY_SPACE:
            closegraph();
            cout << "Valider le choix" << endl;
            game game{d_mapFile, d_robotAvance};
            game.run();
            break;
    }

}

void launcher::messageRobot(string message) {

    setcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    string textRobot, textTouche;

    textRobot = "Mode Robot : ";
    outtextxy(20, 200, textRobot.c_str());

    outtextxy(300, 200, "                      ");
    outtextxy(300, 200, message.c_str());

    textTouche = "Appuyez sur |R| pour changer";
    outtextxy(600, 200, textTouche.c_str());
}

void launcher::messageMap(string message) {

    setcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    string textMap, textTouche;

    textMap = "Carte choisie : ";
    outtextxy(20, 500, textMap.c_str());

    outtextxy(300, 500, "                            ");
    outtextxy(300, 500, message.c_str());

    textTouche = "Appuyez sur |M| pour changer";
    outtextxy(600, 500, textTouche.c_str());
}

void launcher::messageVue(string message) {

    setcolor(WHITE);
    settextstyle(TRIPLEX_FONT, HORIZ_DIR, 3);
    string textMap, textTouche;

    textMap = "Vue choisie : ";
    outtextxy(20, 800, textMap.c_str());

    outtextxy(300, 800, "                            ");
    outtextxy(300, 800, message.c_str());

    textTouche = "Appuyez sur |V| pour changer";
    outtextxy(600, 800, textTouche.c_str());
}