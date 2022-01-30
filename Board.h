//
// Created by 34773 on 1/29/2022.
//

#ifndef QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_BOARD_H
#define QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_BOARD_H

#define  ASCII_A  65
#define QWIRKLE_COUNT 6

#include "Tile.h"
#include "vector"
#include <iomanip>

using namespace std;

class Board {
public:
    Board();

    int getRows();

    int getColumns();


    void extendNorth();

    void extendSouth();

    void extendEast();

    void extendWest();

    void placeTile(int row, int column, Tile tile);

    Tile getTile(int row, int column);

    int getScore(int row, int column);

    bool hasQWIRKLE(int row, int column);

    bool isEmptyPosition(int row, int column);


    friend ostream &operator<<(ostream &, const Board &);

    vector<vector<Tile>> board;

    bool hasNeighbour(int row, int column);

    int getTileSize();

    bool isBoardValid(int row, int column,const Tile& tile);

private:

    int getRowScore(int row, int column);

    int getColumnScore(int row, int column);

};


#endif //QWIRKLE_ADVANCED_PROGRAMMING_TECHNIQUES_2021S1_BOARD_H
