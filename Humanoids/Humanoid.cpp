#include <ctime>
#include <iostream>
#include <random>

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
   //cout << "on detruit un humanoid" << endl;
}

Coordinate Humanoid::track(Field &field, Humanoid *target, int n) {

   Coord delta = Coordinate(target->getPos() - coord); // "vecteur" de mouvement
   int div = max(abs(delta.getX()),abs(delta.getY()));
   // on norme le vecteur pour que le déplacement soit de n
   delta.setX((delta.getX()*n)/div);
   delta.setY((delta.getY()*n)/div);

   Coord newCoord = delta + coord;

   if(newCoord.getX() >= field.getHeight() || newCoord.getX() < 0)
      newCoord.setX(coord.getX());
   if(newCoord.getY() >= field.getWidth() || newCoord.getY() < 0)
      newCoord.setY(coord.getY());

   return newCoord;
}

Coordinate Humanoid::move(Field &field) {
   //générer le déplacement aléatoire
   std::default_random_engine generator;
   std::uniform_int_distribution<int> distribution(-1,1);
   int deltaX, deltaY;
   do {
      deltaX = distribution(generator);
      deltaY = distribution(generator);
   }
   while(deltaX == 0 && deltaY == 0);

   int x = getPos().getX() + deltaX;
   int y = getPos().getY() + deltaY;

   if(x >= field.getHeight() || x < 0) x = this->getPos().getX();
   if(y >= field.getWidth() || y < 0) y = this->getPos().getY();
   return {x,y};
}
