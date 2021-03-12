/////////////////////////
/////METODO DE EULER/////
//////PEDRO MENDES///////
/////////////////////////

#include<stdio.h>
#include<math.h>

int main()
{
	int m;
	double x, deltat, tau, t, tf;

	printf("\n #Insira um valor do passo:\n\n");	
	scanf("%lf", &deltat);

	x =10;
	tf = 15;
	tau = 2;
	t = 0;

	printf("\n#Escolha o metodo\n#Explicito(0)\n#Implicito(1)\n\n");
	scanf("%d", &m);

	printf("%lf %lf", t, x);	
	
	if(m==0)
	{
		while(t < tf)	
		{
			x = x - ( (x/tau)*(deltat) );
			t = t + deltat;
			printf("%lf %lf\n", t, x);
		}
	}

	else
	{
		while(t < tf)	
		{
			x = x/(1 + (deltat/tau) );
			t = t + deltat;
			printf("%lf %lf\n", t, x);
		}
	}

	return 0;
}
