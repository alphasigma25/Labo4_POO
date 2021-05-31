#ifndef L4_HUMANOID_H
#define L4_HUMANOID_H


#include "../Field.h"
#include "../Actions/Action.h"
#include "../Utils/Coordinate.h"
#include <valarray>
class Field;
class Action;

using Coord = Coordinate;

class Humanoid {
protected:
   Action* action;
   Coord coord;
   bool alive;
   Coordinate move(Field &field);
   Coordinate track(Field &field, Humanoid *target, int n);
   bool targeted;
public:
   Humanoid(const Coord &coord);

   int distanceTo(Humanoid *o);

   virtual ~Humanoid();

   void move(const Coord& newPlace);
   const Coord& getPos();

   virtual void setAction(Field &field) = 0;
   virtual void executeAction(Field &field) final;
   bool isAlive() const;
   virtual void kill();

   bool isTargeted() const;
   void setTargeted(bool targeted);
};


#endif //L4_HUMANOID_H
