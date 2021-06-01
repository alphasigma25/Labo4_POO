#ifndef L4_FIELD_H
#define L4_FIELD_H

#include <list>
#include <typeinfo>
#include <cstdlib>
#include "Humanoids/Humanoid.h"

class Humanoid;

/**
 * classe field permettant de simuler un champ avec des humanoides
 */
class Field {
   std::list<Humanoid*> humanoids; // tous les humanoïdes de la simulation
   int turn; // Le tour actuel de la simulation

   bool buffyVictory; // true si Buffy a gagné (pas de vampires et au moins un humain vivant)
   const size_t dimensions[2]; // dimensions du champ

public:
   /**
    * @param height hauteur du champ
    * @param width largeur du champ
    * @param nbHumans nombre d'humains
    * @param nbVampires nombre de vampires
    */
   Field(size_t height, size_t width, size_t nbHumans, size_t nbVampires);
   ~Field();

   /**
    * passe au tour suivant
    * @return le numéro du tour
    */
   int nextTurn();

   /**
    * getteurs pour la hauteur, la largeur et la liste des humanoides
    */
   int getHeight() const;
   int getWidth() const;
   const std::list<Humanoid *> &getPopulation() const;

   /**
    * @return vrais si la partie est toujours en cours (il reste des humains ou
    * des vampires)
    */
   bool stillRunning();

   /**
    * calcule quel est l'humanoïde d'un type donné le plus proche de l'humanoïde
    * fourni en paramètre
    * @param h humanoide
    * @param ti type de l'humanoide recherché
    * @return l'humanoide le plus proche trouvé
    */
   Humanoid * closestTo(Humanoid* h, const std::type_info& ti);

   /**
    * ajout d'un humanoide au champ
    * @param h humanoide à rajouter
    */
   void addHumanoid(Humanoid* h);

   /**
    * @return vrai s'il n'y a plus de vampires
    */
   bool isBuffyVictory() const;
};


#endif //L4_FIELD_H
