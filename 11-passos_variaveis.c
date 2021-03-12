////////////////////
//PASSOS VARIAVEIS//
////PEDRO MENDES////
////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double F(double x);
double RK2(double x, double deltat, double (*f)(double));
double RK4(double x, double deltat, double (*f)(double));

int main()
{
	int n;
	double t, tf, deltat, deltatn;
	double x, x2, x4;
	double tol, ec;	
	double time;
	
	clock_t time1, time2;

	printf("\n#Escolha a tolerancia\n\n");
	scanf("%lf", &tol);

	x = 0.001;
	deltat = .00001;
	t = 0.;
	tf =80.;
	n = 0.;

	time1 = clock();

	while(t < tf)
	{
		n = n + 1;

		x2 = RK2(x,deltat,F);

		if(n%10 == 0)
		{
			x4 = RK4(x,deltat,F);
		
			ec = sqrt( fabs(pow((x4 - x),2) - pow((x2 - x),2)) );

			deltatn = deltat*pow((tol/ec),1./3);

			if(deltatn > 2.*deltat)
			{
				deltatn = 2.*deltat;
				deltat = deltatn;
			}
			
			else
			{
				deltat = deltatn;
			}
		}

		printf("%d %.12lf %.12lf %.12lf\n", n, t, deltat, x);

		x = x2;
		t = t + deltat;

	}
	
	time2 = clock();
	time = ( (double) (time2 - time1) )/CLOCKS_PER_SEC;
	printf("\n\n#O programa levou %lf segundos\n\n", time);

	return 0;
}

double F(double x)
{
	return 0.1*x*(2 - x);
}

double RK2(double x, double deltat, double (*f)(double))
{
	double k1, k2;

	k1 = F(x);
	k2 = F(x + 0.5*k1*deltat);
	
	return x + k2*deltat;
}

double RK4(double x, double deltat, double (*f)(double))
{
	double k1, k2, k3, k4;

	k1 = F(x);
	k2 = F( F(x) + 1./3.*k1*deltat);
	k3 = F( F(x) - 1./3.*k1*deltat + k2*deltat);
	k4 = F( F(x) + k1*deltat - k2*deltat - k3*deltat); 

	return x + (1./8)*(k1 + 3.*k2 + 3.*k3 + k4)*deltat; 
}
