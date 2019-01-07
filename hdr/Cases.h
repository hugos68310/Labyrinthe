#ifndef LABYRINTHE_CASE_H
#define LABYRINTHE_CASE_H

#include <iostream>

using namespace std;

class cases {
public:
    cases(int top, int left, int typeCase);
    void printCases();
    int getTypeCase() const;
    void setD_top(int d_top);
    void setD_left(int d_left);

private:
    int d_top,d_left;
    int d_typeCase; //0=sol 1=mur 2=robot 3=finish

};


#endif //LABYRINTHE_CASE_H
