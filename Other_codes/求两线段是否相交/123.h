#ifndef __123_h_
#define __123_h_

#include<stdio.h>

int Check(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4);


#endif


int Check(double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4)
{
	double k1,k2,tmp;
	double x[4] = {x1,x2,x3,x4};
	int i, j;
	k1 = (y2 - y1) / (x2 - x1);
	k2 = (y4 - y3) / (x4 - x3);

	for (i = 0; i < 3; i++)
	{
		for (j = i+1; j < 4;j++)
		{
			if (x[i]>x[j])
			{
				tmp = x[i];
				x[i] = x[j];
				x[j] = tmp;
			}
		}
			
	}

	double xx, yy;
	xx = ((y3 - (k2*x3)) - (y1 - (k1*x1)))/(k1 - k2);
	printf("%f\n",xx);
	if ((x[1] <= xx) && (xx <= x[2]))
	{
		printf("相交！");
		return 1;
	}
	else
	{
		printf("线段不相交！");
		return 0;
	}
}