#ifndef __LINE_H__
#define __LINE_H__

#include "object.h"
#include "point.h"
#include "tool.h"

class Line : public AbstractObject {
private:
  Point a;
  Point b;
  Color color;
  Tool tool;

public:
  Line();
  Line(Point a, Point b, Color color);
  Line(Point a, Point b, Color color, Tool tool);
  Tool getTool();
  ~Line();
  void draw();
  void redraw();
  void moveObject(GLint x, GLint y);
  bool insideObject(GLint x, GLint y);
  void setA(Point a);
  void setB(Point b);
  friend std::ostream &operator<<(std::ostream &os, const Line &line);
};

#endif