//////////////////////////////
/////////RANDOM WALKER////////
///////DIFERENTES PASSOS//////
/////////PEDRO MENDES/////////
//////////////////////////////

#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

double simple_step();//passos discretos 1 ou -1
double exp_step();//passos exponenciais
double cauchy_step();//passos de cauchy

int main()
{
	int i, j, m=10000, max=10000, h1;
	int h[max], small, x[m];
	double msd[max+1], sum[m], square[m]; 
	double step;
	FILE *MSD, *position, *hist;

	MSD = fopen("MSD.dat", "w");
	position = fopen("position.dat", "w");
	hist = fopen("histogram.dat", "w");

	srand(time(NULL));

	for(i=1; i<=m; i++)
	{	
		x[i] = 0;
		sum[i] = 0;
	}

	for(i=1; i<=max; i++)
	{
		h[i] = 0;
		msd[i] = 0;
	}
	
	for(i=0; i<=m; i++)
	{
		fprintf(position,"0 ");
	}

	for(j=1; j<=max; j++)
	{
		fprintf(position,"\n%d ", j);
		fprintf(MSD,"\n%d ", j);

		for(i=1; i<=m; i++)
		{
			step = simple_step(); //DEFINIR A FUNÇÃO DO PASSO AQUI!!!!!
			x[i] = x[i] + step;
			sum[i] = sum[i] + x[i];
			square[i] = pow(x[i],2);
		
			fprintf(position,"%d ", x[i]);
		}
	
		for(i=1; i<=m; i++)
		{
			msd[j] = msd[j] + square[i]; 
		}

		fprintf(MSD,"%lf", msd[j]/m);

	}

	small = 0;

	for(i=1; i<=m; i++)
	{
		if(x[i] < small)
		{
			small = x[i];
		}
	}

	small = -1*small;

	for(j=1; j<=1; j++)
	{
		for(i=1; i<=m; i++)
		{	
			h1 = x[i] + small;
			h[h1] = h[h1] + 1;
		}
	}
	
	for(j=1; j<=max; j++)
	{
		if(h[j] != 0)
		{
			fprintf(hist,"%d %d\n", (j-small), h[j]);
		}
	}

	fclose(position);
	fclose(MSD);	
	fclose(hist);

	return 0;
}

double simple_step()
{
	return 2*(rand()%2) - 1;
}

double exp_step()
{
	int d;
	double x;
	
	d = rand()%2;
	x = (double)rand()/((double)RAND_MAX);
	
	if(d == 0)
	{
		x = -2*log(1-x);
	}
	if(d != 0)
	{	
		x = -2*log(1-x);
		x = -x;
	}

	return x;
}

double cauchy_step()
{
	int d;
	double x;
	
	d = rand()%2;
	x = (double)rand()/((double)RAND_MAX);
	
	if(d == 0)
	{
		x = -tan(M_PI*(x + 0.5));
	}
	if(d != 0)
	{
		x = -tan(M_PI*(x + 0.5));
		x = -x;
	}

	return x;
}
