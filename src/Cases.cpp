#include <graphics.h>
#include <Cases.h>

#include "Cases.h"

cases::cases() {

}

cases::cases(int top, int left, int typeCase):
    d_top{top},
    d_left{left},
    d_typeCase{typeCase}
{}

void cases::printCases() {

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

