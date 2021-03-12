////////////////////////////
///////SCHRAGE DISTRIB//////
////////PEDRO MENDES////////
////////////////////////////

#include<stdio.h>
#include<math.h>

int main ()
{
	int a, m;
	int r, q;
	int x, x1, t;
	int L, n=10000, h[n];
	int med, sum, quad;

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

	printf("\nPara n = %d\n", n);

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

//	for(t=0; t<L; t++) //caso seja interessante fazer o histograma
//	{
//		printf("%d %d\n", t, h[t]);	
//	}

	med = 0;

	for(t=0; t<L; t++)
	{
		med = med + h[t];		
	}	

	med = med/L;

	printf("\nA media é %d\n\n", med);

	sum = 0;
	quad = 0;

	for(t=0; t<L; t++)
	{
		quad = h[t] - med;
		quad = pow(quad,2);
		sum = sum + quad;
	}		
	
	sum = sum/L;
	sum = sqrt(sum);
	
	printf("O desvio padrao é %d\n\n", sum);

	return 0;
}
