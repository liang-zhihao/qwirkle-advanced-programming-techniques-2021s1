//
// Created by 34773 on 1/27/2022.
//

#include "Player.h"

#include <utility>


Player::Player() {
    hands = new LinkedList();
    score = 0, name = "";
}

Player::Player(string name) {
    hands = new LinkedList();
    score = 0, this->name = std::move(name);
}

Player::~Player() {}

Tile *Player::removeHand(const Tile &hand) {
    return hands->removeElement(hand);
}

bool Player::hasHand(const Tile &hand) {
    return hands->hasElement(hand);
}

void Player::addHand(Tile *hand) {
    hands->addElement(hand);
}

Tile *Player::findTile(Tile *hand) {

    return nullptr;

}

string Player::getName() {
    return name;
}

int Player::getScore() {
    return score;
}

void Player::addScore(int scoreIn) {
    this->score += scoreIn;
}

string Player::getHandsString() {

    return hands->toString();
}

int Player::getHandsSize() {
    return hands->getLength();
}


