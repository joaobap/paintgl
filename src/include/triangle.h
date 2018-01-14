#ifndef __TRIANGLE_H__
#define __TRIANGLE_H__

#include "object.h"
#include "point.h"
#include "tool.h"

class Triangle : public AbstractObject {
private:
  Point a;
  Point b;
  Point c;
  Color color;
  Tool tool;
  bool isTool;
  bool isEmpty;

public:
  Triangle() {
  }
  Triangle(Point a, Point b, Point c, Color color);
  Triangle(Point a, Point b, Point c, Color color, bool isEmpty);
  Triangle(Point a, Point b, Point c, Color color, Tool tool);
  Triangle(Point a, Point b, Point c, Color color, Tool tool, bool isEmpty);
  ~Triangle();
  void draw();
  void redraw();
  void moveObject(GLint x, GLint y);
  Color getColor();
  void setColor(Color color);
  Tool getTool();
  void setA(Point a);
  void setB(Point b);
  void setC(Point c);
  Point getA();
  Point getB();
  Point getC();
  bool getIsTool();
  bool getIsEmpty();
  bool insideObject(GLint x, GLint y);
};

#endif // __TRIANGLE_H__