//
// Created by AnneSo on 26.05.2021.
//

#ifndef L4_COORDINATE_H
#define L4_COORDINATE_H


class Coordinate {
int x;
int y;

public:
   Coordinate(int x, int y);

   Coordinate operator+(const Coordinate& other) const;
   Coordinate operator+(int) const;
   Coordinate operator-(const Coordinate& other) const;

   int getX() const;

   void setX(int x);

   int getY() const;

   void setY(int y);
};


#endif //L4_COORDINATE_H
