//
// Created by AnneSo on 12.05.2021.
//

#include <ctime>
#include <iostream>
#include "Vampire.h"
#include "Human.h"
#include "../Actions/Move.h"
#include "../Actions/Kill.h"
#include "../Actions/Convert.h"

using namespace std;

void Vampire::setAction(Field &field) {
   Humanoid* target = field.closestTo((Humanoid *)this, typeid(Human));
   if(target->distanceTo((Humanoid *)this) > 1){

      //distance : (A - B).max();

      Coord delta = Coordinate(target->getPos() - coord); // "vecteur" de
      // mouvement
      int div = max(abs(delta.getX()),abs(delta.getY()));
      // on norme le vecteur pour que le déplacement soit de 1
      delta.setX(delta.getX()/div);
      delta.setY(delta.getY()/div);

      Coord newCoord = delta + getPos();

      if(newCoord.getX() >= field.getWidth() || newCoord.getX() < 0)
         newCoord.setX(this->getPos().getX());
      if(newCoord.getY() >= field.getHeight() || newCoord.getY() < 0)
         newCoord.setY(this->getPos().getY());

      action = new Move((Humanoid *) this, newCoord);
   } else{
      srand (time(NULL));
      if(rand() % 2){
         action = new Kill(target);
      }else{
         action  = new Convert(target);
      }
   }
}

Vampire::Vampire(const Coord &coord) : Humanoid(coord) {}

Vampire::~Vampire() {
}

