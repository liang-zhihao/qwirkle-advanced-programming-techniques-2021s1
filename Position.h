//
// Created by 34773 on 1/29/2022.
//

#ifndef QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_POSITION_H
#define QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_POSITION_H
//note: #define should be front of #include
#define  ASCII_A 65

#include <string>

using namespace std;


class Position {
public:
    explicit Position(string desc);

    int getColumn();

    int getRow();

    string getDesc();

private:
    string desc;
};


#endif //QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_POSITION_H
