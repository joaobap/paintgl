#ifdef __APPLE__
 #include <GLUT/glut.h>
#elif WIN32
 #include <GL/glut.h>
#endif

#include "quadrilateral.h"

Quadrilateral::Quadrilateral(Point a, Point b, Point c, Point d, Color color)
	: a(a), b(b), c(c), d(d), color(color) {}

void Quadrilateral::draw() {
	glBegin(GL_POLYGON);
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


