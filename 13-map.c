////////////////////////
/////MAPA LOGISTICO/////
//////PEDRO MENDES//////
////////////////////////

#include<stdio.h>
#include<math.h>

int main()
{
	int n;
	double x, l;
	
	printf("\n#escolha o lambda\n\n");
	scanf("%lf", &l);

	printf("\n#escolha x0\n\n");
	scanf("%lf", &x);

	for(n=0; n<11; n++)
	{
		x = 4*l*x*(1 - x);
		printf("%d %lf\n", n, x);
	}

	return 0;
}
