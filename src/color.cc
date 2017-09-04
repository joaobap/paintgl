#ifdef __APPLE__
 #include <GLUT/glut.h>
#elif WIN32
 #include <GL/glut.h>
#endif


#include "color.h"

Color::Color(float r, float g, float b) : r(r), g(g), b(b) {}

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
