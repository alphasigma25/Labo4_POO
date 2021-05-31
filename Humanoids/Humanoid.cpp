#include <ctime>
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
   cout << "on detruit un humanoid" << endl;
}

Coordinate Humanoid::track(Field &field, Humanoid *target, int n) {

   //distance : (A - B).max();

   Coord delta = Coordinate(target->getPos() - coord); // "vecteur" de mouvement
   double div = max(abs(delta.getX()),abs(delta.getY()));
   //cout << delta.getX() << " " << delta.getY() << " " << max(abs(delta.getX()), abs(delta.getY())) << endl;
   // on norme le vecteur pour que le déplacement soit de n
   delta.setX(ceil(delta.getX()/div)*n);
   delta.setY(ceil(delta.getY()/div)*n);

   Coord newCoord = delta + coord;

   if(newCoord.getX() >= field.getHeight() || newCoord.getX() < 0)
      newCoord.setX(coord.getX());
   if(newCoord.getY() >= field.getWidth() || newCoord.getY() < 0)
      newCoord.setY(coord.getY());

   return newCoord;
}

Coordinate Humanoid::move(Field &field) {
   //générer le déplacement aléatoire
   srand(time(NULL));
   int deltaX, deltaY;
   do {
      deltaX = rand() % 3 - 1;
      deltaY = rand() % 3 - 1;
   }
   while(deltaX == 0 && deltaY == 0);

   int x = getPos().getX() + deltaX;
   int y = getPos().getY() + deltaY;

   if(x >= field.getHeight() || x < 0) x = this->getPos().getX();
   if(y >= field.getWidth() || y < 0) y = this->getPos().getY();
   return {x,y};
}
