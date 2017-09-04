#ifndef __QUADRILATERAL_H__
#define __QUADRILATERAL_H__

#include "object.h"
#include "point.h"

class Quadrilateral : public AbstractObject {
private:
	Point a;
	Point b;
	Point c;
	Point d;

	Color color;
public:
	Quadrilateral(Point a, Point b, Point c, Point d, Color color);
	virtual ~Quadrilateral();
	virtual void draw();
	virtual void redraw();
};

#endif // __QUADRILATERAL_H__
