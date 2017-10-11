#include <stdio.h >  //librerías
#include <stdlib.h>
#include <conio.h>
#define ESC 27 // ESCAPE (tecla)
#define PF 11 //PUNTO FILA
#define PC 11 //PUNTO COLUMNA
#define ABA 80  //flecha abajo
#define ARRI 72 //flecha arriba
#define DER 77  //flecha derecha
#define IZQ 75  //flecha izquierda
#define B 176 //BLOQUE
#define C 254 //CAJA
#define J 153 //JUGADOR
// FIN LIBRERIAS Y DEFINE
//---------------------------------------------

void mapita (int mat[PF][PC], int *niv);
int copiarmapita (int orig[PF][PC], int copia[PF][PC]);
void imprimir (int mat[PF][PC], int *niv);
int juego (int mat[PF][PC], int *niv);
// PROTOTIPOS DE FUNCIONES 
// ---------------------------------------------

int main() {
	int mat[PF][PC], nivel;
	nivel=1;
	printf ("\t    Sokoban muy basico.\n\nCONTROLES:\t\t\tFIGURAS:\n\n-Flechas para moverse.\t\t-Jugador= %c\n-R para reiniciar.\t\t-Caja= %c\n-Escape para salir.\t\t-Muro= %c\n\t\t\t\t-Punto para caja= *\n\n\n", J, C, B);
	system ("pause");
	fflush (stdin);
	while (nivel<=5) {
		mapita (mat, &nivel);
		juego (mat, &nivel);
	}
	system ("cls");
	printf ("Gracias por jugar.\n");
	system ("pause");
	return 0;
} // INT MAIN
//----------------------------------------------


