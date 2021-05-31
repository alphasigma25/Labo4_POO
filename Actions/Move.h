#ifndef L4_MOVE_H
#define L4_MOVE_H

#include "Action.h"
#include "../Humanoids/Human.h"
#include "../Utils/Coordinate.h"

class Move : public Action {
   using Coord = Coordinate;
   Coord dest;
public:
   /**
    * effectue le déplacement d'un humanoïde
    * @param h humanoide à déplacer
    * @param dest destination
    */
   Move(Humanoid *h, const Coord &dest);

   /**
    * exécute l'action sur un champs donné
    * @param field champs sur lequel exécuter l'action
    */
   void execute(Field &field) override;
};

#endif //L4_MOVE_H
