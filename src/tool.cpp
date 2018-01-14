#include <iostream>

#include "quadrilateral.h"
#include "tool.h"

Tool::Tool(int tool) : tool(tool) {
}

Tool::~Tool() {
}

int Tool::getTool() {
  return tool;
}

std::ostream &operator<<(std::ostream &os, const Tool &tool) {
  if (tool.tool == SQUARE) {
    os << "tool: square";
  } else if (tool.tool == EMPTY_SQUARE) {
    os << "tool: empty square";
  } else if (tool.tool == TRIANGLE) {
    os << "tool: triangle";
  } else if (tool.tool == EMPTY_TRIANGLE) {
    os << "tool: empty triangle";
  } else if (tool.tool == CIRCLE) {
    os << "tool: circle";
  } else if (tool.tool == EMPTY_CIRCLE) {
    os << "tool: empty circle";
  } else if (tool.tool == LINE) {
    os << "tool: line";
  } else if (tool.tool == MOVE) {
    os << "tool: move";
  } else if (tool.tool == ERASE) {
    os << "tool: erase";
  }

  return os;
}