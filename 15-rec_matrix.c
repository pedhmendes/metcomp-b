/////////////////////////////
////MATRIZ DE RECORRENCIA////
/////DO MAPA LOGISTICO///////
////////PEDRO MENDES/////////
/////////////////////////////

#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int main()
{
	int i, j, n;
	double r0, lambda;
	double x[300];

	r0 = 0.001;
	lambda = 3.573; //0.5c0 ; 1.4c1 ; 3.1c2 ; 3.5c4 ; 3.5442c8 ; 3.57caos 
	n = 300;
	x[0] = 0.2;
	
	for(i=0; i<n; i++)
	{
		x[i+1] = lambda*x[i]*(1 - x[i]);
		printf("%lf", x[i]);
	}

	for(i=0;i<n;i++)
	{
		for(j=i;j<n;j++)
		{

			if( fabs(x[i] - x[j]) < r0 )
			{
				printf("%d %d\n", i,j);		
				printf("%d %d\n", j,i);	
	
			}
		}
	}

	return 0;
}
