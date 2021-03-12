///////////////////////////
//////METODO DE VERLET/////
//////VELOCITY-VERLET//////
///////PEDRO MENDES////////
///////////////////////////

#include<stdio.h>
#include<math.h>

double acc(double x); //para generalizar a função aceleração

int main()
{
	int c;
	double t, tf, deltat;
	double x, xm, xM;
	double v, vmeio;
	double g, m, l;
	double ug, ek, em;
	
	printf("\n #Insira um valor do passo:\n\n");	
	scanf("%lf", &deltat);

	printf("\n#Escolha o metodo\n#Verlet(0)\n#Velocity-Verlet(1)\n\n");
	scanf("%d", &c);
	
	g = 10;
	l = 10;
	m = 3;
	t = 0;
	tf = 30;
	x = 1; 
	xM = 0;
	v = 0;
	vmeio = 0;
	xm = x - v*deltat; 
	ek = 0.5*m*pow(l,2)*pow(v,2);
	ug =  m*g*l*(1 - cos(xm));
	em = ug + ek;

	if(c==0) //Verlet
	{
		while(t < tf)	
		{
			xM = 2*x - xm + acc(x)*pow(deltat,2);
			t += deltat;
			v = (xM - xm)/(2*deltat);
			xm = x;
			x = xM;
			ek = 0.5*m*pow(l,2)*pow(v,2);
			ug =  m*g*l*(1 - cos(xm));
			em = ug + ek;
			printf("%lf %lf %lf %lf %lf\n",t, x, v, acc(x), em);
		}
	}

	else //Velocity-Verlet
	{
		while(t < tf)	
		{
			vmeio = v + acc(x)*(deltat/2);
			x = x + vmeio*deltat;
			v = vmeio + acc(x)*(deltat/2);	
			t += deltat;
			ek = 0.5*m*pow(l,2)*pow(v,2);
			ug =  m*g*l*(1 - cos(xm));
			em = ug + ek;
			printf("%lf %lf %lf %lf %lf\n",t, x, v, acc(x), em);
		}
	}

	return 0;
}

double acc(double x)
{
	int l, g;
	double w, a;
	
	l = 10;
	g = 10;
	w = sqrt(l/g);

	a = pow(w,2)*sin(x);

	return a;
}
