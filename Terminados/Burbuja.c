//PROGRAMA MUY SIMPLE PARA ORDENAR NUMEROS UTILIZANDO EL METODO DE LA BURBUJA, SIN VALIDACION

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#define t 10
//librerias y define
//----------------------------------------


int main () {
	int i, j, opcion, a, vector[t], auxj;
	printf ("\t\tPrograma para ordenar numeros:\n");
	printf ("1.Menor a mayor.\n2.Mayor a menor.\n");
	scanf ("%d", &opcion);
	
	system ("CLS");
	
	printf ("Ingrese valores (maximo 10 y diferentes de 0) y un 0 al final para validar\n");
	
	for (i=0; i<t; i++) {
		scanf ("%d", &vector[i]);
		if (vector[i]==0) {
			break;
		}
	}//for para escanear los valores
	
	auxj=t-1; //inicializacion de auxj;
	
	for (i=0; i<t; i++) {
		for (j=0; j<auxj; j++) {
			if (vector[j+1]==0) {
				auxj=j-1;
				break;
			}//cuando sea '0' el valor en vector, se rompe ciclo y se acortan las repeticiones
			if (vector[j]>vector[j+1] && opcion==1) {	
				a=vector[j+1];
				vector[j+1]=vector[j];
				vector[j]=a;
			}//menor a mayor
			if (vector[j]<vector[j+1] && opcion==2) {
				a=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=a;
			}//mayor a menor
		}//for de chequeo e intercambio (si es necesario) de valores
	}//for de repeticiones del algoritmo
	printf ("\n");
	
	for (i=0; i<t; i++) {
		if (vector[i]==0) {
			break;
		}
		printf ("%d ", vector[i]);
	} //for para imprimir
	
	fflush (stdin);
	getch ();
}//int main
