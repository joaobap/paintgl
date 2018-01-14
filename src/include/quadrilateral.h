#ifndef __QUADRILATERAL_H__
#define __QUADRILATERAL_H__

#include "object.h"
#include "point.h"
#include "tool.h"

class Quadrilateral : public AbstractObject {
private:
  Point a;
  Point b;
  Point c;
  Point d;

  Color color;
  Tool tool;
  bool isTool;
  bool isEmpty;

public:
  Quadrilateral() {
  }
  Quadrilateral(Point a, Point b, Point c, Point d, Color color);
  Quadrilateral(Point a, Point b, Point c, Point d, Color color, bool isEmpty);
  Quadrilateral(Point a, Point b, Point c, Point d, Color color, Tool tool);
  Quadrilateral(Point a, Point b, Point c, Point d, Color color, Tool tool,
                bool isEmpty);
  virtual ~Quadrilateral();
  void draw();
  void redraw();
  void moveObject(GLint x, GLint y);
  Color getColor();
  void setColor(Color color);
  Tool getTool();
  void setA(Point a);
  void setB(Point b);
  void setC(Point c);
  void setD(Point d);
  Point getA();
  Point getB();
  Point getC();
  Point getD();
  bool getIsTool();
  bool getIsEmpty();
  bool insideObject(GLint x, GLint y);
};

#endif // __QUADRILATERAL_H__
