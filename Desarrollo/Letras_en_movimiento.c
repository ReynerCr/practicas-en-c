#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include <windows.h>
#define t 100
//LIBRERIAS Y DEFINE
//-----------------------------------------


void gotoxy( int column, int line ) { //GOTOXY
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
  );
}

int wherex() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
     ))
    return -1;
  return result.X;
}

int wherey() {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
     ))
    return -1;
  return result.Y;
}
//FIN GOTOXY
//-----------------------------------------


void letras (int unsigned letra[t], char unsigned cadena[t]);
void imprimir (int mat[5][5], int i, int j);
void switches (char unsigned var, int mat[5][5], int i);
void copiarmat (int original[5][5], int copia[5][5], int i);
//PROTOTIPOS
//-----------------------------------------


int main () {
	char unsigned cadena[t];
	int unsigned letra[t], i;
	printf ("Ingrese lo que quiera ver: \n");
	strset (cadena, '\0');
	fflush (stdin);
	gets (cadena);
	system ("cls");
	
	for (i=0; i<t; i++) {
		if (cadena[i]=='\0') {
				break;
		}
		if ((cadena[i]>=65 && cadena[i]<=90) || (cadena[i]==164 || cadena[i]==165)) {
			letra[i]=cadena[i];
		}
	}
	letras(letra, cadena);
	printf ("\n\n\n%s", cadena);
	fflush (stdin);
	getch ();
	return 0;
} //INT MAIN
//-----------------------------------------


void letras (int unsigned letra[t], char unsigned cadena[t]) {
	int i, j, k , auxi, mat[5][5];
	char unsigned var;
	
	k=0;
	auxi=0;
	do {  //bucle de cadena
		for (i=auxi; i<5; i=auxi) { //avance en filas de la matriz
			for (j=0; j<5; j++) { //avance en columnas de la matriz
				if (cadena[k]=='\0') {
					auxi++;
					k=0;
					printf ("\n");
					break;
				}
				var=cadena[k];
				switches (var, mat, i);
				imprimir (mat, i, j);
				
				if (j==4) {
					printf ("   ");
					k++;
				}
			} //fin columnas
		}  //fin filas
	} while (auxi!=5); //fin bucle cadena
} //VOID LETRAS
//-----------------------------------------


void imprimir (int mat[5][5], int i, int j) {
	if (mat[i][j]==0) {
		printf (" ");
	}
	if (mat[i][j]==1) {
		printf ("%c", 250);
	}
	if (mat[i][j]==4) {
		printf ("%c", 126);
	}
} //VOID IMPRIMIR
//-----------------------------------------


