#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>

int main () {
	int ascii1, ascii2, contdig, x, i, j, k, contvoc, contlet, contesp;
	char cad[300];
	printf ("Ingrese su cadenita: \n");
	fflush (stdin);
	gets(cad);
	fflush (stdin);
	x=strlen(cad);
	contdig=0;
	contvoc=0;
	contlet=0;
	contesp=1;
	strlwr(cad);
	
	for(i=0;i<x;i++){
		if (isdigit(cad[i])) {
			contdig++;
		}
		
		if (cad[i]=='a' || cad[i]=='e' || cad[i]=='i' || cad[i]=='o' || cad[i]=='u') {
			contvoc++;
		}
		if (isalpha(cad[i])) {
			contlet++;
		}
		if (cad[i]==' ') {
			contesp++;
		}
	}
	printf ("Vocales: %d\n", contvoc);
	printf ("Digitos: %d\n", contdig);
	printf ("Letras: %d\n", contlet);
	printf ("Palabras: %d\n", contesp);
system ("pause");
return 0;
}
