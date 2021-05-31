#ifndef L4_TERMINALDISPLAY_H
#define L4_TERMINALDISPLAY_H


#include "../Field.h"
#include <string>
#include <vector>

class TerminalDisplay {
   Field const *f;
   std::vector<std::string> tab;

public:
   /**
    * affichage sur terminal d'un champs
    * @param f champs à afficher
    */
   explicit TerminalDisplay(Field *f);

   /**
    * afficher le champs
    */
   void display();

};


#endif //L4_TERMINALDISPLAY_H
