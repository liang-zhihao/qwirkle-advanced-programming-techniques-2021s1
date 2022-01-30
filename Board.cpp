//
// Created by 34773 on 1/29/2022.
//

#include <set>
#include "Board.h"

Board::Board() {
    int rows = 7, cols = 7;
    board.resize(rows);
    for (auto &i : board) {
        i.resize(cols);
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            board[i][j] = Tile();
        }
    }
}

int Board::getRows() {

    return board.size();
}

int Board::getColumns() {
    return board[0].size();
}


void Board::extendNorth() {
    vector<Tile> newRow;
    newRow.resize(board[0].size());
    board.insert(board.begin(), newRow);
}

void Board::extendSouth() {
    vector<Tile> newRow;
    newRow.resize(board[0].size());
    board.push_back(newRow);
}

void Board::extendEast() {
    for (auto &j : board) {
        j.emplace_back();
    }
}

void Board::extendWest() {
    for (auto &j : board) {
        j.insert(j.begin(), Tile());
    }
}


void Board::placeTile(int row, int column, Tile tile) {

    board[row][column] = tile;

}

Tile Board::getTile(int row, int column) {
    return board[row][column];
}

int Board::getRowScore(int row, int column) {
    int tmp = 0, rowScore = 0,
            columns = getColumns(), startColumn = column;
    tmp = column;
    while (tmp >= 0 && !board[row][tmp].isEmpty()) {
        startColumn = tmp;
        tmp--;
    }
    //    right
    tmp = startColumn;
    while (tmp < columns && !board[row][tmp].isEmpty()) {
        rowScore++;
        tmp++;
    }
    rowScore = rowScore == 1 ? 0 : rowScore;
    cout << "Row got " << rowScore << endl;
    return rowScore;
}

int Board::getColumnScore(int row, int column) {
    int tmp = 0, columnScore = 0,
            rows = getRows(),
            startRow = row;
    // up
    tmp = row;
    while (tmp >= 0 && !board[tmp][column].isEmpty()) {
        startRow = tmp;
        tmp--;
    }
    tmp = startRow;
    while (tmp < rows && !board[tmp][column].isEmpty()) {
        columnScore++;
        tmp++;
    }
    columnScore = columnScore == 1 ? 0 : columnScore;
    cout << "Column got " << columnScore << endl;
    return columnScore;
}

int Board::getScore(int row, int column) {
    int score = max(1, getColumnScore(row, column) + getRowScore(row, column));
    return score;
}

bool Board::hasQWIRKLE(int row, int column) {
    return getRowScore(row, column) == QWIRKLE_COUNT || getColumnScore(row, column) == QWIRKLE_COUNT;
}

bool Board::isEmptyPosition(int row, int column) {
    return board[row][column].isEmpty();
}

ostream &operator<<(ostream &os, const Board &boardC) {
    vector<vector<Tile>> board = boardC.board;
    int rows = board.size(), columns = board[0].size();
    os << " ";
    for (int i = 0; i < columns; ++i) {
        os << setw(3) << i;
    }
    os << endl << " ";
    for (int i = 0; i < columns; ++i) {
        os << "----";
    }
    os << endl;

    for (int i = 0; i < rows; ++i) {
        char rowChar = i + ASCII_A;
        os << rowChar << " |";
        for (int j = 0; j < columns; ++j) {
            Tile tile = board[i][j];
            string tileStr = tile.isEmpty() ? "  " : tile.toString();
            os << tileStr << "|";
        }
        os << endl;
    }
    return os;
}

bool Board::hasNeighbour(int row, int column) {
    // north
    if (row - 1 >= 0 && !isEmptyPosition(row - 1, column)) {
        return true;
    }
    // south
    if (row + 1 < getRows() && !isEmptyPosition(row + 1, column)) {
        return true;

    }
    // west
    if (column - 1 >= 0 && !isEmptyPosition(row, column - 1)) {
        return true;

    }
    // east
    if (column + 1 < getColumns() && !isEmptyPosition(row, column + 1)) {
        return true;
    }
    return false;
}

int Board::getTileSize() {
    int size = 0;
    for (vector<Tile> vec: board) {
        for (Tile tile:vec) {
            if (!tile.isEmpty()) {
                size++;
            }
        }
    }
    return size;
}

bool Board::isBoardValid(int row, int column, const Tile &tile) {
    bool isColumnValid = false, isRowValid = false;
    int rowSize = 0, columnSize = 0;
    board[row][column] = tile;
    int tmp,
            maxRow = getRows(),
            startRow = row;
    //   column

    tmp = row;
    while (tmp >= 0 && !board[tmp][column].isEmpty()) {
        startRow = tmp;
        tmp--;
    }
    tmp = startRow;

    set<char> colourSet{};
    set<int> shapeSet{};

    while (tmp < maxRow && !board[tmp][column].isEmpty()) {
        colourSet.insert(board[tmp][column].colour);
        shapeSet.insert(board[tmp][column].shape);
        rowSize++;
        tmp++;
    }
    if ((colourSet.size() == rowSize && shapeSet.size() == 1) ||
        (shapeSet.size() == rowSize && colourSet.size() == 1)) {
        isColumnValid = true;
    }

    //    row
    colourSet = {};
    shapeSet = {};
    int maxColumn = getColumns(), startColumn = column;
    tmp = column;
    while (tmp >= 0 && !board[row][tmp].isEmpty()) {
        startColumn = tmp;
        tmp--;
    }
    tmp = startColumn;
    while (tmp < maxColumn && !board[row][tmp].isEmpty()) {
        colourSet.insert(board[row][tmp].colour);
        shapeSet.insert(board[row][tmp].shape);
        columnSize++;
        tmp++;
    }
    if ((colourSet.size() == columnSize && shapeSet.size() == 1) ||
        (shapeSet.size() == columnSize && colourSet.size() == 1)) {
        isRowValid = true;
    }
    board[row][column] = Tile();

    return isRowValid && isColumnValid;

}




