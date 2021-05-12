//
// Created by AnneSo on 12.05.2021.
//

#include "TerminalDisplay.h"
#include "../Humanoids/Buffy.h"
#include "../Humanoids/Vampire.h"
#include "../Humanoids/Human.h"
#include <iostream>
#include <typeinfo>

using namespace std;

TerminalDisplay::TerminalDisplay(Field* f)
: f(f), tab(f->getHeight()*f->getWidth(),' ') {}

void TerminalDisplay::display() {
   tab = string(f->getWidth()*f->getHeight(),' ');
   for(Humanoid* it : f->getPopulation()) {
      char type = ' ';
      if(typeid(&it) == typeid(Human)) {
         type = 'h';
      } else if(typeid(&it) == typeid(Vampire)) {
         type = 'v';
      } else if(typeid(&it) == typeid(Buffy)) {
         type = 'B';
      }
      tab[it->getPos()[0]+it->getPos()[1]] = type;
   }

   cout << "+" << string(f->getWidth(),'-') << "+" << endl;
   for(unsigned i = 0; i<f->getHeight(); ++i){
      cout << '|';
      for(unsigned j = 0; j<f->getWidth(); ++j){
         cout << tab[i+j] << endl;
      }
      cout << '|' << endl;
   }
}
