//
// Created by AnneSo on 12.05.2021.
//

#include <ctime>
#include "Vampire.h"
#include "Human.h"
#include "../Actions/Move.h"
#include "../Actions/Kill.h"
#include "../Actions/Convert.h"

char Vampire::symbol() const {
   return 'v';
}

void Vampire::setAction(Field &field) {
   Humanoid* target = field.closestTo((Humanoid *)this, typeid(Human));
   if(target->distanceTo((Humanoid *)this) > 1){

      //distance : (A - B).max();

      Coord delta = (target->getPos() - coord); // "vecteur" de mouvement
      delta /= abs(delta).max();    // on norme le vecteur pour que le déplacement
      // soit de 1

      if((coord + delta)[0] > field.getWidth()) delta[0] = coord[0];
      if((coord + delta)[1] > field.getHeight()) delta[0] = coord[1];

      action = new Move((Humanoid *) this, coord + delta);
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
