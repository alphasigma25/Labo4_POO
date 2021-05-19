//
// Created by AnneSo on 12.05.2021.
//

#include "Buffy.h"
#include "Vampire.h"
#include "../Actions/Move.h"
#include "../Actions/Kill.h"
char Buffy::symbol() const {
   return 'b';
}

void Buffy::kill() {
   alive = true;
} //Buffy est immortel

void Buffy::setAction(Field &field) {
   Humanoid* target = field.closestTo((Humanoid *)this, typeid(Vampire));
   if(target->distanceTo((Humanoid *)this) > 1){

      //distance : (A - B).max();

      Coord delta = (target->getPos() - coord); // "vecteur" de mouvement
      delta /= abs(delta).max();    // on norme le vecteur pour que le déplacement
      // soit de 1

      if((coord + delta)[0] > field.getWidth()) delta[0] = coord[0];
      if((coord + delta)[1] > field.getHeight()) delta[0] = coord[1];

      action = new Move((Humanoid *) this, coord + delta+1);
   } else{
      action = new Kill(target);
   }
}

Buffy::Buffy(const Coord &coord) : Humanoid(coord) {}


