#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <windows.h>
#endif

#include <cmath>
#include <iostream>
#include <memory>

#include "circle.h"
#include "line.h"
#include "quadrilateral.h"
#include "triangle.h"
#include "window.h"

extern int windowID;

#define Q 'q'

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

  // draw first so that the toolbar is always
  // on the front
  for (auto &o : objects) {
    o.get()->draw();
  }

  background.draw();
  selectedColor.setColor(currentColor);
  selectedColor.draw();
  outlineSelectedTool.draw();

  for (auto &p : pallete) {
    p.get()->draw();
  }

  for (auto &t : tools) {
    t.get()->draw();
  }
}

void Window::initPallete() {
  // Background
  background = Quadrilateral(
      Point(0, HEIGHT - palleteHeight), Point(0, HEIGHT), Point(WIDTH, HEIGHT),
      Point(WIDTH, HEIGHT - palleteHeight), Color(0.9, 0.9, 0.9));

  // Color pallete

  auto black = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset, palleteColorStart),
      Point(palleteObjectOffset + palleteObjectSize, palleteColorStart),
      Point(palleteObjectOffset + palleteObjectSize,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset, palleteColorStart - palleteObjectSize),
      Color(0.0, 0.0, 0.0));

  auto grey = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 2 + palleteObjectSize, palleteColorStart),
      Point(palleteObjectOffset * 2 + palleteObjectSize * 2, palleteColorStart),
      Point(palleteObjectOffset * 2 + palleteObjectSize * 2,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 2 + palleteObjectSize,
            palleteColorStart - palleteObjectSize),
      Color(0.4, 0.4, 0.4));

  auto brown = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 3 + palleteObjectSize * 2, palleteColorStart),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 3, palleteColorStart),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 3,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 2,
            palleteColorStart - palleteObjectSize),
      Color(0.4, 0.2, 0.0));

  auto red = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 4 + palleteObjectSize * 3, palleteColorStart),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 4, palleteColorStart),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 4,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 3,
            palleteColorStart - palleteObjectSize),
      Color(1.0, 0.0, 0.0));

  auto orange = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 5 + palleteObjectSize * 4, palleteColorStart),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 5, palleteColorStart),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 5,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 4,
            palleteColorStart - palleteObjectSize),
      Color(1.0, 0.5, 0.0));

  auto yellow = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 6 + palleteObjectSize * 5, palleteColorStart),
      Point(palleteObjectOffset * 6 + palleteObjectSize * 6, palleteColorStart),
      Point(palleteObjectOffset * 6 + palleteObjectSize * 6,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 6 + palleteObjectSize * 5,
            palleteColorStart - palleteObjectSize),
      Color(1.0, 1.0, 0.0));

  auto green = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 7 + palleteObjectSize * 6, palleteColorStart),
      Point(palleteObjectOffset * 7 + palleteObjectSize * 7, palleteColorStart),
      Point(palleteObjectOffset * 7 + palleteObjectSize * 7,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 7 + palleteObjectSize * 6,
            palleteColorStart - palleteObjectSize),
      Color(0.5, 1.0, 0.0));

  auto blue = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 8 + palleteObjectSize * 7, palleteColorStart),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 8, palleteColorStart),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 8,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 7,
            palleteColorStart - palleteObjectSize),
      Color(0.0, 1.0, 1.0));

  auto purple = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8, palleteColorStart),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9, palleteColorStart),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8,
            palleteColorStart - palleteObjectSize),
      Color(0.6, 0.2, 0.99));

  auto pink = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 10 + palleteObjectSize * 9,
            palleteColorStart),
      Point(palleteObjectOffset * 10 + palleteObjectSize * 10,
            palleteColorStart),
      Point(palleteObjectOffset * 10 + palleteObjectSize * 10,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 10 + palleteObjectSize * 9,
            palleteColorStart - palleteObjectSize),
      Color(1.0, 0.0, 0.5));

  auto white = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 11 + palleteObjectSize * 10,
            palleteColorStart),
      Point(palleteObjectOffset * 11 + palleteObjectSize * 11,
            palleteColorStart),
      Point(palleteObjectOffset * 11 + palleteObjectSize * 11,
            palleteColorStart - palleteObjectSize),
      Point(palleteObjectOffset * 11 + palleteObjectSize * 10,
            palleteColorStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0));

  pallete.push_back(std::move(black));
  pallete.push_back(std::move(grey));
  pallete.push_back(std::move(brown));
  pallete.push_back(std::move(red));
  pallete.push_back(std::move(orange));
  pallete.push_back(std::move(yellow));
  pallete.push_back(std::move(green));
  pallete.push_back(std::move(blue));
  pallete.push_back(std::move(purple));
  pallete.push_back(std::move(pink));
  pallete.push_back(std::move(white));

  // Tools
  auto lineTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset, palleteToolStart),
      Point(palleteObjectOffset + palleteObjectSize, palleteToolStart),
      Point(palleteObjectOffset + palleteObjectSize,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset, palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(LINE));

  auto lineIcon = std::make_unique<Line>(
      Point(palleteObjectOffset + palleteObjectSize - 5, palleteToolStart - 5),
      Point(palleteObjectOffset + 5, palleteToolStart - palleteObjectSize + 5),
      Color(0.0, 0.0, 0.0), Tool(LINE));

  auto squareTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 2 + palleteObjectSize, palleteToolStart),
      Point(palleteObjectOffset * 2 + palleteObjectSize * 2, palleteToolStart),
      Point(palleteObjectOffset * 2 + palleteObjectSize * 2,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 2 + palleteObjectSize,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(SQUARE));

  auto squareIcon = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 2 + palleteObjectSize + 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 2 + palleteObjectSize * 2 - 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 2 + palleteObjectSize * 2 - 5,
            (palleteToolStart - palleteObjectSize) + 5),
      Point(palleteObjectOffset * 2 + palleteObjectSize + 5,
            (palleteToolStart - palleteObjectSize) + 5),
      Color(0.0, 0.0, 0.0), Tool(SQUARE));

  auto emptySquareTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 3 + palleteObjectSize * 2, palleteToolStart),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 3, palleteToolStart),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 3,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 2,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(EMPTY_SQUARE));

  auto emptySquareIcon = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 3 + palleteObjectSize * 2 + 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 3 - 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 3 - 5,
            palleteToolStart - palleteObjectSize + 5),
      Point(palleteObjectOffset * 3 + palleteObjectSize * 2 + 5,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.0, 0.0, 0.0), Tool(SQUARE), true);

  auto triangleTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 4 + palleteObjectSize * 3, palleteToolStart),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 4, palleteToolStart),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 4,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 3,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(TRIANGLE));

  auto triangleIcon = std::make_unique<Triangle>(
      Point(palleteObjectOffset * 4 + palleteObjectSize * 3 + 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 4 - 5,
            palleteToolStart - palleteObjectSize + 5),
      Point(palleteObjectOffset * 4 + palleteObjectSize * 3 + 5,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.0, 0.0, 0.0), Tool(TRIANGLE));

  auto emptyTriangleTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 5 + palleteObjectSize * 4, palleteToolStart),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 5, palleteToolStart),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 5,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 4,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(EMPTY_TRIANGLE));

  auto emptyTriangleIcon = std::make_unique<Triangle>(
      Point(palleteObjectOffset * 5 + palleteObjectSize * 4 + 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 5 - 5,
            palleteToolStart - palleteObjectSize + 5),
      Point(palleteObjectOffset * 5 + palleteObjectSize * 4 + 5,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.0, 0.0, 0.0), Tool(EMPTY_TRIANGLE), true);

  auto circleTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 6 + palleteObjectSize * 5, palleteToolStart),
      Point(palleteObjectOffset * 6 + palleteObjectSize * 6, palleteToolStart),
      Point(palleteObjectOffset * 6 + palleteObjectSize * 6,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 6 + palleteObjectSize * 5,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(CIRCLE));

  auto circleIcon = std::make_unique<Circle>(
      Point(palleteObjectOffset * 6 + palleteObjectSize * 5 +
                palleteObjectSize / 2,
            palleteToolStart - palleteObjectSize / 2),
      8, Color(0.0, 0.0, 0.0), Tool(CIRCLE));

  auto emptyCircleTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 7 + palleteObjectSize * 6, palleteToolStart),
      Point(palleteObjectOffset * 7 + palleteObjectSize * 7, palleteToolStart),
      Point(palleteObjectOffset * 7 + palleteObjectSize * 7,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 7 + palleteObjectSize * 6,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(EMPTY_CIRCLE));

  auto emptyCircleIcon = std::make_unique<Circle>(
      Point(palleteObjectOffset * 7 + palleteObjectSize * 6 +
                palleteObjectSize / 2,
            palleteToolStart - palleteObjectSize / 2),
      8, Color(0.0, 0.0, 0.0), Tool(EMPTY_CIRCLE), true);

  auto moveTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 8 + palleteObjectSize * 7, palleteToolStart),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 8, palleteToolStart),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 8,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 7,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(MOVE));

  auto moveIcon1 = std::make_unique<Line>(
      Point(palleteObjectOffset * 8 + palleteObjectSize * 8 - 10,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 7 + 5,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.6, 0.6, 0.6), Tool(MOVE));

  auto moveIcon2 = std::make_unique<Line>(
      Point(palleteObjectOffset * 8 + palleteObjectSize * 8 - 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 8 + palleteObjectSize * 7 + 10,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.0, 0.0, 0.0), Tool(MOVE));

  auto eraseTool = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8, palleteToolStart),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9, palleteToolStart),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9,
            palleteToolStart - palleteObjectSize),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8,
            palleteToolStart - palleteObjectSize),
      Color(1.0, 1.0, 1.0), Tool(ERASE));

  auto eraseIcon1 = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8 + 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9 - 5,
            palleteToolStart - 5),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9 - 5,
            palleteToolStart - palleteObjectSize + 5),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8 + 5,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.863, 0.078, 0.235), Tool(ERASE));

  auto eraseIcon2 = std::make_unique<Quadrilateral>(
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8 + 5,
            palleteToolStart - 15),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9 - 5,
            palleteToolStart - 15),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 9 - 5,
            palleteToolStart - palleteObjectSize + 5),
      Point(palleteObjectOffset * 9 + palleteObjectSize * 8 + 5,
            palleteToolStart - palleteObjectSize + 5),
      Color(0.117647, 0.564706, 1.0), Tool(ERASE));

  selectedColor =
      Quadrilateral(Point(palleteObjectOffset * 13 + palleteObjectSize * 11,
                          palleteColorStart),
                    Point(palleteObjectOffset * 14 + palleteObjectSize * 13,
                          palleteColorStart),
                    Point(palleteObjectOffset * 14 + palleteObjectSize * 13,
                          palleteToolStart - palleteObjectSize),
                    Point(palleteObjectOffset * 13 + palleteObjectSize * 11,
                          palleteToolStart - palleteObjectSize),
                    Color(1.0, 1.0, 1.0));

  tools.push_back(std::move(lineTool));
  tools.push_back(std::move(squareTool));
  tools.push_back(std::move(emptySquareTool));
  tools.push_back(std::move(triangleTool));
  tools.push_back(std::move(emptyTriangleTool));
  tools.push_back(std::move(circleTool));
  tools.push_back(std::move(emptyCircleTool));
  tools.push_back(std::move(moveTool));
  tools.push_back(std::move(eraseTool));

  tools.push_back(std::move(squareIcon));
  tools.push_back(std::move(lineIcon));
  tools.push_back(std::move(emptySquareIcon));
  tools.push_back(std::move(triangleIcon));
  tools.push_back(std::move(emptyTriangleIcon));
  tools.push_back(std::move(circleIcon));
  tools.push_back(std::move(emptyCircleIcon));
  tools.push_back(std::move(moveIcon1));
  tools.push_back(std::move(moveIcon2));
  tools.push_back(std::move(eraseIcon1));
  tools.push_back(std::move(eraseIcon2));
}

