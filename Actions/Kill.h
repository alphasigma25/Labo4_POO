#ifndef L4_KILL_H
#define L4_KILL_H


#include "Action.h"

class Kill : public Action {
public:
   void execute(Field &field) override;
   explicit Kill(Humanoid *h);
};


#endif //L4_KILL_H
