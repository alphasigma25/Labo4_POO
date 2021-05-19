#include "Kill.h"

Kill::Kill(Humanoid *h) : Action(h){}

void Kill::execute(Field &field) {
   h->kill();
}