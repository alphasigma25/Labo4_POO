//
// Created by AnneSo on 12.05.2021.
//

#include "Field.h"
#include "Humanoids/Buffy.h"
#include "Humanoids/Vampire.h"
#include "Humanoids/Human.h"
#include <list>
#include <ctime>

using namespace std;

Field::Field(size_t height, size_t width, int nbHumans, int nbVampires)
: turn(0), dimensions{height, width}, nbHumans(nbHumans), nbVampires(nbVampires) {
   srand (time(NULL));
   for(size_t i = 0; i < nbHumans; ++i){
      Humanoid* h = (Humanoid *) new Human({(rand() % height), rand() % width});
      humanoids.push_back(h);
   }
   for(size_t i = 0; i < nbVampires; ++i){
      Humanoid* h = (Humanoid *) new Vampire({(rand() % height), rand() % width});
      humanoids.push_back(h);
   }
   humanoids.push_back((Humanoid *) new Buffy({(rand() % height), rand() % width}));
}

int Field::nextTurn() {
// Déterminer les prochaines actions
   for (list<Humanoid *>::iterator it = humanoids.begin();
        it != humanoids.end(); it++)
      (*it)->setAction(*this);
// Executer les actions
   for (list<Humanoid *>::iterator it = humanoids.begin();
        it != humanoids.end(); it++)
      (*it)->executeAction(*this);
// Enlever les humanoides tués
   for (list<Humanoid *>::iterator it = humanoids.begin(); it != humanoids.end();)
      if (!(*it)->isAlive()) {
         it = humanoids.erase(it); // suppression de l’élément dans la liste
         delete *it; // destruction de l’humanoide référencé
      } else {
         ++it;
      }
   return turn++;
}

const list<Humanoid *> &Field::getPopulation() const {
   return humanoids;
}

int Field::getHeight() const {
   return dimensions[0];
}

int Field::getWidth() const {
   return dimensions[1];
}

bool Field::stillRunning() const {
   int humans = 0;
   int vampires = 0;
   for(Humanoid* h: humanoids){
      if(typeid(*h) == typeid(Human)) {
         ++humans;
      } else if(typeid(*h) == typeid(Vampire)) {
         ++vampires;
      }
   }
   return humans > 0 || vampires > 0;
}

Humanoid *Field::closestTo(Humanoid *h, const type_info& ti) {
   Humanoid* closest = nullptr;
   int dist = getHeight()*getWidth();
   for(Humanoid* humanoid : humanoids) {
      if (ti == typeid(*humanoid)) {
         int newDist = h->distanceTo(humanoid);
         if(newDist < dist){
            dist = newDist;
            closest = humanoid;
         }
      }
   }
   return closest;
}

void Field::addHumanoid(Humanoid *h) {
   humanoids.push_front(h);
}

Field::~Field() {
   for(Humanoid* h : humanoids){
      delete h;
   }
}