void switches (char unsigned var, int mat[5][5], int i) {
	int A[5][5]={{0, 0, 1, 0, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0}};
				 
	int B[5][5]={{0, 1, 1, 0, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 0, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 0, 0}};
				 
	int C[5][5]={{0, 0, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 0, 1, 1, 0}};
				 
	int D[5][5]={{0, 1, 1, 0, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 0, 0}};
				 
	int E[5][5]={{0, 1, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 1, 0}};
				 
	int F[5][5]={{0, 1, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0}};
	
	int G[5][5]={{0, 1, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 1, 0}};
				 
	int H[5][5]={{0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0}};
				 
	int I[5][5]={{0, 1, 1, 1, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 1, 1, 1, 0}};
	
	int J[5][5]={{0, 1, 1, 1, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 1, 1, 0, 0}};
				 
	int K[5][5]={{0, 1, 0, 1, 0},
				 {0, 1, 1, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 0, 0},
				 {0, 1, 0, 1, 0}};
				 
	int L[5][5]={{0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 1, 0}};
				 
	int M[5][5]={{1, 0, 0, 0, 1},
				 {1, 1, 0, 1, 1},
				 {1, 0, 1, 0, 1},
				 {1, 0, 0, 0, 1},
				 {1, 0, 0, 0, 1}};
				 
	int N[5][5]={{0, 1, 0, 0, 1},
				 {0, 1, 0, 0, 1},
				 {0, 1, 1, 0, 1},
				 {0, 1, 0, 1, 1},
				 {0, 1, 0, 0, 1}};
				 
	int N1[5][5]={{0, 1, 4, 4, 1},
				  {0, 1, 0, 0, 1},
				  {0, 1, 1, 0, 1},
				  {0, 1, 0, 1, 1},
				  {0, 1, 0, 0, 1}};
				 
	int O[5][5]={{0, 1, 1, 0, 0},
				 {1, 0, 0, 1, 0},
				 {1, 0, 0, 1, 0},
				 {1, 0, 0, 1, 0},
				 {0, 1, 1, 0, 0}};
				 
	int P[5][5]={{0, 1, 1, 0, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 0, 0, 0}};
				 
	int Q[5][5]={{0, 1, 1, 0, 0},
				 {1, 0, 0, 1, 0},
				 {1, 0, 1, 1, 0},
				 {1, 0, 0, 1, 0},
				 {0, 1, 1, 0, 1}};
	
	int R[5][5]={{0, 1, 1, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 1, 1, 0},
				 {0, 1, 1, 0, 0},
				 {0, 1, 0, 1, 0}};
	
	int S[5][5]={{0, 0, 1, 1, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 0, 0},
				 {0, 0, 0, 1, 0},
				 {0, 1, 1, 0, 0}};
				 
	int T[5][5]={{0, 1, 1, 1, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0}};
				 
	int U[5][5]={{0, 1, 0, 0, 1},
				 {0, 1, 0, 0, 1},
				 {0, 1, 0, 0, 1},
				 {0, 1, 0, 0, 1},
				 {0, 0, 1, 1, 0}};
	
	int V[5][5]={{1, 0, 0, 0, 1},
				 {1, 0, 0, 0, 1},
				 {1, 0, 0, 0, 1},
				 {0, 1, 0, 1, 0},
				 {0, 0, 1, 0, 0}};
	
	int W[5][5]={{1, 0, 0, 0, 1},
				 {1, 0, 0, 0, 1},
				 {1, 0, 1, 0, 1},
				 {1, 0, 1, 0, 1},
				 {0, 1, 0, 1, 0}};
				 
	int X[5][5]={{0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 0, 1, 0, 0},
				 {0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0}};
				 
	int Y[5][5]={{0, 1, 0, 1, 0},
				 {0, 1, 0, 1, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0},
				 {0, 0, 1, 0, 0}};
				 
	int Z[5][5]={{0, 1, 1, 1, 0},
				 {0, 0, 0, 1, 0},
				 {0, 0, 1, 0, 0},
				 {0, 1, 0, 0, 0},
				 {0, 1, 1, 1, 0}};	
	
	switch (var) {
		case 'A':
			copiarmat (A, mat, i);
			break;
		
		case 'B':
			copiarmat (B, mat, i);
			break;
			
		case 'C':
			copiarmat (C, mat, i);
			break;
			
		case 'D':
			copiarmat (D, mat, i);
			break;
		
		case 'E':
			copiarmat (E, mat, i);
			break;
		
		case 'F':
			copiarmat (F, mat, i);
			break;
			
		case 'G':
			copiarmat (G, mat, i);
			break;
			
		case 'H':
			copiarmat (H, mat, i);
			break;
		
		case 'I':
			copiarmat (I, mat, i);
			break;
			
		case 'J':
			copiarmat (J, mat, i);
			break;
			
		case 'K':
			copiarmat (K, mat, i);
			break;
		
		case 'L':
			copiarmat (L, mat, i);
			break;
			
		case 'M':
			copiarmat (M, mat, i);
			break;
			
		case 'N':
			copiarmat (N, mat, i);
			break;
		
		case 165:
			copiarmat (N1, mat, i);
			break;
			
		case 'O':
			copiarmat (O, mat, i);
			break;
			
		case 'P':
			copiarmat (P, mat, i);
			break;
		
		case 'Q':
			copiarmat (Q, mat, i);
			break;
			
		case 'R':
			copiarmat (R, mat, i);
			break;
			
		case 'S':
			copiarmat (S, mat, i);
			break;
		
		case 'T':
			copiarmat (T, mat, i);
			break;
			
		case 'U':
			copiarmat (U, mat, i);
			break;
			
		case 'V':
			copiarmat (V, mat, i);
			break;
		
		case 'W':
			copiarmat (W, mat, i);
			break;
			
		case 'X':
			copiarmat (X, mat, i);
			break;
			
		case 'Y':
			copiarmat (Y, mat, i);
			break;
		
		case 'Z':
			copiarmat (Z, mat, i);
			break;
	}
} //VOID SWITCHES
//-----------------------------------------


void copiarmat (int original[5][5], int copia[5][5], int i) {
	int j;
	for (j=0; j<5; j++) {
		copia[i][j]=original[i][j];
	}
} //VOID COPIARMAT
//-----------------------------------------
