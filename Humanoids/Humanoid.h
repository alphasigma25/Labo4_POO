#ifndef L4_HUMANOID_H
#define L4_HUMANOID_H


#include "../Field.h"
#include <valarray>

class Humanoid {
   bool alive;
   valarray<int> coord;
protected:
   int distanceTo(const Humanoid& o);
public:
   Humanoid(bool alive, const valarray<int> &coord);

   void move(const valarray<int>& newPlace);

   virtual void setAction(const Field& field) = 0;
   virtual void executeAction(const Field& field) = 0;
   bool isAlive() const;
};


#endif //L4_HUMANOID_H
