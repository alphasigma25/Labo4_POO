#ifndef L4_HUMANOID_H
#define L4_HUMANOID_H


#include "../Field.h"
#include "../Actions/Action.h"
#include <valarray>
class Field;

class Humanoid {
protected:
   Action* action;
   Coord coord;
   bool alive;
public:
   Humanoid(const Coord &coord);

   int distanceTo(Humanoid *o);

   virtual ~Humanoid();

   void move(const Coord& newPlace);
   const Coord& getPos();

   virtual char symbol() const = 0;

   virtual void setAction(Field &field) = 0;
   virtual void executeAction(Field &field) final;
   bool isAlive() const;
   virtual void kill();


};


#endif //L4_HUMANOID_H
