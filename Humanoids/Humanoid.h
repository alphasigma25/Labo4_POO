#ifndef L4_HUMANOID_H
#define L4_HUMANOID_H


#include "../Field.h"
#include <valarray>
class Field;

class Humanoid {
   bool alive;
   std::valarray<int> coord;
protected:
   int distanceTo(const Humanoid& o);
public:
   Humanoid(bool alive, const std::valarray<int> &coord);

   void move(const std::valarray<int>& newPlace);
   const std::valarray<int>& getPos();

   virtual char symbol() const = 0;

   virtual void setAction(const Field& field) = 0;
   virtual void executeAction(const Field& field) = 0;
   bool isAlive() const;
};


#endif //L4_HUMANOID_H
