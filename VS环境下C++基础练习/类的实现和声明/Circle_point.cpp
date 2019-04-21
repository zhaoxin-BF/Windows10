#include <iostream>

using namespace std;

class MyPoint
{
public:
	void setPoint(double _x1, double _y1)
	{
		x1 = _x1;
		y1 = _y1;
	}

	double getX1()
	{
		return x1;
	}

	double getY1()
	{
		return y1;
	}
private:
	double x1, y1;
};

class AdvCircle
{
public:
	void setCircle(double _r, double _x0, double _y0)
	{
		r = _r;
		x0 = _x0;
		y0 = _y0;
	}

	double getR()
	{
		return r;
	}

	double getX0()
	{
		return x0;
	}

	double getY0()
	{
		return y0;
	}
public:
	int judgeCP(MyPoint &p1)
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
private:
	double r, x0, y0;

};



int main()
{
	AdvCircle c1;
	MyPoint p1;

	c1.setCircle(1, 1, 1);
	p1.setPoint(2, 1.1);

	//在圆形1， 不再圆形0；

	int tag = c1.judgeCP(p1);
	if (tag == 1)
	{
		cout << "在圆形内！" << endl;
	}
	else if (tag == -1)
	{
		cout << "在圆形外！" << endl;
	}
	else
		cout << "在圆上！" << endl;

	system("pause");
	return 0;
} 