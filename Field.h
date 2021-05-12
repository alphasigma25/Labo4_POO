//
// Created by AnneSo on 12.05.2021.
//

#ifndef L4_FIELD_H
#define L4_FIELD_H

#include <list>
#include "iostream"
#include "Humanoids/Humanoid.h"

class Field {
   std::list<Humanoid*> humanoids;
   int turn;

public:
   Field();
   int nextTurn();

   const std::list<Humanoid *> &getPopulation() const;
};


#endif //L4_FIELD_H
