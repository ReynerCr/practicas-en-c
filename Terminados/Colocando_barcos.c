#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
//LIBRERIAS
//----------------------------------------


typedef struct {
	int pf, pc;
}barco;
//ESTRUCTURA
//----------------------------------------


void pedir_datos (barco *x);
void comprobarmayor (int vector[300], int *valor);
void imprimir (int vect[300]);
void inicializar (int vector[300]);
//PROTOTIPOS
//----------------------------------------


int main () {
	int casosp, i, j, contador, valor, vect[300], vector[300], pf, pc;
	contador=0;
	inicializar (vect);
	do {
		fflush (stdin);
		scanf ("%d", &casosp);
		barco B[casosp];
		inicializar (vector);
		if (casosp>=2 && casosp<=1000) {
			for (i=0; i<casosp; i++) {
				pedir_datos (&B[i]);
			}//for i=0
			for (i=0; i<casosp; i++) {
				for (j=i; j<casosp; j++) {
					
					//condiciones para hallar las distancias de cada punto
					if (B[i].pf>B[j].pf)
						pf=B[i].pf-B[j].pf;
					else 
						pf=B[j].pf-B[i].pf;
						
					if (B[i].pc>B[j].pc)
						pc=B[i].pc-B[j].pc;
					else
						pc=B[j].pc-B[i].pc;
		
					//suma de las distancias y unión en vector para luego comparar la mayor con el método de la burbuja
					vector[j]=pf+pc;
				} //for j=0
				comprobarmayor (vector, &valor);
			} //for i=0
			vect[contador]=valor;
 		} //if casosp
		contador++;	
 		printf ("\n");
	} while (casosp!=0);
	imprimir (vect);	
	fflush (stdin);
	system ("pause");
} //INT MAIN
//----------------------------------------


void pedir_datos (barco *x) {
	scanf ("%d %d", &x->pf, &x->pc);
}//VOID PEDIR_DATOS
//----------------------------------------


void comprobarmayor (int vector[300], int *valor) {
	int i, j, auxj, a;
	auxj=300;
	for (i=0; i<300-1; i++) {
		for (j=0; j<auxj; j++) {
			if (vector[j+1]==-1) {
				auxj=j-1;
				break;
			}//cuando sea -1 el valor en vector, se rompe ciclo y se acortan las repeticiones
			if (vector[j]<vector[j+1]) {
				a=vector[j];
				vector[j]=vector[j+1];
				vector[j+1]=a;
			}//mayor a menor
		}//for de chequeo e intercambio (si es necesario) de valores
	}//for de repeticiones del algoritmo
	*valor=vector[0];
}//VOID IMPRIMIR
//----------------------------------------


void imprimir (int vect[300]) {
	int i;
	printf ("\n");
	for (i=0; i<300; i++) {
		if (vect[i]==-1) {
			break;
		}
		printf ("%d\n", vect[i]);
	}
}//VOID IMPRIMIR
//----------------------------------------


void inicializar (int vector[300]) {
	int i;
	for (i=0; i<300; i++) {
		vector[i]=-1;
	}
}//VOID INICIALIZAR
//----------------------------------------
