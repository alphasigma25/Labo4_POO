#include "Humanoid.h"

using namespace std;

Humanoid::Humanoid(bool alive, const valarray<int> &coord)
: alive(alive), coord(coord) {}

bool Humanoid::isAlive() const {
   return alive;
}

int Humanoid::distanceTo(const Humanoid &o) {
   return abs(coord - o.coord).sum();
}

void Humanoid::move(const valarray<int> &newPlace) {
   coord = newPlace;
}

const valarray<int> &Humanoid::getPos() {
   return coord;
}
