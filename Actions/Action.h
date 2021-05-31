#ifndef L4_ACTION_H
#define L4_ACTION_H

#include "../Field.h"
#include "../Humanoids/Humanoid.h"

class Humanoid;

class Field;

/**
 * classe Action
 */
class Action {
protected:
   Humanoid *h;
public:
   /**
    * @param h humanoide qui va exécuter l'action
    */
   explicit Action(Humanoid *h);

   virtual ~Action();

   /**
    * exécute l'action sur un champs donné
    * @param field champs sur lequel exécuter l'action
    */
   virtual void execute(Field &field) = 0;

};

#endif //L4_ACTION_H
