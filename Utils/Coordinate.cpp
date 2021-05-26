//
// Created by AnneSo on 26.05.2021.
//

#include "Coordinate.h"

Coordinate::Coordinate(int x, int y) : x(x), y(y) {}

int Coordinate::getX() const {
   return x;
}

void Coordinate::setX(int x) {
   Coordinate::x = x;
}

int Coordinate::getY() const {
   return y;
}

void Coordinate::setY(int y) {
   Coordinate::y = y;
}

Coordinate Coordinate::operator+(const Coordinate &other) const {
   return {x+other.x, y+other.y};
}

Coordinate Coordinate::operator-(const Coordinate &other) const {
   return {x-other.x, y-other.y};
}

Coordinate Coordinate::operator+(int val) const {
   return {x+val,y+val};
}
