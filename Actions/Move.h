#ifndef L4_MOVE_H
#define L4_MOVE_H


#include "Action.h"

class Move : public Action {
   using Coord = std::valarray<size_t>;
   Coord dest;
public:
   Move(Humanoid &h, const Coord &dest);


   void execute(Field &field);
};


#endif //L4_MOVE_H
