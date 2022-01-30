
#include "LinkedList.h"

LinkedList::LinkedList() {
    head = nullptr;
    length = 0;
    // TODO
}

LinkedList::~LinkedList() {
}

int LinkedList::getLength() {

    return length;
}

void LinkedList::addElement(Tile *tile) {
    Node *newNode = new Node(tile);
    if (length == 0) {
        head = newNode;
    } else {
        Node *current = head;
        while (current && current->next) {
            current = current->next;
        }
        current->next = newNode;

    }
    length++;

}

Node *LinkedList::getNode(const Tile &tile) {
    Node *current = head;
    while (current->next != nullptr) {
        if (*current->tile == tile) {
            return current;
        }
        current = current->next;
    }
    return nullptr;
}

string LinkedList::toString() {
    string s;
    if (length == 0) {
        s = "";
    } else {
        Node *current = head;
        while (current) {
            s += current->tile->toString();
            if (current->next != nullptr) {
                s += " ";
            }
            current = current->next;
        }
    }
    return s + "\n";
}

Tile *LinkedList::removeElement(const Tile &tile) {
    Node *current = head;
    Node *prevNode = nullptr;

    if (*head->tile == tile) {
        head = head->next;
        length--;
        return current->tile;
    }
    while (current->next != nullptr) {
        if (*current->tile == tile) {
            prevNode->next = current->next;
            length--;
            return current->tile;
        }
        prevNode = current;
        current = current->next;
    }
    if (*current->tile == tile) {
        length--;
        prevNode->next = nullptr;
        return current->tile;
    }
    return nullptr;
}

bool LinkedList::hasElement(const Tile &tile) {
    Node *current = head;
    while (current != nullptr) {
        if (*current->tile == tile) {
            return true;
        }
        current = current->next;
    }
    return false;
}

void LinkedList::insert(int i, Tile *tile) {
    Node *newNode = new Node(tile);
    if (i == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node *current = head;
    Node *prevNode = nullptr;
    while (i-- > 0) {
        prevNode = current;
        current = current->next;
    }
    newNode->next = current;
    prevNode->next = newNode;
}

Tile *LinkedList::pop() {
    if (head != nullptr) {
        Node *current = head;
        head = head->next;
        length--;
        return current->tile;
    }
    return nullptr;
}
