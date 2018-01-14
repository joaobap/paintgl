#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "object.h"
#include "point.h"
#include "tool.h"

class Circle : public AbstractObject {
private:
  Point center;
  int radius;
  Color color;
  Tool tool;
  bool isTool;
  bool isEmpty;

public:
  Circle() {
  }
  Circle(Point a, int radius, Color color);
  Circle(Point a, int radius, Color color, bool isEmpty);
  Circle(Point a, int radius, Color color, Tool tool);
  Circle(Point a, int radius, Color color, Tool tool, bool isEmpty);
  ~Circle();
  void draw();
  void drawEmpty();
  void drawFilled();
  void redraw();
  void moveObject(GLint x, GLint y);
  Color getColor();
  void setColor(Color color);
  virtual Tool getTool();
  Point getCenter();
  void setCenter(Point center);
  void setRadius(int radius);
  bool getIsTool();
  bool getIsEmpty();
  bool insideObject(GLint x, GLint y);
};

#endif