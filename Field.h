//
// Created by AnneSo on 12.05.2021.
//

#ifndef L4_FIELD_H
#define L4_FIELD_H

#include <list>
#include <typeinfo>
#include <cstdlib>
#include "Humanoids/Humanoid.h"

class Humanoid;

class Field {
   std::list<Humanoid*> humanoids;
   int turn;

   bool buffyVictory;
   const size_t dimensions[2];

public:
   Field(size_t height, size_t width, int nbHumans, int nbVampires);
   ~Field();
   int nextTurn();

   int getHeight() const;
   int getWidth() const;

   const std::list<Humanoid *> &getPopulation() const;

   bool stillRunning();

   Humanoid * closestTo(Humanoid* h, const std::type_info& ti);

   void addHumanoid(Humanoid* h);

   int isInBounds(Humanoid* target);

   bool isBuffyVictory() const;
};


#endif //L4_FIELD_H
