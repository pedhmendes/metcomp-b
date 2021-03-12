////////////////////////
/////INTEGRAL DE MC/////
//////PEDRO MENDES//////
////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double F(double x);

int main()
{
	double a, b;
	double x, y, ym;
	double c, INT;
	int n, t;

	a = 0;
	b = -2;
	c = 0;
	n = 1000;
	ym = 1.5;

	for(t=0; t<n; t++)
	{
		x = a + (rand()/RAND_MAX)*(b-a);
		y = ym*(rand()/RAND_MAX);

		if( y < F(x))
		{
			c = c + 1;
		}
	}	
		
	INT = (c*ym*(b-a))/n;

	printf("\nA integral é %lf\n\n", INT);

	return 0;
}

double F(double x)
{
	return exp(-1*((pow((x-2),2))/8));
}
