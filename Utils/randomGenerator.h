//
// Created by AnneSo on 01.06.2021.
//

#ifndef L4_RANDOMGENERATOR_H
#define L4_RANDOMGENERATOR_H

/**
 * Cette classe représente un générateur de nombres aléatoires
 */
class randomGenerator {

   static randomGenerator rg;

public :
   /**
    * crée un générateur d'entiers aléatoires
    */
   randomGenerator();

   /**
    * @param min
    * @param max
    * @return une valeur aléatoire comprise entre min et max
    */
   int getRand(int min, int max);

   /**
    * @return instance du générateur
    */
   static randomGenerator& getGenerator();

};

#endif //L4_RANDOMGENERATOR_H
