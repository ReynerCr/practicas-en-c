#include <stdio.h >  //librerías
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define PF 15 //PUNTO FILA
#define PC 15 //PUNTO COLUMNA
#define ABA 80  //flecha abajo
#define ARRI 72 //flecha arriba
#define DER 77  //flecha derecha
#define IZQ 75  //flecha izquierda
// FIN LIBRERIAS Y DEFINE
//---------------------------------------------

void mapita (int mat[PF][PC], int nivel);
int copiarmapita (int orig[PF][PC], int copia[PF][PC]);
void imprimir (int mat[PF][PC], int contcajas);
int juego (int mat[PF][PC], int nivel);
// DECLARACION DE FUNCIONES
// ---------------------------------------------

int main() {
	int mat[PF][PC], nivel;
	fflush (stdin);
	mapita (mat, nivel);
	juego (mat, nivel);
	return 0;
} // INT MAIN
//----------------------------------------------


void mapita (int mat[PF][PC], int nivel) {
	int map[PF][PC]={{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 5, 0, 0, 0, 5, 0, 0, 0, 0, 1}, //7,7=mitad contando desde cero;
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 6, 1},
     			  	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
     			  	 
     			  	 copiarmapita (map,mat);						
} // VOID MAPITA
//------------------------------------------


int copiarmapita (int orig[PF][PC], int copia[PF][PC]) {
	int i,j;
	for(i=0;i<PF;i++)
		for(j=0;j<PC;j++)
			copia[i][j]=orig[i][j];
} // INT COPIARMAPITA
//------------------------------------------


void imprimir (int mat[PF][PC], int contcajas) {
	int i, j;
	for (i=0; i<PF; i++) {
		printf ("\n");
		for (j=0; j<PC; j++) {
			if (mat[i][j]==1) {
				printf ("#");
			}
			if (mat[i][j]==0) {
				printf (" ");
			}
			if (mat[i][j]==2) {
				printf ("@");
			}
			if (mat[i][j]==5) {
				printf ("€");
			}
			if (mat[i][j]==6) {
				printf ("*");
			}
   		}
    }
    printf ("cajas=%d", contcajas);
} // VOID IMPRIMIR
//------------------------------------------


int juego (int mat[PF][PC], int nivel) {
	//DECLARACION DE VARIABLES
	int jf, jc, cf, cc, contcajas;
	char resp;
	contcajas=0;
	cf=20;
	cc=20;
	jf=13;
	jc=11;
	mat[jf][jc]=2;
	imprimir (mat, contcajas);
	
	//tecla de juego 
	resp=0;
	while (resp!='x') {
		mat[jf][jc]=0;
		
		// escaneo de tecla contínuo
		//if (kbhit()) 
			resp=getch();
  		
  		//movimiento de jugador y cajita si hay
  		if (resp==ARRI) {
  			if (mat[jf-1][jc]==0) {
  				jf--;	
			}
			else if (mat[jf-1][jc]==5) {
				cf=jf-1;
				cc=jc;
				mat[cf][cc]=0;
				if (mat[cf-1][cc]==0) {
					cf--;
					jf--;	
				}
			}
		} // ARRIBA
		
  		if (resp==ABA) {
  			if (mat[jf+1][jc]==0) {
  				jf++;	
			}
			else if (mat[jf+1][jc]==5) {
				cf=jf+1;
				cc=jc;
				mat[cf][cc]=0;
				if (mat[cf+1][cc]==0) {
					cf++;
					jf++;	
				}
			}
		} // ABAJO
		
		if (resp==IZQ) {
  			if (mat[jf][jc-1]==0) {
  				jc--;	
			}
			else if (mat[jf][jc-1]==5) {
				cf=jf;
				cc=jc-1;
				mat[cf][cc]=0;
				if (mat[cf][cc-1]==0) {
					cc--;
					jc--;	
				}
			}
		} // IZQUIERDA
		
		if (resp==DER) {
  			if (mat[jf][jc+1]==0) {
  				jc++;	
			}
			else if (mat[jf][jc+1]==5) {
				cf=jf;
				cc=jc+1;
				mat[cf][cc]=0;
				if (mat[cf][cc+1]==0 || mat[cf][cc+1]==6) {
					if (mat[cf][cc+1]==6) {
						contcajas++;
					}
					cc++;
					jc++;
				}
			}
		} // DERECHA
		
		
  		system ("cls");
  		mat[cf][cc]=5;
  		mat[jf][jc]=2;
		imprimir (mat, contcajas);
		Sleep (80);
	}
	
} // INT JUEGO 
// ---------------------------------------

