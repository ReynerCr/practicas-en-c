#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#define T 20

void letras (char unsigned vector[T], int letra);

int main () {
	char unsigned cadena[T]; 
	int unsigned letra, i;
	printf ("Ingrese lo que quiera ver: \n");
	strset (cadena, '\0');
	fflush (stdin);
	gets (cadena);
	system ("cls");
	for (i=0; i<T; i++) {
		if (cadena[i]=='\0') {
				break;
		}
		if ((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]==164 || cadena[i]==165)) {
			letra=cadena[i];
		}
	}
	printf ("%s", cadena);
	fflush (stdin);
	getch ();
	return 0;
}
