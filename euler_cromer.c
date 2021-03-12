//////////////////////
////EULER EXPLICITO///
//////////VS//////////
/////EULER-CROMER/////
/////PEDRO MENDES/////
//////////////////////

#include<stdio.h>
#include<math.h>

int main ()
{
	int m;
	double x, xi, deltat, v, t, w, tf;
	double g, l;

	printf("\n #Insira um valor do passo:\n\n");	
	scanf("%lf", &deltat);

	x = 0.1; 
	v = 0;
	g = 10;
	l = 10;
	w = g/l; 
	t = 0;
	tf = 30;

	printf("\n#Escolha o metodo\n#Euler-Explicito(0)\n#Euler-Cromer(1)\n\n");
	scanf("%d", &m);

	printf("%lf %lf\n", t, x);	
	
	if(m==0) //euler explicito
	{
		while(t < tf)	
		{
			xi = x;
			x = x + v*deltat;
			v = v - w*sin(xi)*deltat;
			t = t + deltat;
			printf("%lf %lf\n", t, x);
		}
	}

	else //euler-cromer
	{
		while(t < tf)	
		{	
			x = x + v*deltat;
			v = v - w*sin(x)*deltat;
			t = t + deltat;
			printf("%lf %lf\n", t, x);
		}
	}

	return 0;
}
