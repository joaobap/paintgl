#include "point.h"

Point::Point(int x, int y) : x(x), y(y) {
}

int Point::getX() {
  return x;
}

int Point::getY() {
  return y;
}

void Point::setX(int x) {
  this->x = x;
}

void Point::setY(int y) {
  this->y = y;
}

std::ostream &operator<<(std::ostream &os, const Point &point) {
  os << "(" << point.x << ", " << point.y << ")";

  return os;
}