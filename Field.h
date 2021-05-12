//
// Created by AnneSo on 12.05.2021.
//

#ifndef L4_FIELD_H
#define L4_FIELD_H

#include <list>
#include "Humanoids/Humanoid.h"

class Humanoid;

class Field {
   std::list<Humanoid*> humanoids;
   int turn;

   int nbHumans;
   int nbVampires;
   const int dimensions[2];

public:
   Field(int height, int width, int nbHumans, int nbVampires);
   int nextTurn();

   int getHeight() const;
   int getWidth() const;

   const std::list<Humanoid *> &getPopulation() const;
};


#endif //L4_FIELD_H
