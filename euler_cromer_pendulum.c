//////////////////////
/////EULER-CROMER/////
////////PENDULO///////
/////PEDRO MENDES/////
//////////////////////

#include<stdio.h>
#include<math.h>

int main ()
{
	double x, deltat, v, t, w, tf;
	double g, l;
	double m, et;

	printf("\n #Insira um valor do passo:\n\n");	
	scanf("%lf", &deltat);

	x = -3.14; 
	v = 0.1; 
	g = 10;
	l = 10;
	w = g/l; 
	t = 0;
	tf = 30;
	m = 1;
	et = 0.5*m*pow(l,2)*pow(v,2) + m*g*l*(1 - cos(x));

	printf("%lf %lf %lf %lf\n", t, x, v, et);	
	
	//euler-cromer
	while(t < tf)	
		{	
			x = x + v*deltat;
			v = v - w*sin(x)*deltat;
			t = t + deltat;
			et = 0.5*m*pow(l,2)*pow(v,2) + m*g*l*(1 - cos(x));
			printf("%lf %lf %lf %lf\n", t, x, v, et);
		}
	

	return 0;
}
