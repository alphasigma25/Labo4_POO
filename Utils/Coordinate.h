#ifndef L4_COORDINATE_H
#define L4_COORDINATE_H

/**
 * Classe représentant une coordonnée 2D
 */
class Coordinate {
   // coordonnées x et y
   int x;
   int y;

public:
   /**
    * Vecteur 2D de coordonnées
    * @param x
    * @param y
    */
   Coordinate(int x, int y);

   /**
    * additionne deux coordonnées (adition vectorielle champs par champs)
    * @param other autre coordonnée
    * @return coordonnée résulat de l'addition
    */
   Coordinate operator+(const Coordinate& other) const;
   /**
    * additionne un entier à chaque composante d'une coordonnée
    * @param int entier
    * @return coordonnée résulat de l'addition
    */
   Coordinate operator+(int) const;

   /**
    * soustrait une coordonnée à la coordonnée courante (adition vectorielle champs par champs)
    * @param other autre coordonnée
    * @return coordonnée résulat de l'addition
    */
   Coordinate operator-(const Coordinate& other) const;

   /**
    * getters et setters pour les champs x et y
    */
   int getX() const;
   void setX(int x);
   int getY() const;
   void setY(int y);
};


#endif //L4_COORDINATE_H
