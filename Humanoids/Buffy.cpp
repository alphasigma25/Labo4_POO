//
// Created by AnneSo on 12.05.2021.
//

#include <iostream>
#include "Buffy.h"
#include "Vampire.h"
#include "../Actions/Move.h"
#include "../Actions/Kill.h"

using namespace std;

void Buffy::kill() {
   alive = true;
} //Buffy est immortel

void Buffy::setAction(Field &field) {
   Humanoid* target = field.closestTo((Humanoid *)this, typeid(Vampire));
   if(target == nullptr) return;
   if(target->distanceTo((Humanoid *)this) > 1){

      //distance : (A - B).max();

      Coord delta = (target->getPos() - coord); // "vecteur" de mouvement
      int div = max(abs(delta.getX()),abs(delta.getY()));
      cout << delta.getX() << " " << abs(delta.getX()) << " " << max(abs(delta
      .getX()),abs(delta.getY())) << endl;
      // on norme le vecteur pour que le déplacement soit de 1
      delta.setX(delta.getX()/div);
      delta.setY(delta.getY()/div);

      Coord newCoord = delta + coord;

      if(newCoord.getX() >= field.getWidth() || newCoord.getX() < 0)
         newCoord.setX(coord.getX());
      if(newCoord.getY() >= field.getHeight() || newCoord.getY() < 0)
         newCoord.setY(coord.getY());

      action = new Move((Humanoid *) this, newCoord);
   } else{
      action = new Kill(target);
   }
}

Buffy::Buffy(const Coord &coord) : Humanoid(coord) {}

Buffy::~Buffy() {
}


