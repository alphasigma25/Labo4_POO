#include <ctime>
#include <iostream>

#include "Humanoid.h"
#include "../Utils/randomGenerator.h"

using namespace std;

Humanoid::Humanoid(const Coord &coord) : alive(true), coord(coord), action
(nullptr), targeted(false) {}

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

   Coord delta = Coordinate(target->coord - coord); // "vecteur" de mouvement
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
   randomGenerator rg = randomGenerator::getGenerator();
   int deltaX, deltaY;
   do {
      deltaX = rg.getRand(-1,1);
      deltaY = rg.getRand(-1,1);
   }
   while(deltaX == 0 && deltaY == 0);

   int x = coord.getX() + deltaX;
   int y = coord.getY() + deltaY;

   if(x >= field.getHeight() || x < 0) x = coord.getX();
   if(y >= field.getWidth() || y < 0) y = coord.getY();
   return Coord{x,y};
}

bool Humanoid::isTargeted() const{
   return targeted;
}

void Humanoid::setTargeted(bool targeted){
   this->targeted = targeted;
}
