#ifndef L4_TERMINALDISPLAY_H
#define L4_TERMINALDISPLAY_H


#include "../Field.h"
#include <string>
#include <vector>

/**
 * Classe permettant d'afficher la simulation sur le terminal
 */
class TerminalDisplay {
   Field const *f; //Le field à afficher
   std::vector<std::string> tab; //Le tableau graphique affiché

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
