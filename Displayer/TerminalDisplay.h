//
// Created by AnneSo on 12.05.2021.
//

#ifndef L4_TERMINALDISPLAY_H
#define L4_TERMINALDISPLAY_H


#include "../Field.h"
#include <string>

class TerminalDisplay {
   Field const* f;

   std::string tab;

public:
   explicit TerminalDisplay(Field* f);

   void display();

};


#endif //L4_TERMINALDISPLAY_H
