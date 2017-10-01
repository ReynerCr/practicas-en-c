#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <math.h>

int main() {
	char resp;
	double x, y, z, a, b, c;
	int h1, h2, h3, h4, h5;
	a=0; b=0; c=0;

	do {
	printf ("Escriba el primer valor (entero positivo) del triangulo: \n");
	fflush (stdin);
	scanf ("%d", &a);
	system ("cls");
	} while (a<=0);
	do {
	printf ("Escriba el segundo valor (entero positivo) del triangulo: \n");
	fflush (stdin);
	scanf ("%d", &b);
	system ("cls");
	} while (b<=0);
	do {
	printf ("Escriba el tercer valor (entero positivo) del triangulo: \n");
	fflush (stdin);
	scanf ("%d", &c);
	system ("cls");
	} while (c<=0);
	system ("cls");
	if (a!=b && a!=c) {
	if (a>b) {
		if (a>c && b>c) {
			x=a;
			y=b;
			z=c;
		}
		if (a>c && c>b){
			x=a;
			y=c;
			z=b;
		}
	}
	if (b>a) {
		if (b>c && a>c) {
			x=b;
			y=a;
			z=c;
		}
		if (b>c && c>a) {
			x=b;
			y=c;
			z=a;
		}
	}
	if (c>a) {
		if (c>b && a>b) {
			x=c;
			y=a;
			z=b;
		}
		if (c>b && b>a) {
			x=c;
			y=b;
			z=a;
		}
	}
	}
	if (a==b && b==c) {
		x=a;
		y=b;
		z=c;
	}
	if (a==b && a!=c) {
		if (a>c) {
			x=a;
			y=b;
			z=c;
		}
		else {
			x=c;
			y=a;
			z=b;
		}
	}
	if (a==c && a!=b) {
		if (a>b) {
			x=a;
			y=c;
			z=b;
		}
		else {
			x=b;
			y=a;
			z=c;
		}
	}
	if (b==c && b!=a) {
		if (b>a) {
			x=b;
			y=c;
			z=a;
		}
		else {
			x=a;
			y=b;
			z=c;
		}
	}
	printf ("A: %d\n", x);
	printf ("B: %d\n", y);	
	printf ("C: %d\n", z);
	printf ("\n\n");

	if (x>=y+z) {
		printf ("NO FORMA TRIANGULO\n");
		system ("pause");
		return 0;
	}
	if ((x*x)==((y*y)+(z*z))) {
		printf ("TRIANGULO RECTANGULO\n");
		system("pause");
	}
	if ((x*x)>(y*y)+(z*z)) {
		printf ("TRIANGULO OBTUSANGULO\n");
		system("pause");
	}
	if ((x*x)<((y*y)+(z*z))) {
		printf ("TRIANGULO ACUTANGULO\n");
		system("pause");
	}
	if (x==y && y==z) {
		printf("TRIANGULO EQUILATERO\n");
		system("pause");
	}
	if ((x==y && y!=z)||(x!=y && y==z)||(z!=y && x==z)) {
		printf ("TRIANGULO ISOSCELES\n");
		system("pause");
	}

	system ("cls");

	

	system("pause");
	return 0;
}
