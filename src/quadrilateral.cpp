// comment all this crap if you're using
// an OS that doesnt suck

#define NOMINMAX // windows being windows

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <windows.h>
#endif

// till this

#include "quadrilateral.h"
#include <algorithm>
#include <iostream>

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d, Color color)
    : a(a), b(b), c(c), d(d), color(color), isTool(false), isEmpty(false) {
}

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d, Color color,
                             bool isEmpty)
    : a(a), b(b), c(c), d(d), color(color), isTool(false), isEmpty(isEmpty) {
}

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d, Color color,
                             Tool tool)
    : a(a), b(b), c(c), d(d), color(color), tool(tool), isTool(true),
      isEmpty(false) {
}

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d, Color color,
                             Tool tool, bool isEmpty)
    : a(a), b(b), c(c), d(d), color(color), tool(tool), isTool(true),
      isEmpty(isEmpty) {
}

Quadrilateral::~Quadrilateral() {
}

void Quadrilateral::draw() {
  if (isEmpty) {
    glBegin(GL_LINE_LOOP);
  } else {
    glBegin(GL_POLYGON);
  }
  color.glColor();

  glVertex2i(a.getX(), a.getY());
  glVertex2i(b.getX(), b.getY());
  glVertex2i(c.getX(), c.getY());
  glVertex2i(d.getX(), d.getY());

  glEnd();
  glFlush();
}

void Quadrilateral::redraw() {
}

void Quadrilateral::moveObject(GLint x, GLint y) {
  a.setX(a.getX() + x);
  a.setY(a.getY() + y);
  b.setX(b.getX() + x);
  b.setY(b.getY() + y);
  c.setX(c.getX() + x);
  c.setY(c.getY() + y);
  d.setX(d.getX() + x);
  d.setY(d.getY() + y);
}

Color Quadrilateral::getColor() {
  return color;
}

void Quadrilateral::setColor(Color color) {
  this->color = color;
}

Tool Quadrilateral::getTool() {
  return tool;
}

void Quadrilateral::setA(Point a) {
  this->a = a;
}

void Quadrilateral::setB(Point b) {
  this->b = b;
}

void Quadrilateral::setC(Point c) {
  this->c = c;
}

void Quadrilateral::setD(Point d) {
  this->d = d;
}

Point Quadrilateral::getA() {
  return a;
}

Point Quadrilateral::getB() {
  return b;
}

Point Quadrilateral::getC() {
  return c;
}

Point Quadrilateral::getD() {
  return d;
}

bool Quadrilateral::getIsTool() {
  return isTool;
}

bool Quadrilateral::getIsEmpty() {
  return isEmpty;
}

bool Quadrilateral::insideObject(GLint x, GLint y) {
  int Xmin = std::min({a.getX(), b.getX(), c.getX(), d.getX()});
  int Xmax = std::max({a.getX(), b.getX(), c.getX(), d.getX()});
  int Ymin = std::min({a.getY(), b.getY(), c.getY(), d.getY()});
  int Ymax = std::max({a.getY(), b.getY(), c.getY(), d.getY()});

  return (x >= Xmin && x <= Xmax && y >= Ymin && y <= Ymax);
}