void Window::mouseEvent(GLint button, GLint state, GLint x, GLint y) {

  if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
      insideToolbar(x, HEIGHT - y)) {
    for (auto &p : pallete) {
      if (p.get()->insideObject(x, HEIGHT - y)) {
        auto quadrilateral = dynamic_cast<Quadrilateral *>(p.get());
        if (quadrilateral == NULL) {
          return; // cast failed
        }
        currentColor = quadrilateral->getColor();
        selectedColor.setColor(currentColor);
        std::cout << currentColor << std::endl;
        break;
      }
    }

    for (auto &t : tools) {
      if (t.get()->insideObject(x, HEIGHT - y)) {
        auto quadrilateral = dynamic_cast<Quadrilateral *>(t.get());
        if (quadrilateral == NULL) {
          return; // cast failed
        }
        currentTool = quadrilateral->getTool();

        int nrTool = static_cast<int>(quadrilateral->getTool().getTool()) + 1;

        outlineSelectedTool = Quadrilateral(
            Point(palleteObjectOffset * nrTool +
                      palleteObjectSize * (nrTool - 1) - 2,
                  palleteToolStart + 2),
            Point(palleteObjectOffset * nrTool + palleteObjectSize * nrTool + 2,
                  palleteToolStart + 2),
            Point(palleteObjectOffset * nrTool + palleteObjectSize * nrTool + 2,
                  palleteToolStart - palleteObjectSize - 2),
            Point(palleteObjectOffset * nrTool +
                      palleteObjectSize * (nrTool - 1) - 2,
                  palleteToolStart - palleteObjectSize - 2),
            Color(0.0, 0.0, 0.0), true);

        std::cout << currentTool << std::endl;
        break;
      }
    }
  } else if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&
             insideToolbar(x, HEIGHT - y)) {
    glutPostRedisplay(); // the window is going to be redisplayed
  } else {
    if (currentTool.getTool() == ERASE) {
      std::cout << "erase" << std::endl;
      if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
          !insideToolbar(x, HEIGHT - y)) {
        for (auto it = objects.rbegin(); it != objects.rend(); it++) {
          if ((*it).get()->insideObject(x, HEIGHT - y)) {
            objects.erase(--it.base());
            break;
          }
        }
      }
      if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&
          !insideToolbar(x, HEIGHT - y)) {
        glutPostRedisplay();
      }
    } else if (currentTool.getTool() == MOVE) {
      std::cout << "move" << std::endl;
      moving = true;
      if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
          !insideToolbar(x, HEIGHT - y)) {
        for (auto &obj : objects) {
          if (obj.get()->insideObject(x, HEIGHT - y)) {
            selectedObject = obj.get();
            moveX = x;
            moveY = HEIGHT - y;
            break;
          }
        }
      }
      if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&
          !insideToolbar(x, HEIGHT - y)) {
        glutPostRedisplay();
        moving = false;
      }
    }
    // draw
    else if (currentTool.getTool() != MOVE && currentTool.getTool() != ERASE) {
      std::cout << "draw" << std::endl;
      if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN &&
          !insideToolbar(x, HEIGHT - y)) {
        Point currentPoint(x, HEIGHT - y);
        drawing = true;
        if (currentTool.getTool() == LINE) {
          auto ptr =
              std::make_unique<Line>(currentPoint, currentPoint, currentColor);
          objects.push_back(std::move(ptr));
          glLineStipple(3, 0xAAAA);
          glEnable(GL_LINE_STIPPLE);
        } else if (currentTool.getTool() == SQUARE) {
          auto ptr = std::make_unique<Quadrilateral>(currentPoint, currentPoint,
                                                     currentPoint, currentPoint,
                                                     currentColor);
          objects.push_back(std::move(ptr));
        } else if (currentTool.getTool() == EMPTY_SQUARE) {
          auto ptr = std::make_unique<Quadrilateral>(currentPoint, currentPoint,
                                                     currentPoint, currentPoint,
                                                     currentColor, true);
          objects.push_back(std::move(ptr));
          glLineStipple(3, 0xAAAA);
          glEnable(GL_LINE_STIPPLE);
        } else if (currentTool.getTool() == TRIANGLE) {
          auto ptr = std::make_unique<Triangle>(currentPoint, currentPoint,
                                                currentPoint, currentColor);
          objects.push_back(std::move(ptr));
        } else if (currentTool.getTool() == EMPTY_TRIANGLE) {
          auto ptr = std::make_unique<Triangle>(
              currentPoint, currentPoint, currentPoint, currentColor, true);
          objects.push_back(std::move(ptr));
          glLineStipple(3, 0xAAAA);
          glEnable(GL_LINE_STIPPLE);
        } else if (currentTool.getTool() == CIRCLE) {
          auto ptr = std::make_unique<Circle>(currentPoint, 0, currentColor);
          objects.push_back(std::move(ptr));
        } else if (currentTool.getTool() == EMPTY_CIRCLE) {
          if (!objects.empty()) {
            auto ptr =
                std::make_unique<Circle>(currentPoint, 0, currentColor, true);
            objects.push_back(std::move(ptr));
            glLineStipple(3, 0xAAAA);
            glEnable(GL_LINE_STIPPLE);
          }
        }
      }
      if (button == GLUT_LEFT_BUTTON && state == GLUT_UP &&
          !insideToolbar(x, HEIGHT - y)) {
        glDisable(GL_LINE_STIPPLE);
        glutPostRedisplay();
        drawing = false;
      }
    }
  }
}

