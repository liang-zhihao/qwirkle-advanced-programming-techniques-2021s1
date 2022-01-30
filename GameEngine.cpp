//
// Created by 34773 on 1/27/2022.
//
#include <regex>
#include "GameEngine.h"

#include "TileCodes.h"

GameEngine::GameEngine(string player1In, string player2In) {

    this->player1 = new Player(player1In);
    this->player2 = new Player(player2In);
    bag = generateTiles();
    pBoard = new Board();
}

GameEngine::GameEngine() {
    bag = generateTiles();
    pBoard = new Board();
}

void GameEngine::endGame() {

}

LinkedList *GameEngine::generateTiles() {
    char colours[] = {RED, ORANGE, YELLOW, GREEN, BLUE, PURPLE};
    char shapes[] = {CIRCLE, STAR_4, DIAMOND, SQUARE, STAR_6, CLOVER};
    vector<Tile> tiles;
    auto *tmpBag = new LinkedList();
    int index[TILE_SIZE];
    std::default_random_engine generator(time(NULL));
    for (int i = 0; i < TILE_SIZE; ++i) {
        index[i] = i;
    }
    shuffle(index, index + TILE_SIZE, generator);
    for (char colour: colours) {
        for (char shape:shapes) {
            tiles.emplace_back(colour, shape);
            tiles.emplace_back(colour, shape);
        }
    }
//    default_random_engine generator{std::random_device{}()};

    for (int i : index) {
        Tile tmp = tiles[i];
        Tile *tile = new Tile(tmp);
        tmpBag->addElement(tile);
    }

    return tmpBag;
}

bool GameEngine::placeTile(Player *currentPlayer, const Tile &tile, Position position) {
    int row = position.getRow(), column = position.getColumn();

    int rows = pBoard->getRows(), columns = pBoard->getColumns();

//    has a tile? has the hand? has neighbours?
    if (!pBoard->isEmptyPosition(row, column)) {
        return false;
    }
// note: too many '!'
    if (pBoard->getTileSize() != 0) {
        // same color with diff shape
        // same shape with diff color
        if (!pBoard->hasNeighbour(row, column) || !pBoard->isBoardValid(row, column, tile)) {
            return false;
        }
    }


    pBoard->placeTile(row, column, tile);
    currentPlayer->removeHand(tile);

    // check QWIRKLE

    if (pBoard->hasQWIRKLE(row, column)) {
        cout << "QWIRKLE!!!" << endl;
    }

//    add score
    int score = pBoard->getScore(row, column);
    cout << currentPlayer->getName() << " got " << score << " points" << endl;

    currentPlayer->addScore(score);
// supply hands
    if (bag->getLength() > 0) {
        currentPlayer->addHand(bag->pop());
    }
//    extend pBoard
    if (row == 0) {
        pBoard->extendNorth();
    }
    if (column == 0) {
        pBoard->extendWest();
    }
    if (row == rows - 1) {
        pBoard->extendSouth();
    }
    if (column == columns - 1) {
        pBoard->extendEast();
    }
    return true;
}


bool GameEngine::replace(Player *player, const Tile &tile) {

    Tile *fold = player->removeHand(tile);
    Tile *drawn = drawTile();

    int len = bag->getLength();
    srand(time(nullptr));
    int randomIndex = rand() % len;

    bag->insert(randomIndex, fold);
    player->addHand(drawn);

    return true;
}

void GameEngine::saveGame() {}

void GameEngine::shuffleBag() {
    int length = bag->getLength();
    int index[length];
    for (int i = 0; i < length; ++i) {
        index[i] = i;
    }
}


Tile *GameEngine::drawTile() {
    return bag->pop();
}

void GameEngine::run() {
    // init hands

    for (int i = 0; i < HANDS_SIZE; ++i) {
        player1->addHand(bag->pop());
        player2->addHand(bag->pop());
    }
    while (true) {
        if (isGameOver()) {
            break;
        }
        nextTurn(player1);
        if (isGameOver()) {
            break;
        }
        nextTurn(player2);
    }

}

void GameEngine::nextTurn(Player *currentPlayer) {
    cout << currentPlayer->getName() << ", " << "it's your turn" << endl;
    cout << "Score for " << player1->getName() << ": " << player1->getScore() << endl;
    cout << "Score for " << player2->getName() << ": " << player2->getScore() << endl;
    cout << *pBoard << endl;
    cout << "Your hand is " << endl << currentPlayer->getHandsString();
    while (true) {
        cout << ">";
        string command;
        getline(cin, command);
        if (command.empty()) {
            continue;
        }
// optimal
        string replacePattern = "replace [R|O|Y|G|B|P][1-6]";
        string placePattern = "place [R|O|Y|G|B|P][1-6] at [A-Z]([0-9]|1[0-9]|2[0-6])$";

        if (!(regex_match(command, regex(replacePattern)) ||
              regex_match(command, regex(placePattern)))) {
            cout << "invalid input (command is invalid)" << endl;
            continue;
        }

        std::regex reg("[ ]");
        std::vector<std::string> v(std::sregex_token_iterator(command.begin(), command.end(), reg, -1),
                                   std::sregex_token_iterator());

        string operation = v[0];
        string tileStr = v[1];
        Tile tile = Tile(tileStr[0], tileStr[1] - '0');
        if (!currentPlayer->hasHand(tile)) {
            cout << "invalid input (current player does not have this tile)" << endl;
            continue;
        }
        if (operation == "replace") {
            replace(currentPlayer, tile);
            break;
        } else if (operation == "place") {
            string posStr = v[3];
            if (!placeTile(currentPlayer, tile, Position(posStr))) {
                cout << "invalid input (cannot place the tile)" << endl;
                continue;
            }
            break;
        }

    }


}


bool GameEngine::isGameOver() {
    // is game over
    if (player1->getHandsSize() == 0) {
        player1->addScore(6);
        return true;

    }
    if (player2->getHandsSize() == 0) {
        player2->addScore(6);
        return true;

    }
    return false;
}






