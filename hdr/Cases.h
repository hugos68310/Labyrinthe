#ifndef LABYRINTHE_CASE_H
#define LABYRINTHE_CASE_H

#include <iostream>

using namespace std;

class cases {
public:
    cases(int top, int left, int typeCase, string pathImage);
    bool isClick() const;
    void printCases();
private:
    int d_top,d_left;
    int d_typeCase; //0=sol 1=mur 2=robot 3=finish



};


#endif //LABYRINTHE_CASE_H
