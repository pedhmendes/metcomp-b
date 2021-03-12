////////////////////
////////ERRO////////
////NA INTEGRAÇÃO///
/////DO PENDULO/////
////PEDRO MENDES////
////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

int main ()
{
	int c;
	double t, tf, deltat, deltatm;
	double x, xn, x0, xa;
       	double v, vn, va;
	double w;
	double k1x, k2x, k3x, k4x;
	double k1v, k2v, k3v, k4v;
	double ex, ev;
	double time;
	
	clock_t time1, time2;

	printf("\n#Escolha o passo minimo: ");
	scanf("%lf", &deltat);

	printf("\n#Escolha o passo maximo: ");
	scanf("%lf", &deltatm);
	
	printf("\n#Escolha o metodo:\n#Runge-Kutta-4(0)\n#Runge-Kutta-2(1)\n#Euler-Cromer(2)\n\n");
	scanf("%d", &c);

	x = 0.1;
	x0 = 0.1;
	v = 0;
	tf = 30;
	t = 0;
	w = 1;
	
	switch(c)
	{
		case 0: //rk 4
		
			time1 = clock();

			while(deltat < deltatm) //laço do erro
			{
				x = .1;
				v = 0;
				t = 0;
				ex = 0;
				ev = 0;

				while(t < tf) //laço do rk4
				{
					k1x = v;
					k1v = -w*x;
				
					xn = x + k1x*deltat*.5;
					vn = v + k1v*deltat*.5;

					k2x = vn;
					k2v = -w*xn;

					xn = x + k2x*deltat*.5;
					vn = v + k2v*deltat*.5;

					k3x = vn;
					k3v = -w*xn;

					xn = x + k3x*deltat;
					vn = v + k3v*deltat;

					k4x = vn;
					k4v = -w*xn;

					x = x + (1./6)*(k1x + 2.*k2x + 2.*k3x + k4x)*deltat;
					v = v + (1./6)*(k1v + 2.*k2v + 2.*k3v + k4v)*deltat;

					t = t + deltat;
				
					xa = x0*cos(w*t);
					va = -x0*sin(w*t);

					ex = ex + (x - xa);
					ev = ev + (v - va);
				}

			printf("%lf %lf %lf\n", log(deltat), log(fabs(ex*(deltat/tf))), log(fabs(ev*(deltat*tf))));
			deltat = 2*deltat;
			}
			
			time2 = clock();
			time = ( (double) (time2 - time1) )/CLOCKS_PER_SEC;
			printf("\n\n#O programa levou %lf segundos\n\n", time);
	
		break;
	
		case 1: //rk 2
	
			time1 = clock();
	
			while(deltat < deltatm) //laço para o erro
			{
				x = 0.1;
				v = 0;
				t = 0;
				ex = 0;
				ev = 0;

				while(t < tf) //laço do rk2
				{

					k1x = v;
					k1v = -w*x;

					xn = x + k1x*deltat*.5;
					vn = v + k1v*deltat*.5;
		
					k2x = vn;
					k2v = -w*xn;

					x = x + k2x*deltat;
					v = v + k2v*deltat;
		
					t = t + deltat;
		
					xa = x0*cos(w*t);
					va = -x0*sin(w*t);

					ex = ex + (x - xa);
					ev = ev + (v - va);

				}	

			printf("%lf %lf %lf\n", log(deltat), log(fabs(ex*(deltat/tf))), log(fabs(ev*(deltat/tf))));		
			deltat = 2*deltat;

			}
			
			time2 = clock();
			time = ( (double) (time2 - time1) )/CLOCKS_PER_SEC;
			printf("\n\n#O programa levou %lf segundos\n\n", time);
	

		break;

		case 2: //euler-cromer

			time1 = clock();

			while(deltat < deltatm) //laço do erro
			{
				x = 0.1;
				v = 0;
				t = 0;
				ex = 0;
				ev = 0;

				while(t < tf) //euler-cromer	
				{	
					x = x + v*deltat;
					v = v - w*sin(x)*deltat;
					t = t + deltat;

					xa = x0*cos(w*t);
					va = -x0*sin(w*t);

					ex = ex + (x - xa);
					ev = ev + (v - va);	
				}

				printf("%lf %lf %lf\n", log(deltat), log(fabs(ex*(deltat/tf))), log(fabs(ev*(deltat/tf))) );
				deltat = 2*deltat;
			}
			
			time2 = clock();
			time = ( (double) (time2 - time1) )/CLOCKS_PER_SEC;
			printf("\n\n#O programa levou %lf segundos\n\n", time);

		break;

		default:

			printf("\nDon't Panic! The answer is 42...\n\n");
	
		break;
	}

	return 0;
}
