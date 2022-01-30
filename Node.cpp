
#include "Node.h"


Node::Node(Tile *tile) {
    // TODO
    this->tile = tile;
    next = nullptr;
}


Node::Node(Node &other) {
    // TODO

    this->next = other.next;

//    this->tile = new Tile(other.tile->colour, other.tile->shape);
    this->tile = other.tile;


}

Node::~Node() {

}
