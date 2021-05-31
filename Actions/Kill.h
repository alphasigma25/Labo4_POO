#ifndef L4_KILL_H
#define L4_KILL_H

#include "Action.h"

class Kill : public Action {
public:

   /**
    * @param h humanoide à tuer
    */
   explicit Kill(Humanoid *h);

   /**
    * exécute l'action sur un champs donné
    * @param field champs sur lequel exécuter l'action
    */
   void execute(Field &field) override;
};

#endif //L4_KILL_H
