//
// Created by AnneSo on 01.06.2021.
//

#include "randomGenerator.h"

#include <ctime>
#include <cstdlib>

using namespace std;

randomGenerator::randomGenerator() {
   srand(time(NULL));
}

int randomGenerator::getRand(int min, int max) {
   return rand() % (max - min + 1) + min ;
}

randomGenerator &randomGenerator::getGenerator() {
   return rg;
}

randomGenerator randomGenerator::rg = randomGenerator();