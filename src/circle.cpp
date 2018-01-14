#include "circle.h"

#include <cmath>

#define PI 3.1415926f

Circle::Circle(Point center, int radius, Color color)
    : center(center), radius(radius), color(color), isTool(false),
      isEmpty(false) {
}

Circle::Circle(Point center, int radius, Color color, bool isEmpty)
    : center(center), radius(radius), color(color), tool(tool), isTool(false),
      isEmpty(isEmpty) {
}

Circle::Circle(Point center, int radius, Color color, Tool tool)
    : center(center), radius(radius), color(color), tool(tool), isTool(true),
      isEmpty(false) {
}

Circle::Circle(Point center, int radius, Color color, Tool tool, bool isEmpty)
    : center(center), radius(radius), color(color), tool(tool), isTool(true),
      isEmpty(isEmpty) {
}

Circle::~Circle() {
}

void Circle::draw() {
  if (isEmpty) {
    drawEmpty();
  } else {
    drawFilled();
  }
}

void Circle::drawEmpty() {
  int lineAmount = 100;
  GLfloat twicePi = 2.0f * PI;

  glBegin(GL_LINE_LOOP);
  color.glColor();
  for (int i = 0; i <= lineAmount; i++) {
    glVertex2f(center.getX() + (radius * cos(i * twicePi / lineAmount)),
               center.getY() + (radius * sin(i * twicePi / lineAmount)));
  }
  glEnd();
  glFlush();
}

void Circle::drawFilled() {
  int i;
  int triangleAmount = 40;
  GLfloat twicePi = 2.0f * PI;

  glBegin(GL_TRIANGLE_FAN);
  color.glColor();
  glVertex2f(center.getX(), center.getY());
  for (i = 0; i <= triangleAmount; i++) {
    glVertex2f(center.getX() + (radius * cos(i * twicePi / triangleAmount)),
               center.getY() + (radius * sin(i * twicePi / triangleAmount)));
  }
  glEnd();
  glFlush();
}

void Circle::redraw() {
}

void Circle::moveObject(GLint x, GLint y) {
  center.setX(center.getX() + x);
  center.setY(center.getY() + y);
}

Point Circle::getCenter() {
  return this->center;
}

void Circle::setCenter(Point a) {
  this->center = center;
}

void Circle::setRadius(int radius) {
  this->radius = radius;
}

Color Circle::getColor() {
  return color;
}

void Circle::setColor(Color color) {
  color = color;
}

Tool Circle::getTool() {
  return tool;
}

bool Circle::getIsTool() {
  return isTool;
}

bool Circle::getIsEmpty() {
  return isEmpty;
}

bool Circle::insideObject(GLint x, GLint y) {
  // a point belongs to a circle if its distance to the center
  // is less or equal to the radius of the circle
  return std::sqrt(std::pow(x - center.getX(), 2) +
                   std::pow(y - center.getY(), 2)) <= radius;
}