#ifndef __OBJECT_H__
#define __OBJECT_H__

#if defined(__APPLE__) || defined(MACOSX)
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#include <gl/gl.h>
#include <gl/glu.h>
#include <windows.h>
#endif

#include "color.h"

class AbstractObject {
public:
  virtual ~AbstractObject() {
  }
  virtual void draw() = 0;
  virtual void redraw() = 0;
  virtual void moveObject(GLint x, GLint y) = 0;
  virtual bool insideObject(GLint x, GLint y) = 0;
};

#endif // __OBJECT_H__
