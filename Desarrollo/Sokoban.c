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
// PROTOTIPOS DE FUNCIONES 
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
     			  	 {1, 0, 0, 0, 0, 5, 0, 5, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 5, 0, 5, 5, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 5, 0, 6, 6, 6, 6, 0, 5, 0, 0, 1}, //7,7=mitad contando desde cero;
     			  	 {1, 0, 0, 0, 0, 0, 6, 6, 6, 6, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 5, 0, 6, 6, 6, 6, 5, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 0, 0, 1},
     			  	 {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
     			  	 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
     		//0=espacio;   1=muro;   2= jugador;  5=caja;  6=puntoestrella;
     			  	 copiarmapita (map, mat);						
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
    printf ("\tcajas=%d", contcajas);
} // VOID IMPRIMIR
//------------------------------------------


int juego (int mat[PF][PC], int nivel) {
	//DECLARACION DE VARIABLES:
	int jf, jc, cf, cc, contcajas, i, j, matestrella[PF][PC], contcajitas;
	char resp;
	
	//inicializacion de variables:
	contcajas=0;
	contcajitas=0;
	cf=20;
	cc=20;
	jf=11;
	jc=7;
	mat[jf][jc]=2;
	
	for (i=0; i<PF; i++) {
		for (j=0; j<PF; j++) {
			matestrella[i][j]=mat[i][j];
			if (matestrella[i][j]==6) {
				matestrella[i][j]=6;
			}
			if (matestrella[i][j]==5) {
				contcajitas=contcajitas+1;
			}
		} //for J=0
	} //for para copiar matestrella[i][j]
	imprimir (mat, contcajas);
	//tecla de juego :
	resp=0;
	while (resp!='x') {
		mat[jf][jc]=0;  //borrado de personaje
	
		resp=getch(); //escaneo de tecla
		
  		//movimiento de jugador y cajita si hay:
  		if (resp==ARRI) {
  			if (mat[jf-1][jc]==0 || mat[jf-1][jc]==6) {
				jf--;	
			}
			else if (mat[jf-1][jc]==5) {
				cf=jf-1;
				cc=jc;
				mat[cf][cc]=0;
				if (mat[cf-1][cc]==0 || mat[cf-1][cc]==6) {
					cf--;
					jf--;	
				}
			}
		} // ARRIBA
		
  		if (resp==ABA) {
  			if (mat[jf+1][jc]==0 || mat[jf+1][jc]==6) {
  				jf++;	
			}
			else if (mat[jf+1][jc]==5) {
				cf=jf+1;
				cc=jc;
				mat[cf][cc]=0;
				if (mat[cf+1][cc]==0 || mat[cf+1][cc]==6) {
					cf++;
					jf++;	
				}
			}
		} // ABAJO
		
		if (resp==IZQ) {
  			if (mat[jf][jc-1]==0 || mat[jf][jc-1]==6) {
  				jc--;	
			}
			else if (mat[jf][jc-1]==5) {
				cf=jf;
				cc=jc-1;
				mat[cf][cc]=0;
				if (mat[cf][cc-1]==0 || mat[cf][cc-1]==6) {
					cc--;
					jc--;	
				}
			}
		} // IZQUIERDA
		
		if (resp==DER) {
  			if (mat[jf][jc+1]==0 || mat[jf][jc+1]==6) {
				jc++;	
			}
			else if (mat[jf][jc+1]==5) {
				cf=jf;
				cc=jc+1;
				mat[cf][cc]=0;
				if (mat[cf][cc+1]==0 || mat[cf][cc+1]==6) {
					cc++;
					jc++;
		
				}
			}
		} // DERECHA
		
		//Arreglo de los caracteres y contador de cajas:
		mat[cf][cc]=5;
  		mat[jf][jc]=2;
		contcajas=0;
		for (i=0; i<PF; i++) {
			for (j=0; j<PC; j++) {
				if (matestrella[i][j]==6 && mat[i][j]==0) {
					mat[i][j]=6;
				}
				if (matestrella[i][j]==6 && mat[i][j]==5) {
					contcajas++;
				}
			}
		}
		
		//condición de victoria:
		if (contcajas==contcajitas) {
			system ("cls");
			printf ("felicidades");
			system ("pause");
			return 0;
		}
		
		//imprimir y limpiado de pantalla:
		system ("cls");
		imprimir (mat, contcajas);
	} //while resp!='x';
	
} // INT JUEGO 
// ---------------------------------------
