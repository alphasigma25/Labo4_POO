#ifndef L4_MOVE_H
#define L4_MOVE_H

#include "Action.h"
#include "../Humanoids/Human.h"
#include "../Utils/Coordinate.h"
/**
 * Action de mouvement d'un humanoïde
 */
class Move : public Action {
   using Coord = Coordinate;
   Coord dest; //Là où l'humanoïde sera bougé
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
