#ifndef L4_HUMAN_H
#define L4_HUMAN_H


#include "Humanoid.h"


class Human : public Humanoid {
public:
   explicit Human(const Coord &coord);

   char symbol() const override;

   void setAction(Field &field) override;

   virtual ~Human();

};


#endif //L4_HUMAN_H
