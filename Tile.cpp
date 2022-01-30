
#include "Tile.h"

// Empty... for now?
Tile::Tile(Colour c, Shape shape) {
    colour = c;
    this->shape = shape;
}

Tile::Tile() {
    colour = '\0';
    shape = 0;
}

Tile::Tile(Tile const &other) {
    colour = other.colour;
    this->shape = other.shape;
}

Tile::~Tile() {

}

string Tile::toString() {
    string s;
    s += colour;
    s += std::to_string(shape);
    return s;
}

bool Tile::operator==(const Tile &tile) const {
    return this->shape == tile.shape && this->colour == tile.colour;
}


bool Tile::isEmpty() const {
    if (colour == '\0') {
        return true;
    }
    return false;
}

bool Tile::isOnlyColourSame(const Tile &tile) {

    return colour == tile.colour && shape != tile.shape;
}

bool Tile::isOnlyShapeSame(const Tile &tile) {
    return shape == tile.shape && colour != tile.colour;

}
