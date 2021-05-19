
#ifndef L4_ACTION_H
#define L4_ACTION_H


#include "../Field.h"
#include "../Humanoids/Humanoid.h"

class Humanoid;
class Field;

class Action {
protected:
   Humanoid* h;
public:
   explicit Action(Humanoid *h);
   virtual ~Action();
   virtual void execute(Field& field) = 0;

};


#endif //L4_ACTION_H
