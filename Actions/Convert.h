#ifndef L4_CONVERT_H
#define L4_CONVERT_H

#include "Kill.h"

/**
 *
 */
class Convert : public Kill {
public:
   /**
    * @param h humanoide à convertir
    */
   explicit Convert(Humanoid *h);

   /**
    * exécute l'action sur un champs donné
    * @param field champs sur lequel exécuter l'action
    */
   void execute(Field &field) override;
};

#endif //L4_CONVERT_H
