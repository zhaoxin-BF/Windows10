#include "AdvCircle.h"

void AdvCircle::setCircle(double _r, double _x0, double _y0)
{
	r = _r;
	x0 = _x0;
	y0 = _y0;
}

double AdvCircle::getR()
{
	return r;
}

double AdvCircle::getX0()
{
	return x0;
}

double AdvCircle::getY0()
{
	return y0;
}

int AdvCircle::judgeCP(MyPoint &p1)
{
	double x, y, z;
	x = p1.getX1() - x0;
	y = p1.getY1() - y0;
	z = x*x + y*y;
	if (r*r > z)
		return 1;
	else if (r*r == z)
		return 0;
	else
		return -1;
}