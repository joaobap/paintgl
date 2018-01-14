#ifndef __PALLETE_H__
#define __PALLETE_H__

#include "color.h"
#include "quadrilateral.h"

class Pallete {
private:
  Quadrilateral background;
  Color color;

public:
  virtual void draw();
  virtual void redraw();
};

#endif // __PALLETE_H__
