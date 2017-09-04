#ifndef __COLOUR_H__
#define __COLOUR_H__

class Color {
private:
	int r;
	int g;
	int b;

public:
	Color(int r, int g, int b);
	int getR();
	int getG();
	int getB();
	void glColor();
};

#endif // __COLOUR_H__
