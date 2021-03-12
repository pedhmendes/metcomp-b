////////////////////
/////MULTIPASSOS////
////PEDRO MENDES////
////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double F(double x);

int main()
{
	double t, tf, deltat;
	double x0, x1, x2;

	printf("\n#Escolha o passo\n\n");
	scanf("%lf", &deltat);

	x0 = 0.01;
	t = 0.;
	tf = 50000.;

	x1 = x0;
	
	while(t < tf)
	{
		x2 = x1 + ( (3./2.)*F(x1) - (.5)*F(x0) )*deltat;
		x2 = x1 + ( (5./12.)*F(x2) + (2./3.)*F(x1) - (1./12.)*F(x0) )*deltat;

		printf("%lf %.12lf\n", t, x2);
	
		x0 = x1;
		x1 = x2;
		t = t + deltat;
	}	

	return 0;
}

double F(double x)
{
	return 0.0001*x*(2 - x);
}
