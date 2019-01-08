#ifndef LABYRINTHE_LAUNCHER_H
#define LABYRINTHE_LAUNCHER_H

#include <iostream>

using namespace std;

class launcher{
public:
    launcher();
    void run();
    void controles(char pressedTouch);
    void messageRobot(string message);
    void messageMap(string message);
    void messageVue(string message);

private:
    string d_mapFile;
    bool d_robotAvance;
    bool d_vue;
};

#endif //LABYRINTHE_LAUNCHER_H
