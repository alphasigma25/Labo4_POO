//
// Created by AnneSo on 12.05.2021.
//

#include "Field.h"
#include "Humanoids/Buffy.h"
#include "Humanoids/Vampire.h"
#include "Humanoids/Human.h"
#include "Utils/randomGenerator.h"
#include <list>
#include <ctime>

using namespace std;

Field::Field(size_t height, size_t width, size_t nbHumans, size_t nbVampires)
: turn(0), dimensions{height, width}, buffyVictory(false) {
   randomGenerator rg = randomGenerator::getGenerator();
   for(size_t i = 0; i < nbHumans; ++i){
      Humanoid* h = (Humanoid *) new Human(
            Coordinate(rg.getRand(0,height-1), rg.getRand(0,width-1)));
      humanoids.push_back(h);
   }
   for(size_t i = 0; i < nbVampires; ++i){
      Humanoid* h = (Humanoid *) new Vampire(
            Coordinate(rg.getRand(0,height-1), rg.getRand(0,width-1)));
      humanoids.push_back(h);
   }
   humanoids.push_back((Humanoid *) new Buffy(
         Coordinate(rg.getRand(0,height-1), rg.getRand(0,width-1))));
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
         Humanoid* toDelete = *it;
         it = humanoids.erase(it); // suppression de l’élément dans la liste
         delete toDelete; // destruction de l’humanoide référencé
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

bool Field::stillRunning() {
   bool humans = false;
   bool vampires = false;
   for(Humanoid* h: humanoids){
      if(typeid(*h) == typeid(Human)) {
         humans = true;
      } else if(typeid(*h) == typeid(Vampire)) {
         vampires = true;
      }

      if(vampires) return true;
   }
   buffyVictory = humans;
   return false;
}

bool Field::isBuffyVictory() const {
   return buffyVictory;
}

Humanoid *Field::closestTo(Humanoid *h, const type_info& ti) {
   Humanoid* closest = nullptr;
   int dist = max(getHeight(),getWidth());
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
