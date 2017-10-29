#include <stdio.h>
#include <stdlib.h>
#include <conio.h>


int esq1 (int *N, int mat[*N][*N]);
int esq2 (int *N, int mat[*N][*N]);
int esq3 (int *N, int mat[*N][*N]);
int esq4 (int *N, int mat[*N][*N]);
//PROTOTIPOS ------------------------


int main () {
	int cont, esq, N, nesq, cargar, i, j, vector[200], naux, qaux;
	naux=0;
	qaux=1;
	cont=0;
	scanf ("%d", &cargar);
	
	do {  //DO PARA CONTADOR
		cont++;
		scanf ("%d", &nesq);
		esq=nesq%10;
		if (nesq<=99) {
			N=(nesq/10)%10;
		}
		
		else {
			N=nesq/10;
		}
		vector[naux]=N;
		vector[qaux]=esq;
		naux=naux+2;
		qaux=qaux+2;
	} while (cont<cargar); //CIERRE DE DO PARA REPETICIONES//DO PARA CONTADOR
	printf ("\n");
	naux=0;
	qaux=1;
	cont=0;
	
	do {
		cont++;
		N=vector[naux];
		esq=vector[qaux];
	
		naux=naux+2;
		qaux=qaux+2;
		if ((N<1 || N>15) || N%2==0 || (esq<1 || esq>4)) {
			printf ("No se pudo procesar alguno de los datos\n\n");
			continue;
		}
		int mat[N][N];	
		
		for (i=0; i<N; i++) { //inicialización
			for (j=0; j<N; j++) {
				mat[i][j]=0;
			}
		} //fin inicialización
		switch (esq) { //switch
			case 1:
				esq1 (&N, mat);
				break;
			
			case 2:
				esq2 (&N, mat);
				break;
				
			case 3:
				esq3 (&N, mat);
				break;
			
			case 4:
				esq4 (&N, mat);
				break;
				
			default: 
				printf ("\nNo se pudo procesar\n");
				break;
		} //Switch
		
		for (i=0; i<N; i++) { //imprimir
			for (j=0; j<N; j++) {
				if (mat[i][j]<=9) {
					printf ("%d   ", mat[i][j]);
				}
				else if (mat[i][j]>=10 && mat[i][j]<100) {
					printf ("%d  ", mat[i][j]);
				}
				else if (mat[i][j]>=100) {
					printf ("%d ", mat[i][j]);
				}
			}
			printf ("\n");
		} //fin imprimir
		printf ("\n");
	} while (cont<cargar);
	fflush (stdin);
	getch ();	
	return 0;
}
//INT MAIN
//-----------------------------


int esq1 (int *N, int mat[*N][*N]) {
	int auxi, auxj, i, j, k;
	k=1;
	auxi=0;
	auxj=0;	
	
	do { //ciclo para llenado
		for (j=auxj; j<*N; j++) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxi++;
				auxj=j-1;
				break;
			}
			if (j==*N-1) {
				auxi++;
					auxj=j;
				break;
			}
		} //DERECHA
		
		for (i=auxi; i<*N; i++) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i-1;
				auxj--;
				break;
			}
			if (i==*N-1) {
				auxi=i;
				auxj--;
			}
		} //ABAJO
		
		for (j=auxj; j>=0; j--) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxj=j+1;
				auxi--;
				break;
			}
			if (j==0) {
				auxj=j;
				auxi--;
				break;
			}
		} //IZQUIERDA
		
		for (i=auxi; i>=0; i--) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i+1;
				auxj++;
				break;
			}
		} //ARRIBA
			
	} while (k!=*N*(*N)+1); //fin ciclo para llenado
} //INT esq1
//--------------------------------------

int esq2 (int *N, int mat[*N][*N]) {
	int auxi, auxj, i, j, k;
	k=1;
	auxi=0;
	auxj=*N-1;	
	
	do { //ciclo para llenado
		for (i=auxi; i<*N; i++) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i-1;
				auxj--;
				break;
			}
			if (i==*N-1) {
				auxi=i;
				auxj--;
			}
		} //ABAJO
		
		for (j=auxj; j>=0; j--) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxj=j+1;
				auxi--;
				break;
			}
			if (j==0) {
				auxj=j;
				auxi--;
				break;
			}
		} //IZQUIERDA
	
		for (i=auxi; i>=0; i--) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i+1;
				auxj++;
				break;
			}
			if (i==0) {
				auxi=i;
				auxj++;
				break;
			}
		} //ARRIBA
	
		for (j=auxj; j<*N; j++) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxi++;
				auxj=j-1;
				break;
			}
			if (j==*N-1) {
				auxi++;
				auxj=j;
				break;
			}
		} //DERECHA
		
	} while (k!=*N*(*N)+1); //fin ciclo para llenado
} //INT esq2
//----------------------------

int esq3 (int *N, int mat[*N][*N]) {
	int auxi, auxj, i, j, k;
	k=1;
	auxi=*N-1;
	auxj=*N-1;	
	
	do { //ciclo para llenado
		
		for (j=auxj; j>=0; j--) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxj=j+1;
				auxi--;
				break;
			}
			if (j==0) {
				auxj=j;
				auxi--;
				break;
			}
		} //IZQUIERDA
	
		for (i=auxi; i>=0; i--) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i+1;
				auxj++;
				break;
			}
			if (i==0) {
				auxi=i;
				auxj++;
				break;
			}
		} //ARRIBA
	
		for (j=auxj; j<*N; j++) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxi++;
				auxj=j-1;
				break;
			}
			if (j==*N-1) {
				auxi++;
				auxj=j;
				break;
			}
		} //DERECHA
		
		for (i=auxi; i<*N; i++) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i-1;
				auxj--;
				break;
			}
			if (i==*N-1) {
				auxi=i;
				auxj--;
			}
		} //ABAJO
		
	} while (k!=*N*(*N)+1); //fin ciclo para llenado
} //INT esq3
//----------------------------

int esq4 (int *N, int mat[*N][*N]) {
	int auxi, auxj, i, j, k;
	k=1;
	auxi=*N-1;
	auxj=0;	
	
	do { //ciclo para llenado
	
		for (i=auxi; i>=0; i--) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i+1;
				auxj++;
				break;
			}
			if (i==0) {
				auxi=i;
				auxj++;
				break;
			}
		} //ARRIBA
	
		for (j=auxj; j<*N; j++) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxi++;
				auxj=j-1;
				break;
			}
			if (j==*N-1) {
				auxi++;
				auxj=j;
				break;
			}
		} //DERECHA
		
		for (i=auxi; i<*N; i++) {
			if (mat[i][auxj]==0) {
				mat[i][auxj]=k;
				k++;
			}
			else {
				auxi=i-1;
				auxj--;
				break;
			}
			if (i==*N-1) {
				auxi=i;
				auxj--;
			}
		} //ABAJO
		
		for (j=auxj; j>=0; j--) {
			if (mat[auxi][j]==0) {
				mat[auxi][j]=k;
				k++;
			}
			else {
				auxj=j+1;
				auxi--;
				break;
			}
			if (j==0) {
				auxj=j;
				auxi--;
				break;
			}
		} //IZQUIERDA
		
	} while (k!=*N*(*N)+1); //fin ciclo para llenado
} //INT esq4
//----------------------------
