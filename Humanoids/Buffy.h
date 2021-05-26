#ifndef L4_BUFFY_H
#define L4_BUFFY_H


#include "Humanoid.h"


class Buffy: public Humanoid {
public:
   Buffy(const Coord &coord);

   void setAction(Field &field) override;

   virtual ~Buffy();

   void kill() override;
};


#endif //L4_BUFFY_H
