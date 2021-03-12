//////////////////
//MAPA LOGISTICO//
////////&/////////
/////LYAPUNOV/////
///PEDRO MENDES///
//////////////////

#include<stdio.h>
#include<math.h>

int main ()
{
	int n;
	double x, y, dy, lya;
	
	x = 0.2;
	dy = 0.01;
	y = 1.3;
	lya = 0;
	
	while(y<4)	
	{
		for(n=1; n<101; n++)
		{
			x = x*y*(1 - x);
			lya = lya + (log(fabs(y*(1 - 2*x))));
			printf("%lf %lf %lf\n", y, x, (lya/n));
		}
		
		lya = 0;

		for(n=1; n<1001; n++)
		{
			x = x*y*(1 - x);
			lya = lya + (log(fabs(y*(1 - 2*x))));
			printf("%lf %lf %lf\n", y, x, (lya/n));
		}
		
	y = y + dy;
	
	}

	return 0;
}
