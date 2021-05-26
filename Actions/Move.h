#ifndef L4_MOVE_H
#define L4_MOVE_H


#include "Action.h"
#include "../Humanoids/Human.h"
#include "../Utils/Coordinate.h"

class Move : public Action {
   using Coord = Coordinate;
   Coord dest;
public:
   Move(Humanoid *h, const Coord &dest);

   void execute(Field &field);
};


#endif //L4_MOVE_H
