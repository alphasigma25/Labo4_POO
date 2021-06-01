#ifndef L4_HUMANOID_H
#define L4_HUMANOID_H


#include "../Field.h"
#include "../Actions/Action.h"
#include "../Utils/Coordinate.h"
#include <valarray>
class Field;
class Action;

using Coord = Coordinate;
/**
 * Classe représentant les acteurs de la simulation
 */
class Humanoid {
protected:
   Action* action; // L'action de l'humanoïde pour le tour courant
   Coord coord; // Là où se trouve l'humanoïde
   bool alive; // indique si l'humanoïde est vivant
   bool targeted; // indique si l'humanoïde a été ciblé (par des vampires pour être tué)

   /**
    * calcule les déplacements d'un humanoide dans un champs donné
    * @param field champs sur lequel on déplace l'humanoïde
    * @return nouvelle position
    */
   Coordinate move(Field &field);

   /**
    * calcule les déplacement d'un humanoïde lorsqu'il traque une cible sur un
    * champs donné.
    * @param field champs sur lequel on déplace l'humanoïde
    * @param target cible à traquer
    * @param n distance de déplacement
    * @return nouvelle position
    */
   Coordinate track(Field &field, Humanoid *target, int n);

public:
   /**
    * @param coord position de départ de l'humanoïde
    */
   Humanoid(const Coord &coord);

   /**
    * calcule la distance entre deux humanoides.
    * La métrique pour la calcul de la distance est max(x,y)
    * @param o autre humanoide
    * @return distance
    */
   int distanceTo(Humanoid *o);

   virtual ~Humanoid();

   /**
    * permet de déplacer un humanoïde à une place donnée
    * @param newPlace nouvelle place
    */
   void move(const Coord& newPlace);
   const Coord& getPos();

   /**
    * attribue une action à l'humanoïde
    * @param field champs sur lequel se déroule l'action
    */
   virtual void setAction(Field &field) = 0;

   /**
    * exécute l'action attribuée à l'humanoïde s'il en possède une
    * @param field champs sur lequel se déroule l'action
    */
   virtual void executeAction(Field &field) final;

   /**
    * @return vrai si l'humanoide est en vie
    */
   bool isAlive() const;

   /**
    * tue l'humanoïde
    */
   virtual void kill();

   /**
    * permet de savoir si un humanoïde a été ciblé par un autre
    * @return
    */
   bool isTargeted() const;

   /**
    * permet d'indiqué qu'un humanoïde a été ciblé
    * @param targeted
    */
   void setTargeted(bool targeted);
};


#endif //L4_HUMANOID_H
