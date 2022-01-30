//
// Created by 34773 on 1/27/2022.
//

#ifndef QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_GAMEENGINE_H
#define QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_GAMEENGINE_H

#define TILE_SIZE 72
#define HANDS_SIZE 6

#include "LinkedList.h"
#include "Player.h"
#include <algorithm>
#include <random>
#include "vector"
#include <ctime>
#include "Position.h"
#include "Board.h"

using namespace std;
//int TILE_SIZE = 72;

class GameEngine {
public:
    GameEngine();

    GameEngine(string player1In, string player2In);

    bool placeTile(Player *currentPlayer, const Tile &tile, Position position);

    LinkedList *generateTiles();


    bool replace(Player *player, const Tile &tile);

    void endGame();


    void shuffleBag();

    void saveGame();

    Tile *drawTile();

    void run();

    void nextTurn(Player* currentPlayer);

    bool isTileValid(string tile) ;

    bool isGameOver();
private:

    Player *player1;

    Player *player2;

    LinkedList *bag;

    Board *pBoard;



};


#endif //QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_GAMEENGINE_H
