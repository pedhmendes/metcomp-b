//////////////////////
///EULER EXPLICITO////
/////PEDRO MENDES/////
//////////////////////

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	double x, deltat, tau, t, tf;

	printf("\n #Insira um valor do passo:\n\n");	
	scanf("%lf", &deltat);

	x =10;
	tf = 10;
	tau = 2;
	t = 0;

	printf("%lf %lf", t, x);	

	while(t < tf)	
	{
		x = x - ( (x/tau)*(deltat) );
		t = t + deltat;
		printf("%lf %lf\n", t, x);
	}

	return 0;
}
