#ifndef LABYRINTHE_CASE_H
#define LABYRINTHE_CASE_H


class cases {
public:
    cases();
    bool isClick() const;
    void printCases();
private:
    int d_top,d_left;
    int typeCase; //0=sol 1=mur 2=robot 3=finish



};


#endif //LABYRINTHE_CASE_H
