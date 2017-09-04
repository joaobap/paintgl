#ifdef __APPLE__
 #include <GLUT/glut.h>
#elif WIN32
 #include <GL/glut.h>
#endif


#include "color.h"

Color::Color(int r, int g, int b) : r(r), g(g), b(b) {}

int Color::getR() {
	return r;
}

int Color::getG() {
	return g;
}

int Color::getB() {
	return b;
}

void Color::glColor() {
	glColor3i(r, g, b);
}
