
#ifndef ASSIGN2_TILE_H
#define ASSIGN2_TILE_H

// Define a Colour type
typedef char Colour;

// Define a Shape type
typedef int Shape;

#include <iostream>

using namespace std;

class Tile {
public:
    Colour colour;
    Shape shape;


    Tile(Colour c, Shape shape);

    Tile(Tile const &other);

    Tile();

    ~Tile();

    string toString();

    bool isEmpty() const;

    bool operator==(const Tile &tile) const;

    bool isOnlyColourSame(const Tile& tile);

    bool isOnlyShapeSame(const Tile& tile);
};

#endif // ASSIGN2_TILE_H
