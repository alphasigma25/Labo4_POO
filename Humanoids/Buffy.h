#ifndef L4_BUFFY_H
#define L4_BUFFY_H


#include "Humanoid.h"


class Buffy: public Humanoid {
public:
   Buffy(const Coord &coord);

   char symbol() const override;

   void setAction(Field &field) override;

   void kill() override;
};


#endif //L4_BUFFY_H
