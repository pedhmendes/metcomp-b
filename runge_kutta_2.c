////////////////////
////RUNGE-KUTTA2////
////PEDRO MENDES////
////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double F(double x);
double RK(double x, double a1, double a2, double p, double q, double deltat, double (*f)(double));

int main()
{
	int c;
	double t, deltat, tf;
	double x;
	double a1, a2, p, q;

	printf("\n#Escolha o passo\n\n");
	scanf("%lf", &deltat);
	
	printf("\n#Escolha o metodo\n#Heun(1)\n#Ponto Medio(2)\n#Ralston(3)\n\n");
	scanf("%d", &c);

	x = 10;
	tf = 5;
	t = 0;

	printf("%lf %lf\n\n", t, x);

	switch(c)
	{
		case 1: //heun
 
			a1 = .5;
			a2 = .5;
			p = 1;
			q = 1;
		
			while(t < tf)
			{
				x = x + RK(x,a1,a2,p,q,deltat,F);
				t = t + deltat;
				printf("%lf %lf\n", t, x);
			}

		break;

		case 2: //ponto medio

			a1 = 0;
			a2 = 1;
			p = .5;
			q = .5;

			while(t < tf)
			{
				x = x + RK(x,a1,a2,p,q,deltat,F);
				t = t + deltat;
				printf("%lf %lf\n", t, x);
			}


		break;

		case 3: //ralson
			
			a1 = 2/3;
			a2 = 1/3;
			p = 3/4;
			q = 3/4;
	
			while(t < tf)
			{
				x = x + RK(x,a1,a2,p,q,deltat,F);
				t = t + deltat;
				printf("%lf %lf\n", t, x);
			}
		break;

		default:
		
			printf("\n“Don't Panic!”\n\n");

		break;
	}

	return 0;
}

double F(double x)
{
	int tau;

	tau = 2;

	return  - (x/tau);
}


double RK(double x, double a1, double a2, double p, double q, double deltat,double (*f)(double))
{
	double k1, k2;
	double value;

	k1 = F(x);
	k2 = F(x + q*k1*deltat);
	value = (a1*k1 + a2*k2)*deltat; 

	return value;
}
