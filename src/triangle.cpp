#include "triangle.h"

Triangle::Triangle(Point a, Point b, Point c, Color color)
    : a(a), b(b), c(c), color(color), isTool(false), isEmpty(false) {
}

Triangle::Triangle(Point a, Point b, Point c, Color color, bool isEmpty)
    : a(a), b(b), c(c), color(color), tool(tool), isTool(false),
      isEmpty(isEmpty) {
}

Triangle::Triangle(Point a, Point b, Point c, Color color, Tool tool)
    : a(a), b(b), c(c), color(color), tool(tool), isTool(true), isEmpty(false) {
}

Triangle::Triangle(Point a, Point b, Point c, Color color, Tool tool,
                   bool isEmpty)
    : a(a), b(b), c(c), color(color), tool(tool), isTool(true),
      isEmpty(isEmpty) {
}

Triangle::~Triangle() {
}

void Triangle::draw() {
  if (isEmpty) {
    glBegin(GL_LINE_LOOP);
  } else {
    glBegin(GL_TRIANGLES);
  }
  color.glColor();

  glVertex2i(a.getX(), a.getY());
  glVertex2i(b.getX(), b.getY());
  glVertex2i(c.getX(), c.getY());

  glEnd();
  glFlush();
}

void Triangle::redraw() {
}

void Triangle::moveObject(GLint x, GLint y) {
  a.setX(a.getX() + x);
  a.setY(a.getY() + y);
  b.setX(b.getX() + x);
  b.setY(b.getY() + y);
  c.setX(c.getX() + x);
  c.setY(c.getY() + y);
}

Color Triangle::getColor() {
  return color;
}

void Triangle::setColor(Color color) {
  color = color;
}

Tool Triangle::getTool() {
  return tool;
}

void Triangle::setA(Point a) {
  this->a = a;
}

void Triangle::setB(Point b) {
  this->b = b;
}

void Triangle::setC(Point c) {
  this->c = c;
}

Point Triangle::getA() {
  return a;
}

Point Triangle::getB() {
  return b;
}

Point Triangle::getC() {
  return c;
}

bool Triangle::getIsTool() {
  return isTool;
}

bool Triangle::getIsEmpty() {
  return isEmpty;
}

// Checking on which side of the half-plane
// created by the edges the point is.
// Check for more info:
// https://stackoverflow.com/a/2049593/4332164
int sign(Point a, Point b, Point c) {
  return (a.getX() - c.getX()) * (b.getY() - c.getY()) -
         (b.getX() - c.getX()) * (a.getY() - c.getY());
}

bool Triangle::insideObject(GLint x, GLint y) {
  auto b1 = sign(Point(x, y), a, b) < 0;
  auto b2 = sign(Point(x, y), b, c) < 0;
  auto b3 = sign(Point(x, y), c, a) < 0;

  return ((b1 == b2) && (b2 == b3));
}
