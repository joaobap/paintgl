#ifndef __WINDOW_H__
#define __WINDOW_H__

#include <memory>
#include <vector>

#include "object.h"
#include "quadrilateral.h"
#include "tool.h"

class Window {
public:
  int HEIGHT = 800; // Window height
  int WIDTH = 800;  // Window width

private:
  std::vector<std::unique_ptr<AbstractObject>> objects; // Drawn objects
  std::vector<std::unique_ptr<AbstractObject>>
      pallete;                                        // Color pallete objects;
  std::vector<std::unique_ptr<AbstractObject>> tools; // Toolbar objects

  int palleteHeight = 100;
  int palleteObjectOffset = 10;
  int palleteObjectSize = 25;
  int palleteColorStart = HEIGHT - palleteObjectOffset;
  int palleteToolStart = HEIGHT - palleteObjectSize - palleteObjectOffset * 3;

  Color currentColor;
  Tool currentTool;
  Quadrilateral background;
  Quadrilateral selectedColor;
  Quadrilateral outlineSelectedTool;
  AbstractObject *selectedObject;

  bool drawing = false;
  bool moving = false;
  int moveX;
  int moveY;

  void initPallete();

public:
  Window();
  void init();
  void changeSize(int height, int width);

  // glutEvent handlers
  void display();
  void mouseEvent(GLint button, GLint state, GLint x, GLint y);
  void moveActiveMouseEvent(GLint x, GLint y);
  void movePassiveMouseEvent(GLint x, GLint y);
  void keyboardEvent(unsigned char key, int x, int y);
  bool insideObject(GLint x, GLint y);
  bool insideToolbar(GLint x, GLint y);
};

#endif // __WINDOW_H__
