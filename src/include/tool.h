#ifndef __TOOL_H__
#define __TOOL_H__

#include "object.h"
#include "point.h"
#include <iostream>
#include <memory>

#define NR_TOOLS 9
#define NR_ICONS 11

enum Tools {
  LINE,
  SQUARE,
  EMPTY_SQUARE,
  TRIANGLE,
  EMPTY_TRIANGLE,
  CIRCLE,
  EMPTY_CIRCLE,
  MOVE,
  ERASE
};

class Tool {
private:
  int tool;

public:
  Tool(){};
  Tool(int tool);
  ~Tool();
  int getTool();
  friend std::ostream &operator<<(std::ostream &os, const Tool &tool);
};

#endif // __TOOL_H__