////////////////////
////RUNGE-KUTTA4////
////PEDRO MENDES////
////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

double F(double x);

int main()
{
	int c;
	double t, deltat, tf;
	double x;
	double a1, a2, a3, a4;
	double k1, k2, k3, k4;
	double b, b2, b3, b4, p, q;

	printf("\n#Escolha o passo: ");
	scanf("%lf", &deltat);
	
	printf("\n#Escolha o metodo:\n#Runge-Kutta-4(0)\n#Ponto Medio(1)\n\n");
	scanf("%d", &c);

	x = 10;
	tf = 5;
	t = 0;

	printf("%lf %lf\n", t, x);

	switch(c)
	{

		case 0: //rk 4

			a1 = 1./6.;
			a2 = 1./3.;
			a3 = 1./3.;
			a4 = 1./6.;
			
			while(t < tf)
			{
				k1 = F(x);

				b2 = x + .5*k1*deltat;
				k2 = F(b2);

				b3 = x + .5*k2*deltat;
				k3 = F(b3);
				
				b4 = x + k3*deltat;
				k4 = F(b4); 

				x = x + (1./8)*(k1 + 3*k2 + 3*k3 + k4)*deltat; 
				t = t + deltat;
			
				printf("%lf %lf\n", t, x);
			}


		case 1: //ponto medio
		
			a1 = 0;
			a2 = 1;
			q = .5;
		
			while(t < tf)
			{
				k1 = F(x);

				b = x + q*k1*deltat;
				k2 = F(b);

				x = x + (a1*k1 + a2*k2)*deltat; 
				t = t + deltat;

				printf("%lf %lf\n", t, x);
			}


		break;

		default:

			printf("\nDon't Panic! The answer is 42...\n\n");
	
		break;
	}

	return 0;
}

double F(double x)
{
	double tau;
	double f;
	
	tau = 2;

	f = - (x/tau);
	return f;
}
