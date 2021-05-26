//
// Created by AnneSo on 12.05.2021.
//

#include <ctime>
#include <iostream>
#include "Human.h"
#include "../Actions/Move.h"

using namespace std;

void Human::setAction(Field &field) {
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

   action = new Move((Humanoid*) this, Coordinate(x,y));
}

Human::Human(const Coord &coord) : Humanoid(coord) {}

Human::~Human() {
}
