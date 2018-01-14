#ifndef __COLOUR_H__
#define __COLOUR_H__

#include <iostream>

class Color {
private:
  float r;
  float g;
  float b;

public:
  Color() {
  }
  Color(float r, float g, float b);
  float getR();
  float getG();
  float getB();
  void glColor();
  friend std::ostream &operator<<(std::ostream &os, const Color &color);
};

#endif // __COLOUR_H__
