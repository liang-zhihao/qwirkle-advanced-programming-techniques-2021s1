//
// Created by 34773 on 1/29/2022.
//

#include "Position.h"

Position::Position(string desc) {
    this->desc = desc;
}

int Position::getColumn() {
    string tmpStr = desc;
    tmpStr.erase(0, 1);
    return atoi(tmpStr.c_str());
}

int Position::getRow() {
    return desc[0] - ASCII_A;
}

string Position::getDesc() {
    return desc;
}
