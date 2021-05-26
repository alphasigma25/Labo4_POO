#ifndef L4_VAMPIRE_H
#define L4_VAMPIRE_H


#include "Humanoid.h"

class Vampire : public Humanoid {
public:
   Vampire(const Coord &coord);

   char symbol() const override;

   void setAction(Field &field) override;
   
};


#endif //L4_VAMPIRE_H
