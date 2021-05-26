#include <iostream>
#include "Humanoid.h"
#include "../Actions/Move.h"

using namespace std;

Humanoid::Humanoid(const Coord &coord) : alive(true), coord(coord), action(nullptr) {}

bool Humanoid::isAlive() const {
   return alive;
}

int Humanoid::distanceTo(Humanoid *o) {
   return max(abs(getPos().getX() - o->getPos().getX()),
               abs(getPos().getY() - o->getPos().getY()));
}

void Humanoid::move(const Coord &newPlace) {
   coord = newPlace;
}

const Coord &Humanoid::getPos() {
   return coord;
}

void Humanoid::kill() {
   alive = false;
}

void Humanoid::executeAction(Field &field) {
   if(action != nullptr) {
      action->execute(field);
      delete action;
      action = nullptr;
   }
}

Humanoid::~Humanoid() {
   cout << "on détruit un humanoïd" << endl;
}
