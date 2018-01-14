#ifndef __POINT_H__
#define __POINT_H__

#include <iostream>

class Point {
private:
  int x;
  int y;

public:
  Point() {
  }
  Point(int x, int y);
  int getX();
  int getY();
  void setX(int x);
  void setY(int y);
  friend std::ostream &operator<<(std::ostream &os, const Point &point);
};

#endif // __POINT_H__
