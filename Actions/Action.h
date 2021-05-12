
#ifndef L4_ACTION_H
#define L4_ACTION_H


#include "../Field.h"

class Action {
public:
   virtual void execute(const Field& field) = 0;
};


#endif //L4_ACTION_H
