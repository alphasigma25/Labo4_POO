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
   if(target == nullptr){
      action = new Move((Humanoid *) this, coord);
      return;
   }
   if(target->distanceTo((Humanoid *)this) > 1){

      Coordinate newCoord = track(field,target,2);
      action = new Move((Humanoid *) this, newCoord);
   } else{
      action = new Kill(target);
   }
}

Buffy::Buffy(const Coord &coord) : Humanoid(coord) {}

Buffy::~Buffy() {
}


