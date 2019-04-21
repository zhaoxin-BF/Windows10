#pragma once
#include "MyPoint.h"
class AdvCircle
{
public:
	void setCircle(double _r, double _x0, double _y0);
	double getR();
	double getX0();
	double getY0();
public:
	int judgeCP(MyPoint &p1);
private:
	double r, x0, y0;

};
