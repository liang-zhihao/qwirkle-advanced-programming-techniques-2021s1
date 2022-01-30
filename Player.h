//
// Created by 34773 on 1/27/2022.
//

#ifndef QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_PLAYER_H
#define QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_PLAYER_H

#include "iostream"
#include "LinkedList.h"

using namespace std;

class Player {
public:
    Player();
    Player(string name);

    ~Player();

    int getScore();

    bool hasHand(const Tile& hand);

    void addHand(Tile *hand);

    Tile* removeHand(const Tile& hand);

    Tile *findTile(Tile *hand);

    string getName();

    void addScore(int scoreIn);

    string getHandsString();

    int  getHandsSize();

private:
    string name;
    LinkedList *hands;
    int score;
};


#endif //QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_PLAYER_H
