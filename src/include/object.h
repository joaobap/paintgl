#ifndef __OBJECT_H__
#define __OBJECT_H__

#include "color.h"

class AbstractObject {
public:
	virtual void draw() = 0;
	virtual void redraw() = 0;
};

#endif // __OBJECT_H__
