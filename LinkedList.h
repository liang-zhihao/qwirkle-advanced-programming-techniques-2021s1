
#ifndef ASSIGN2_LINKEDLIST_H
#define ASSIGN2_LINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

class LinkedList {
public:

    LinkedList();

    ~LinkedList();

    int getLength();

    void addElement(Tile *tile);

    Tile* removeElement(const Tile &tile);

    Node *getNode(const Tile &tile);

    void insert(int i, Tile *tile);

    bool hasElement(const Tile &tile);

    string toString();

    Tile* pop();

private:
    Node *head;
    int length;
};

#endif // ASSIGN2_LINKEDLIST_H
