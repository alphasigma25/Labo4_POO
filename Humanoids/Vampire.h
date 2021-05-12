#ifndef L4_VAMPIRE_H
#define L4_VAMPIRE_H


#include "Humanoid.h"

class Vampire : public Humanoid {
public:
   char symbol() const override;
};


#endif //L4_VAMPIRE_H
