#ifndef L4_ACTION_H
#define L4_ACTION_H

#include "../Field.h"
#include "../Humanoids/Humanoid.h"

class Humanoid;

class Field;

/**
 * classe symbolisant l'action qu'un humanoïde peut effectuer
 */
class Action {
protected:
   Humanoid *h; //L'humanoïde qui va subir l'action
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
