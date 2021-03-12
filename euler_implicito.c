///////////////////////
////EULER IMPLICITO////
//////PEDRO MENDES/////
///////////////////////

#include<stdio.h>
#include<math.h>

int main()
{
	double x, deltat, tau, t, tf;

	printf("\n #Insira um valor do passo:\n\n");	
	scanf("%lf", &deltat);

	x =10;
	tf = 15;
	tau = 2;
	t = 0;

	printf("%lf %lf\n", t, x);	

	while(t < tf)	
	{
		x = x/(1 + (deltat/tau) );
		t = t + deltat;
		printf("%lf %lf\n", t, x);
	}

	return 0;
}
