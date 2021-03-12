//////////////////
/////BINARIO//////
///PEDRO MENDES///
//////////////////

#include<stdio.h>
#include<math.h>

int main()
{
	int r, x[8], i;

	printf("\nInsira um numero entre 0 e 255\n\n");
	scanf("%d", &r);

	for(i=0; r>0; i++)
	{
		x[i] = r%2;
		r = r/2;
	}
		
	printf("\n");

	printf("O numero em binario eh: ");	
	
	for(i=i-1; i>=0; i--)
	{	
		printf("%d", x[i]);
	}

	printf("\n\n");

	return 0;
}
