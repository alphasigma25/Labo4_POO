#ifndef L4_CONVERT_H
#define L4_CONVERT_H


#include "Kill.h"

class Convert : public Kill {
public:
   explicit Convert(Humanoid* h);
   void execute(Field &field) override;
};


#endif //L4_CONVERT_H
