////////////////////////////
///////SCHRAGE HISTOGR//////
////////PEDRO MENDES////////
////////////////////////////

#include<stdio.h>

int main()
{
	int a, m;
	int r, q;
	int x, x1, t;
	int L, n=10000, h[n];

	x = 51;
	a = 16807;
	m = 2147483647;
	q = 127773;
	r = 2836;
	L = 100;

	for(t=0; t<n; t++)
	{
		h[t] = 0;
	}

	for(t=0; t<n; t++)
	{
		x = a*(x%q) - r*(x/q);

		if( x < 0 )
		{
			x = x + m;
		}

		x1 = x%L;
		
		h[x1] = h[x1] + 1;
	}
	
	for(t=0; t<L; t++)
	{
		printf("%d %d\n", t, h[t]);	
	}

	return 0;
}