bool Window::insideObject(GLint x, GLint y) {
  for (auto &o : objects) {
    if (o.get()->insideObject(x, y)) {
      return true;
    }
  }

  return false;
}

bool Window::insideToolbar(GLint x, GLint y) {
  return background.insideObject(x, y);
}

void Window::moveActiveMouseEvent(GLint x, GLint y) {
  if (drawing) {
    if (currentTool.getTool() == LINE) {
      if (!objects.empty()) {
        auto line = dynamic_cast<Line *>(objects.back().get());
        if (line == NULL) {
          return; // cast failed
        }
        line->setB(Point(x, HEIGHT - y));
        line->draw();
      }
    } else if (currentTool.getTool() == SQUARE ||
               currentTool.getTool() == EMPTY_SQUARE) {
      if (!objects.empty()) {
        auto square = dynamic_cast<Quadrilateral *>(objects.back().get());
        if (square == NULL) {
          return; // cast failed
        }

        Point b = square->getB();
        b.setX(x);

        Point d = square->getD();
        d.setY(HEIGHT - y);

        square->setB(b);
        square->setC(Point(x, HEIGHT - y));
        square->setD(d);
        square->draw();
      }
    } else if (currentTool.getTool() == TRIANGLE ||
               currentTool.getTool() == EMPTY_TRIANGLE) {
      if (!objects.empty()) {
        auto triangle = dynamic_cast<Triangle *>(objects.back().get());
        if (triangle == NULL) {
          return; // cast failed
        }

        Point b = triangle->getB();
        b.setY(HEIGHT - y);

        triangle->setB(b);
        triangle->setC(Point(x, HEIGHT - y));
        triangle->draw();
      }
    } else if (currentTool.getTool() == CIRCLE ||
               currentTool.getTool() == EMPTY_CIRCLE) {
      if (!objects.empty()) {
        auto circle = dynamic_cast<Circle *>(objects.back().get());
        if (circle == NULL) {
          return; // cast failed
        }
        auto center = circle->getCenter();
        auto radius = std::sqrt(std::pow(center.getX() - x, 2) +
                                std::pow(center.getY() - (HEIGHT - y), 2));
        circle->setRadius(radius);
        circle->draw();
      }
    }
  }

  if (moving && selectedObject != nullptr) {
    selectedObject->moveObject(x - moveX, (HEIGHT - y) - moveY);
    selectedObject->draw();
    moveX = x;
    moveY = HEIGHT - y;
  }
}

void Window::movePassiveMouseEvent(GLint x, GLint y) {
}

void Window::keyboardEvent(unsigned char key, int x, int y) {
  if (tolower(key) == Q) {
    glutDestroyWindow(windowID);
    exit(0);
  }
}
