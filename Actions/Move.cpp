#include "Move.h"

using namespace std;
Move::Move(Humanoid &h, const Coord& dest) : Action(h), dest(dest){}

void Move::execute(Field &field) {
   find(field.getPopulation().begin(), field.getPopulation().end())
}


