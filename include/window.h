#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>
#include <vector>

#include "object.h"

class Window {
private:
	std::vector<std::unique_ptr<AbstractObject>> objects; // Drawn objects
	std::vector<std::unique_ptr<AbstractObject>> tools;   // Toolbar objects
	std::vector<std::unique_ptr<AbstractObject>> pallete; // Colour pallete objects

public:
	int HEIGHT = 800; // Window height
	int WIDTH = 800;  // Window width
	
	Window();
	void init();
	void changeSize(int height, int width);

	// glutEvent handlers
	void display();
	void mouseEvent(GLint button, GLint state, GLint x, GLint y);
	void moveActiveMouseEvent(GLint x, GLint y);
	void movePassiveMouseEvent(GLint x, GLint y);
	void keyboardEvent(unsigned char key, int x, int y);

};

#endif // __WINDOW_H__
