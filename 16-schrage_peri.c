////////////////////////////
///////SCHRAGE PERIODO//////
////////PEDRO MENDES////////
////////////////////////////

#include<stdio.h>
#include<time.h>

int main()
{
	int a, m;
	int r, q;
	int x, x0, t;
	double time;
	clock_t ti, tf;
	
	x0 = 51;
	x = 51;

	a = 16807;
	m = 2147483647;
	q = 127773;
	r = 2836;
	
	ti = clock();

	for(t = 1; t < 10000000000; t++)
	{
		x = a*(x%q) - r*(x/q);

		if( x < 0 )
		{
			x = x + m;
		}

		if( x == x0)
		{	
			printf("\nO periodo é %d\n", t);
		
			break;
		}
	}
	
	tf = clock();
	time = ( (double) (tf - ti) )/CLOCKS_PER_SEC; 

	printf("\nEsse programa levou %lf segundos para calcular\n\n", time);

	return 0;
}
