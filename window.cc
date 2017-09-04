#ifdef __APPLE__
 #include <GLUT/glut.h>
#elif WIN32
 #include <GL/glut.h>
#endif

#include <memory>

#include "window.h"
#include "quadrilateral.h"

Window::Window() {
}

void Window::init() {
	glClearColor(1.0, 1.0, 1.0, 0.0);
	glEnable(GL_COLOR_MATERIAL);
	glLogicOp(GL_COPY);
	gluOrtho2D(0, HEIGHT, 0, WIDTH);

}

void Window::display() {
	glClear(GL_COLOR_BUFFER_BIT);

	Point a = Point(0, 0);
	Point b = Point(0, 100);
	Point c = Point(100, 100);
	Point d = Point(100, 0);
	Color color = Color(200, 0, 0);

	auto quad = std::make_shared<Quadrilateral>(a, b, c, d, color);
	quad.get()->draw();
}

void Window::mouseEvent(GLint button, GLint state, GLint x, GLint y) {

}

void Window::moveActiveMouseEvent(GLint x, GLint y) {

}

void Window::movePassiveMouseEvent(GLint x, GLint y) {

}

void Window::keyboardEvent(unsigned char key, int x, int y) {

}

