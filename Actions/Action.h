
#ifndef L4_ACTION_H
#define L4_ACTION_H


#include "../Field.h"

class Action {
public:
   virtual void execute(Field& field) = 0;
};


#endif //L4_ACTION_H
