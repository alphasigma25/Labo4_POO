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
#include "../Utils/randomGenerator.h"

using namespace std;

void Vampire::setAction(Field &field) {
   Humanoid* target = field.closestTo((Humanoid *)this, typeid(Human));
   if(target == nullptr){
      action = new Move((Humanoid *) this, coord);
      return;
   }
   if(target->distanceTo((Humanoid *)this) > 1){

      Coordinate newCoord = track(field, target, 1);
      action = new Move((Humanoid *) this, newCoord);
   } else if(!target->isTargeted()){
      target->setTargeted(true);
      srand (time(NULL));
      if(rand() % 2){
         action = new Kill(target);
      }else {
         action  = new Convert(target);
      }
   }
}

Vampire::Vampire(const Coord &coord) : Humanoid(coord) {}

Vampire::~Vampire() {
}

