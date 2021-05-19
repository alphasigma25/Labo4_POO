//
// Created by AnneSo on 12.05.2021.
//

#include <ctime>
#include "Human.h"
#include "../Actions/Move.h"
char Human::symbol() const {
   return 'h';
}

void Human::setAction(Field &field) {
   //générer le déplacement aléatoire
   srand(time(NULL));
   int deltaX, deltaY;
   do {
      deltaX = rand() % 3 - 1;
      deltaY = rand() % 3 - 1;
   }
   while(deltaX == 0 && deltaY == 0);

   size_t x = coord[0] + deltaX;
   size_t y = coord[1] + deltaY;

   if(x > field.getWidth()) x = coord[0];
   if(y > field.getHeight()) y = coord[1];

   action = new Move((Humanoid*) this, {x,y});
}

Human::Human(const Coord &coord) : Humanoid(coord) {}
