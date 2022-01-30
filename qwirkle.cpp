


#define EXIT_SUCCESS    0

#include <iostream>
#include "LinkedList.h"
#include "TileCodes.h"
#include "GameEngine.h"
#include "Position.h"
#include "Board.h"
#include "regex"

using namespace std;

void printMenu();

void printCredits();

void loadGame();

void newGame();

bool isNameValid(const string &name);

int nextInt();

int main() {


    GameEngine *gameEngine = new GameEngine();
    LinkedList *linkedList = new LinkedList();
    linkedList->addElement(new Tile(RED, CIRCLE));
    linkedList->addElement(new Tile(RED, CIRCLE));
    linkedList->addElement(new Tile(RED, CIRCLE));
    linkedList->addElement(new Tile(RED, CIRCLE));
//    cout << linkedList->toString();

//    string replacePattern = "replace [R|O|Y|G|B|P][1-6]";
//    string command;
//    getline(cin, command);
//    cout << regex_match(command, regex(replacePattern));
//    regex_match(command, regex(placePattern)))
//    cout << linkedList->toString();
//    Tile *tile = linkedList->pop();
//    cout << linkedList->toString();
//    cout << linkedList->toString();

    bool runMenu = true;
    cout << "Welcome to Qwirkle!" << endl << "-------------------" << endl;
    int option = 0;
    //    todo need more robustness
    while (runMenu) {
        printMenu();
        option = nextInt();
        if (option < 1 || option > 4) {
            cout << "Option error." << endl;
        }
        switch (option) {
            case 1:
                newGame();
//                runMenu = false;
                break;
            case 2:
                break;
            case 3:
                printCredits();
                break;
            case 4:
                cout << "\nGoodbye";
                runMenu = false;
                break;
            default:
                cout << "Error.";
        }
    }
    return EXIT_SUCCESS;
}

int nextInt() {
    string option;
    cout << "> ";
    getline(cin, option);
    return atoi(option.c_str());
}

void printMenu() {
    cout << "Menu" << endl << "----" << endl;
    cout << "1. New Game" << endl;
    cout << "2. Load Game" << endl;
    cout << "3. Credits (Show student information)" << endl;
    cout << "4. Quit" << endl;
}

void printCredits() {
    cout << "----------------------------------\n";
    cout << "Name: Zhihao Liang\n";
    cout << "----------------------------------\n";

}

void loadGame() {

}

void newGame() {
    string player1, player2;

    cout << "Starting a New Game\n";
    cout << "Enter a name for player 1 (uppercase characters only)\n";
    getline(cin, player1);
    if (!isNameValid(player1)) {
        cout << "Invalid Input\n";
        return;
    }
    cout << "Enter a name for player 2 (uppercase characters only)\n";
    getline(cin, player2);

    if (!isNameValid(player2)) {
        cout << "Invalid Input\n";
        return;
    }
    cout << "Let's Play!\n";
    GameEngine *gameEngine = new GameEngine(player1, player2);
    gameEngine->run();

}


bool isNameValid(const string &name) {
    for (char i :name) {
        if (i < 65 || i > 90) {
            return false;
        }
    }
    return true;
}