void mapita (int mat[PF][PC], int *niv) {

	//0=espacio;   1=muro;   2= jugador;  5=caja;  6=puntoestrella;
	
	int map1[PF][PC]={{1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
     			  	  {1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
     			  	  {1, 0, 5, 0, 0, 0, 5, 0, 1, 0, 0},
     			  	  {1, 0, 1, 1, 0, 0, 0, 0, 1, 1, 1},
     			  	  {1, 0, 0, 1, 0, 1, 1, 0, 6, 6, 1}, // 4 contando desde 0;
     			  	  {1, 0, 0, 0, 0, 0, 0, 0, 6, 6, 1}, // 5 contando desde 0;
     			  	  {1, 0, 0, 5, 1, 0, 5, 0, 6, 6, 1},
     			  	  {1, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1}, 
     			  	  {1, 1, 5, 1, 0, 5, 0, 0, 1, 0, 0},
     			  	  {1, 0, 0, 0, 0, 0, 0, 2, 1, 0, 0},
     			  	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0}};
	
	int map2[PF][PC]={{0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 0},
     			  	  {0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
     			  	  {0, 1, 2, 5, 0, 0, 0, 1, 6, 1, 0},
     			  	  {0, 1, 5, 5, 5, 5, 0, 1, 0, 1, 0},
     			  	  {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 4 contando desde 0;
     			  	  {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0}, // 5 contando desde 0;
     			  	  {0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0},
     			  	  {0, 1, 6, 0, 6, 0, 0, 0, 0, 1, 0}, 
     			  	  {0, 1, 1, 1, 1, 6, 0, 0, 6, 1, 0},
     			  	  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0},
     			  	  {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
	
	int map3[PF][PC]={{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
     			  	  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
     			  	  {1, 0, 5, 0, 1, 0, 0, 0, 0, 0, 0},
     			  	  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
     			  	  {1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0}, // 4 contando desde 0;
     			  	  {1, 0, 5, 0, 1, 1, 0, 0, 0, 0, 0}, // 5 contando desde 0;
     			  	  {1, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
     			  	  {1, 0, 5, 5, 5, 1, 1, 6, 6, 0, 1}, 
     			  	  {1, 0, 0, 0, 0, 0, 0, 0, 6, 6, 1},
     			  	  {1, 0, 0, 0, 1, 2, 1, 0, 0, 6, 1},
     			  	  {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    
    int map4[PF][PC]={{0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1},
     			  	  {0, 0, 0, 0, 0, 1, 0, 6, 6, 2, 1},
     			  	  {0, 0, 0, 0, 0, 1, 0, 5, 5, 0, 1},
     			  	  {0, 0, 0, 0, 0, 1, 1, 0, 1, 1, 1},
     			  	  {0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0}, // 4 contando desde 0;
     			  	  {0, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0}, // 5 contando desde 0;
     			  	  {0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 0},
     			  	  {0, 0, 0, 1, 0, 1, 0, 0, 0, 1, 0}, 
     			  	  {0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0},
     			  	  {0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0},
     			  	  {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 0}};
     			  	  
    int map5[PF][PC]={{1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
     			  	  {1, 2, 0, 0, 0, 0, 6, 1, 1, 1, 1},
     			  	  {1, 1, 1, 1, 0, 0, 0, 1, 6, 6, 1},
     			  	  {0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1},
     			  	  {0, 1, 0, 0, 0, 0, 0, 5, 0, 0, 1}, // 4 contando desde 0;
     			  	  {0, 1, 0, 0, 0, 5, 0, 1, 0, 0, 1}, // 5 contando desde 0;
     			  	  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
     			  	  {0, 1, 0, 5, 0, 5, 0, 5, 0, 0, 1}, 
     			  	  {0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 1},
     			  	  {0, 1, 6, 0, 0, 0, 0, 1, 6, 0, 1},
     			  	  {0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}};
    switch (*niv) {
    	case 1:
    		copiarmapita (map1, mat);
    		break;
    		
    	case 2: 
    		copiarmapita (map2, mat);
    		break;
    	
    	case 3:
    		copiarmapita (map3, mat);
    		break;
    	
    	case 4:
    		copiarmapita (map4, mat);
    		break;
    	
    	case 5:
    		copiarmapita (map5, mat);
    		break;
	} //switch (nivel)						
} // VOID MAPITA
//------------------------------------------


int copiarmapita (int orig[PF][PC], int copia[PF][PC]) {
	int i,j;
	for(i=0;i<PF;i++)
		for(j=0;j<PC;j++)
			copia[i][j]=orig[i][j];
} // INT COPIARMAPITA
//------------------------------------------


void imprimir (int mat[PF][PC], int *niv) {
	int i, j;
	system ("cls");
	for (i=0; i<PF; i++) {
		printf ("\n");
		for (j=0; j<PC; j++) {
			if (mat[i][j]==1) {
				printf ("%c", B);
			}
			if (mat[i][j]==0) {
				printf (" ");
			}
			if (mat[i][j]==2) {
				printf ("%c", J);
			}
			if (mat[i][j]==5) {
				printf ("%c", C);
			}
			if (mat[i][j]==6) {
				printf ("*");
			}
   		}
    }
    printf ("\n\n\tNivel=%d", *niv);
} // VOID IMPRIMIR
//------------------------------------------


int juego (int mat[PF][PC], int *niv) {
	//DECLARACION DE VARIABLES:
	int jf, jc, contcajas, i, j, matestrella[PF][PC], contcajitas, nivp;    //int jf=jugador fila;  jc==jugador columna;  contcajas= contador de cajas en posición;  contcajitas= contador de cajas totales;
	char resp;   //int matestrella= matriz auxiliar para realizar las comprobaciones;  nivp= puntero hacia nivel al momento de imprimir;        char resp= tecla ingresada;
	
	//inicializacion de variables:
	contcajas=0;
	contcajitas=0;
	nivp=*niv;
	
	for (i=0; i<PF; i++) {
		for (j=0; j<PF; j++) {
			matestrella[i][j]=mat[i][j];
			if (matestrella[i][j]==6) {
				matestrella[i][j]=6;
			}
			if (mat[i][j]==2) {
				jf=i;
				jc=j;
			}
			if (matestrella[i][j]==5) {
				contcajitas=contcajitas+1;
			}
		} //for J=0
	} //for para copiar matestrella[i][j]
	imprimir (mat, &nivp);
	//tecla de juego :
	resp=0;
	
	while (resp!=ESC && resp!='r' && resp!='R') {
		mat[jf][jc]=0;  //borrado de personaje
	
		resp=getch(); //escaneo de tecla
		
  		//movimiento de jugador y cajita si hay:
  		if (resp==ARRI) {
  			if (mat[jf-1][jc]==0 || mat[jf-1][jc]==6) {
				jf--;	
			}
			else if (mat[jf-1][jc]==5) {
				if (mat[jf-2][jc]==0 || mat[jf-2][jc]==6) {
					mat[jf-1][jc]=0;
					mat[jf-2][jc]=5;
					jf--;
				}
			}
		} // ARRIBA
		
  		if (resp==ABA) {
  			if (mat[jf+1][jc]==0 || mat[jf+1][jc]==6) {
  				jf++;	
			}
			else if (mat[jf+1][jc]==5) {
				if (mat[jf+2][jc]==0 || mat[jf+2][jc]==6) {
					mat[jf+1][jc]=0;
					mat[jf+2][jc]=5;
					jf++;	
				}
			}
		} // ABAJO
		
		if (resp==IZQ) {
  			if (mat[jf][jc-1]==0 || mat[jf][jc-1]==6) {
  				jc--;	
			}
			else if (mat[jf][jc-1]==5) {
				if (mat[jf][jc-2]==0 || mat[jf][jc-2]==6) {
					mat[jf][jc-1]=0;
					mat[jf][jc-2]=5;
					jc--;
				}
			}
		} // IZQUIERDA
		
		if (resp==DER) {
  			if (mat[jf][jc+1]==0 || mat[jf][jc+1]==6) {
				jc++;	
			}
			else if (mat[jf][jc+1]==5) {
				if (mat[jf][jc+2]==0 || mat[jf][jc+2]==6) {
					mat[jf][jc+1]=0;
					mat[jf][jc+2]=5;
					jc++;
				}
			}
		} // DERECHA
		
		//Arreglo de los caracteres y contador de cajas:
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
			} //for j;
		} //for i;
		
		//condición de victoria:
		if (contcajas==contcajitas) {
			system ("cls");
			printf ("Felicitaciones por completar el nivel %d\n", *niv);
			system ("pause");
			*niv=*niv+1;
			resp='r';
		}
		
		if (resp=='u') {
			*niv=*niv+1;
			resp='r';
		}
		
		//condición de salida:
		if (resp==ESC) {
			*niv=6;
		}
		
		imprimir (mat, &nivp); //imprimir
	} //while resp!=ESC || resp!='r'
	
} // INT JUEGO 
// ---------------------------------------
