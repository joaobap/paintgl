#ifdef __APPLE__
 #include <GLUT/glut.h>
#elif WIN32
 #include <GL/glut.h>
#endif

#include "window.h"

static auto window = Window();

// Used for glutDisplayFunc as wrapper for method in Window object.
// Display callback function for the current window.
void display() {
	window.display();
}

// Used for glutMouseFunc as wrapper for method in Window object.
// Mouse callback event function for simple mouse clicks.
void mouseEvent(GLint button, GLint state, GLint x, GLint y) {
	window.mouseEvent(button, state, x, y);
}

// Used for glutMotionFunc as wrapper for method in Window object.
// Mouse movement callback for events when the mouse has a button clicked and
// it is moving at the same time.
void moveActiveMouseEvent(GLint x, GLint y) {
	window.moveActiveMouseEvent(x, y);
}

// Used for glutPassiveMotionFunc as wrapper for method in Window object.
void movePassiveMouseEvent(GLint x, GLint y) {
	window.movePassiveMouseEvent(x, y);
}


// Used for glutKeyboardFunc as wrapper for method in Window object.
// Keyboard click event function.
void keyboardEvent(unsigned char key, int x, int y) {
	window.keyboardEvent(key, x, y);
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(window.HEIGHT, window.WIDTH);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("PaintGL");

	glutDisplayFunc(display);
	glutMouseFunc(mouseEvent);
	glutMotionFunc(moveActiveMouseEvent);
	glutPassiveMotionFunc(movePassiveMouseEvent);
	glutKeyboardFunc(keyboardEvent);

	window.init();
	glutMainLoop();
}
