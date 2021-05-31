#ifndef L4_HUMAN_H
#define L4_HUMAN_H

#include "Humanoid.h"

class Human : public Humanoid {
public:
   /**
    * @param coord position de départ de l'humanoïde
    */
   explicit Human(const Coord &coord);

   /**
    * attribuer une action à l'humain
    * les humains ne peuvent que se déplacer
    * @param field champs sur lequel se déroule l'action
    */
   void setAction(Field &field) override;

   virtual ~Human();
};

#endif //L4_HUMAN_H
