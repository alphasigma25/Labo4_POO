//
// Created by AnneSo on 19.05.2021.
//

#include "Convert.h"
#include "../Humanoids/Vampire.h"

using namespace std;

void Convert::execute(Field &field) {
   Kill::execute(field);
   field.addHumanoid((Humanoid*) new Vampire(deathCoord));
}

Convert::Convert(Humanoid* h) : Kill(h), deathCoord(h->getPos()){}
