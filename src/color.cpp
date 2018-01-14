#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <windows.h>
#endif

/*
#ifdef __APPLE__
#include <GLUT/glut.h>
#elif WIN32
#include <GL/glut.h>
#endif
*/

#include "color.h"
#include <iostream>

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {
}

float Color::getR() {
  return r;
}

float Color::getG() {
  return g;
}

float Color::getB() {
  return b;
}

void Color::glColor() {
  glColor3f(r, g, b);
}

std::ostream &operator<<(std::ostream &os, const Color &color) {
  os << "(R, G, B) = (" << color.r << ", " << color.g << ", " << color.b << ")";
  return os;
}
