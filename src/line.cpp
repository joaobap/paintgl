#include "line.h"
#include "tool.h"

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#include <math.h>
#else
#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <windows.h>
#endif

Line::Line() {
}

Line::Line(Point a, Point b, Color color) : a(a), b(b), color(color) {
}

Line::Line(Point a, Point b, Color color, Tool tool)
    : a(a), b(b), color(color), tool(tool) {
}

Line::~Line() {
}

void Line::draw() {
  glBegin(GL_LINES);
  color.glColor();
  glLineWidth(2.5);
  glVertex2i(a.getX(), a.getY());
  glVertex2i(b.getX(), b.getY());
  glEnd();
  glFlush();
}

void Line::redraw() {
}

void Line::moveObject(GLint x, GLint y) {
  a.setX(a.getX() + x);
  a.setY(a.getY() + y);
  b.setX(b.getX() + x);
  b.setY(b.getY() + y);
}

Tool Line::getTool() {
  return tool;
}

bool Line::insideObject(GLint x, GLint y) {
  // A point belongs to a line if the distance of that point
  // to each of the line's delimiters (in this case, A and B)
  // is equal to the distance between A and B.
  float distA_curr =
      std::sqrt(std::pow(x - a.getX(), 2) + std::pow(y - a.getY(), 2));
  float distB_curr =
      std::sqrt(std::pow(x - b.getX(), 2) + std::pow(y - b.getY(), 2));
  float distA_B = std::sqrt(std::pow(b.getX() - a.getX(), 2) +
                            std::pow(b.getY() - a.getY(), 2));

  // It's given a 1px tolerance.
  if (distA_curr + distB_curr < distA_B + 1) {
    return true;
  }
  return false;
}

void Line::setA(Point a) {
  this->a = a;
}

void Line::setB(Point b) {
  this->b = b;
}

std::ostream &operator<<(std::ostream &os, const Line &line) {
  os << "a: " << line.a << " b: " << line.b << std::endl;
  return os;
}
