#ifndef L4_HUMAN_H
#define L4_HUMAN_H


#include "Humanoid.h"

class Human : public Humanoid {
public:
   char symbol() const override;
};


#endif //L4_HUMAN_H
