#ifndef L4_BUFFY_H
#define L4_BUFFY_H


#include "Humanoid.h"

/**
 * Classe représentant l'acteur Buffy de la simulation
 */
class Buffy: public Humanoid {
public:
   /**
    * @param coord position de départ de l'humanoïde
    */
   explicit Buffy(const Coord &coord);

   /**
    * attribuer une action à Buffy
    * buffy peut se déplacer en traquant des vampires, tuer un vampire ou se
    * déplacer comme un humain
    * @param field champs sur lequel se déroule l'action
    */
   void setAction(Field &field) override;

   virtual ~Buffy();

   /**
    * Buffy ne peut pas être tué
    */
   void kill() override;
};


#endif //L4_BUFFY_H
