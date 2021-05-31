#ifndef L4_VAMPIRE_H
#define L4_VAMPIRE_H


#include "Humanoid.h"

class Vampire : public Humanoid {
public:
   /**
    * @param coord position de départ de l'humanoïde
    */
   explicit Vampire(const Coord &coord);

   virtual ~Vampire();

   /**
    * attribuer une action au vampire
    * les vampires peuvent se déplacer en traquant des humains, tuer des humains
    * et optionnellement le transformer en vampire, ou simplement ne rien faire
    * @param field champs sur lequel se déroule l'action
    */
   void setAction(Field &field) override;
   
};


#endif //L4_VAMPIRE_H
