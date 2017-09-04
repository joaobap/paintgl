#ifndef __COLOUR_H__
#define __COLOUR_H__

class Color {
private:
	float r;
	float g;
	float b;

public:
	Color(float r, float g, float b);
	float getR();
	float getG();
	float getB();
	void glColor();
};

#endif // __COLOUR_H__
