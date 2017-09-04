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

	initPallete();
	
	for (auto &o : objects) {
		o.get()->draw();
	}
}

void Window::initPallete() {
	// Background
	auto bg = std::make_unique<Quadrilateral>(
			Point(0, HEIGHT-palleteHeight),
			Point(0, HEIGHT),
			Point(WIDTH, HEIGHT),
			Point(WIDTH, HEIGHT-palleteHeight),
			Color(0.9, 0.9, 0.9)
	);

	objects.push_back(std::move(bg));

	// Color pallete
	auto red = std::make_unique<Quadrilateral>(
		Point(palleteObjectOffset, palleteColorStart),
		Point(palleteObjectOffset + palleteObjectSize, palleteColorStart),
		Point(palleteObjectOffset + palleteObjectSize, palleteColorStart - palleteObjectSize),
		Point(palleteObjectOffset, palleteColorStart - palleteObjectSize),
		Color(1.0, 0.0, 0.0)
	);

	auto green = std::make_unique<Quadrilateral>(
		Point(palleteObjectOffset * 2 + palleteObjectSize, palleteColorStart),
		Point(palleteObjectOffset * 2 + palleteObjectSize * 2, palleteColorStart),
		Point(palleteObjectOffset * 2 + palleteObjectSize * 2, palleteColorStart - palleteObjectSize),
		Point(palleteObjectOffset * 2 + palleteObjectSize, palleteColorStart - palleteObjectSize),
		Color(0.0, 1.0, 0.0)
	);

	auto blue = std::make_unique<Quadrilateral>(
		Point(palleteObjectOffset * 3 + palleteObjectSize * 2, palleteColorStart),
		Point(palleteObjectOffset * 3 + palleteObjectSize * 3, palleteColorStart),
		Point(palleteObjectOffset * 3 + palleteObjectSize * 3, palleteColorStart - palleteObjectSize),
		Point(palleteObjectOffset * 3 + palleteObjectSize * 2, palleteColorStart - palleteObjectSize),
		Color(0.0, 0.0, 1.0)
	);


	objects.push_back(std::move(red));
	objects.push_back(std::move(green));
	objects.push_back(std::move(blue));
	
	// Tools
	auto square = std::make_unique<Quadrilateral>(
		Point(palleteObjectOffset, palleteToolStart),
		Point(palleteObjectOffset + palleteObjectSize, palleteToolStart),
		Point(palleteObjectOffset + palleteObjectSize, palleteToolStart - palleteObjectSize),
		Point(palleteObjectOffset, palleteToolStart - palleteObjectSize),
		Color(1.0, 1.0, 1.0)
	);

	auto circle = std::make_unique<Quadrilateral>(
		Point(palleteObjectOffset * 2 + palleteObjectSize, palleteToolStart),
		Point(palleteObjectOffset * 2 + palleteObjectSize * 2, palleteToolStart),
		Point(palleteObjectOffset * 2 + palleteObjectSize * 2, palleteToolStart - palleteObjectSize),
		Point(palleteObjectOffset * 2 + palleteObjectSize, palleteToolStart - palleteObjectSize),
		Color(1.0, 1.0, 1.0)
	);

	auto triangle = std::make_unique<Quadrilateral>(
		Point(palleteObjectOffset * 3 + palleteObjectSize * 2, palleteToolStart),
		Point(palleteObjectOffset * 3 + palleteObjectSize * 3, palleteToolStart),
		Point(palleteObjectOffset * 3 + palleteObjectSize * 3, palleteToolStart - palleteObjectSize),
		Point(palleteObjectOffset * 3 + palleteObjectSize * 2, palleteToolStart - palleteObjectSize),
		Color(1.0, 1.0, 1.0)
	);

	objects.push_back(std::move(square));
	objects.push_back(std::move(circle));
	objects.push_back(std::move(triangle));
}

void Window::mouseEvent(GLint button, GLint state, GLint x, GLint y) {

}

void Window::moveActiveMouseEvent(GLint x, GLint y) {

}

void Window::movePassiveMouseEvent(GLint x, GLint y) {

}

void Window::keyboardEvent(unsigned char key, int x, int y) {

}

