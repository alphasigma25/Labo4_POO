//
// Created by AnneSo on 01.06.2021.
//

#ifndef L4_RANDOMGENERATOR_H
#define L4_RANDOMGENERATOR_H


class randomGenerator {

   static randomGenerator rg;

public :
   randomGenerator();


   int getRand(int min, int max);

   static randomGenerator& getGenerator();

};

#endif //L4_RANDOMGENERATOR_H
