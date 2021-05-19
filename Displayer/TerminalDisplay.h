#ifndef L4_TERMINALDISPLAY_H
#define L4_TERMINALDISPLAY_H


#include "../Field.h"
#include <string>
#include <vector>

class TerminalDisplay {
   Field const* f;

   std::vector<std::string> tab;

public:
   explicit TerminalDisplay(Field* f);

   void display();

};


#endif //L4_TERMINALDISPLAY_H
