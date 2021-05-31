//
// Created by AnneSo on 12.05.2021.
//

#include <ctime>
#include <iostream>
#include "Human.h"
#include "../Actions/Move.h"

using namespace std;

void Human::setAction(Field &field) {
   Coordinate newCoord = move(field);

   action = new Move((Humanoid*) this, newCoord);
}

Human::Human(const Coord &coord) : Humanoid(coord) {}

Human::~Human() {
}
