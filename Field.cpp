//
// Created by AnneSo on 12.05.2021.
//

#include "Field.h"
#include <list>

using namespace std;

Field::Field() : turn(0) {}

int Field::nextTurn()
{
// Déterminer les prochaines actions
   for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
      (*it)->setAction(*this);
// Executer les actions
   for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); it++)
      (*it)->executeAction(*this);
// Enlever les humanoides tués
   for (list<Humanoid*>::iterator it = humanoids.begin(); it != humanoids.end(); )
      if (!(*it)->isAlive()) {
         it = humanoids.erase(it); // suppression de l’élément dans la liste
         delete *it; // destruction de l’humanoide référencé
      }
      else {
         ++it;
      }
   return turn++;
}

const list<Humanoid *> &Field::getPopulation() const {
   return humanoids;
}
