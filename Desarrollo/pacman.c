#include <stdio.h >  //librerías
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
#define PF 23  //PUNTO FILA
#define PC 21  //PUNTO COLUMNA
#define ABA 80  //flecha
#define ARRI 72 //flecha
#define DER 77  //flecha
#define IZQ 75  //flecha
#define a 201  //esquina
#define b 205  //barra horizontal
#define c 187  //esquina
#define d 186  //barra vertical
#define f 200  //esquina
#define g 188  //esquina
#define o 167  //comestibles
#define p 64   //pacman
#define v 202  //"t"
#define y 204  //"t"
#define z 185  //"t"
#define h 203  //"t"
#define n 196  //cierre de cajita fantasmas
#define t 79   //"t"
#define k 32   //espacio
#define q 225  //fantasma 1
#define r 81   //fantasma 2
#define s 227  //fantasma 3
#define u 169  //fantasma 4

void mapita (int mat[PF][PC], int nivel);
int copiarmapita (int orig[PF][PC], int copia[PF][PC]);
void imprimir (int mat[PF][PC], int contdin, int contvid);
void fantasmatonto (int mat[PF][PC], int *qf, int *qc, int *dirq);
int juego (int mat[PF][PC], int nivel);

// DECLARACION DE FUNCIONES
// ---------------------------------------------


int main(int argc, char *argv[]) {
	int mat[PF][PC], nivel;
	printf ("Controles:\n\nArriba\t\tAbajo\nIzquierda\tDerecha\nPulse una tecla DIFERENTE a las FLECHAS para continuar.\nPulse X para salir.");
	system ("pause");
	system ("cls");
	fflush (stdin);
	mapita (mat, nivel);
	juego (mat, nivel);
	return 0;
} // INT MAIN
//--------------------------------------- 


void mapita (int mat[PF][PC], int nivel) {
	int map[PF][PC]={{a, b, b, b, b, b, b, b, b, b, h, b, b, b, b, b, b, b, b, b, c},  //20 contando desde 0
      				 {d, o, o, o, o, o, o, o, o, o, d, o, o, o, o, o, o, o, o, o, d},
      			 	 {d, o, a, b, c, o, a, b, c, o, d, o, a, b, c, o, a, b, c, o, d},
     				 {d, t, d, k, d, o, d, k, d, o, d, o, d, k, d, o, d, k, d, t, d},
      				 {d, o, f, b, g, o, f, b, g, o, d, o, f, b, g, o, f, b, g, o, d},
      				 {d, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, d},
        			 {d, o, b, b, b, o, d, o, b, b, h, b, b, o, d, o, b, b, b, o, d},
        			 {d, o, o, o, o, o, d, o, o, o, d, o, o, o, d, o, o, o, o, o, d},
      			  	 {f, b, b, b, c, o, y, b, b, k, d, k, b, b, z, o, a, b, b, b, g},
      			  	 {k, k, k, k, d, o, d, k, k, k, q, k, k, k, d, o, d, k, k, k, k},
      				 {b, b, b, b, g, o, d, k, a, n, n, n, c, k, d, o, f, b, b, b, b},
      			  	 {k, k, k, k, k, o, k, k, d, r, s, u, d, k, k, o, k, k, k, k, k},  //12 mitad u 11 contando desde 0
      			  	 {b, b, b, b, c, o, d, k, f, b, b, b, g, k, d, o, a, b, b, b, b},  
     			  	 {k, k, k, k, d, o, d, k, k, k, k, k, k, k, d, o, d, k, k, k, k},
      			  	 {a, b, b, b, g, o, d, k, b, b, h, b, b, k, d, o, f, b, b, b, c},  
      			  	 {d, o, o, o, o, o, o, o, o, o, d, o, o, o, o, o, o, o, o, o, d},
     			  	 {d, o, b, b, c, o, b, b, b, o, d, o, b, b, b, o, a, b, b, o, d}, 
     			  	 {d, t, o, o, d, o, o, o, o, o, p, o, o, o, o, o, d, o, o, t, d},
     			  	 {y, b, b, o, d, o, d, o, b, b, h, b, b, o, d, o, d, o, b, b, z},
     			     {d, o, o, o, o, o, d, o, o, o, d, o, o, o, d, o, o, o, o, o, d},
     			  	 {d, o, b, b, b, b, v, b, b, o, d, o, b, b, v, b, b, b, b, o, d},
     			  	 {d, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, d},
     			  	 {f, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, b, g}};
     			  	 
     			  	 copiarmapita (map,mat);						
} // VOID MAPITA
//--------------------------------------


int copiarmapita (int orig[PF][PC], int copia[PF][PC]) {
	int i,j;
	for(i=0;i<PF;i++)
		for(j=0;j<PC;j++)
			copia[i][j]=orig[i][j];
} // INT COPIARMAPITA
//---------------------------------


void imprimir (int mat[PF][PC], int contdin, int contvid) {
	int i, j;
	for (i=0; i<PF; i++) {
		printf ("\n"); 
		for (j=0; j<PC; j++) {
			printf ("%c", mat[i][j]);
   		}
    }
    printf ("\n\n%c=%d/172\t\t@=%d", o, contdin, contvid);
} // VOID IMPRIMIR
//---------------------------------


void fantasmatonto (int mat [PF][PC], int *qf, int *qc, int *dirq) {
	int qf1, qc1;
	qf1=*qf;
  	qc1=*qc;
  	
	while (*qf==qf1 && *qc==qc1) {
		// AÑADIR QUE VERIFIQUE SI PUEDE CAMBIAR DE DIRECCION EN CASO DE TENER CASILLA LIBRE A SUS LADOS.
		 	if (*dirq==0) {
	 	 		if (*qf==11 && *qc==0) {
					*qf=11;
					*qc=20;
				}
	 	 		if (mat[*qf][*qc-1]==k || mat[*qf][*qc-1]==o) {
	 	 			*qc--;
				}
				else {
	 		 		*dirq=rand()%4;
				}
			} //DIRQ IZQUIERDA
			
			if (*dirq==1) {
				if (*qf==11 && *qc==20) {
					*qf=11;
					*qc=0;
				}
				if (mat[*qf][*qc+1]==k || mat[*qf][*qc+1]==o) {
					/* if (mat[qf][qc+1]==o) {
						bolita1++;
					} */
					*qc++;
				}
				else {
	 	 			*dirq=rand()%4;
				}
			} //DIRQ DERECHA
		
			if (*dirq==2) {
				if (mat[*qf+1][*qc]==k || mat[*qf+1][*qc]==o) {
					/*if (mat[qf+1][qc]==o) {
						bolita2++;
						dirq1++;
				    } */
					*qf++;
				}
				else {
	 	 			*dirq=rand()%4;
				}
			} //DIRQ ABAJO
			
			if (*dirq==3) {
				if (mat[*qf-1][*qc]==k || mat[*qf-1][*qc]==o) {
					/*if (mat[qf-1][qc]==o) {
						bolita3++;
						dirq1++;	
					} */
					*qf--;
				}
				else {
	 	 			*dirq=rand()%4;
				}
			} //DIRQ ARRIBA
	} //while qf==qf1 && qc==q1
} // INT FANTASMATONTO
//-------------------------------------


int juego (int mat[PF][PC], int nivel) {
	//DECLARACION DE VARIABLES
	int pj, jc, jf, qf, qc, contdin, contvid, dirq;
	char resp;
	contdin=0;
	contvid=3;
	jf=17;
	jc=10;
	qf=9;
	qc=10;
	mat [jf][jc]=p;
	mat [qf][qc]=q;
	imprimir (mat, contdin, contvid);
	
	//tecla, juego 
	resp=0;
	srand(time(NULL));
  	
  	
	while(resp!='x') {
  		mat[jf][jc]=k;
  		mat[qf][qc]=k;
  		
		// escaneo de tecla contínuo
		if (kbhit()) {
			resp=getch();
  		}
  		else {
  			resp=resp;
		}
		
  		//control del personaje y condiciones de victoria/derrota.
  		if (resp==ABA) {
   			if (mat[jf+1][jc]==o || mat[jf+1][jc]==k) {
    			if (mat[jf+1][jc]==o) {
    				contdin++;
    			   		if (contdin==172) {
    						system ("CLS");
    						printf ("Felicitaciones.\n");
    						system ("pause"); 
    						return 0;
    					}			   
				}
				jf++;
			}
   	
		}  //ABAJO
		
  		if (resp==ARRI) {
  			 if (mat[jf-1][jc]==o || mat[jf-1][jc]==k) {
    			if (mat[jf-1][jc]==o) {
    				contdin++;
    				if (contdin==172) {
    					system ("CLS");
   						printf ("Felicitaciones.\n");
    					system ("pause");
    					return 0; 
   					}  
				}
			jf--;
   			}
  		} //ARRIBA
  		
  		if (resp==DER) {
			if (jf==11 && jc==20) {
				jf=11;
				jc=0;
			}
   			else if (mat[jf][jc+1]==o || mat[jf][jc+1]==k) {
    			if (mat[jf][jc+1]==o) {
    				contdin++;
    				if (contdin==172) {
    					system ("CLS");
    					printf ("Felicitaciones.\n");
    					system ("pause");
 						return 0;
    				}	
				}
    			jc++;
			}	
  		} //DERECHA
  		
  		if (resp==IZQ) {
  			if (jf==11 && jc==0) {
				jf=11;
				jc=20;
			}
   			else if (mat[jf][jc-1]==o || mat[jf][jc-1]==k) {
    			if (mat[jf][jc-1]==o) {
					contdin++;
					if (contdin==172) {
    						system ("CLS");
    						printf ("Felicitaciones.\n");
   	 						system ("pause"); 
    						return 0;
    				}
    			}
				jc--;
			}
 	 	} // IZQUIERDA
 	 	
		fantasmatonto (mat, &qf, &qc, &dirq);
	
		////// que dirq1=dirq y entonces al verific|ar que numero era, este no cambie HASTA QUE map[qf+-][qc+-]!=k || o;
 	 	// CUANDO ESTÉ A 4 CASILLAS DE DISTANCIA DE PACMAN, QUE LE PERSIGA if matqf-4==FJ {seguir pacman}; 
	
		//reimpresión de mapita
		printf ("   %d", dirq);
		system ("pause");
		system("CLS");
		mat[jf][jc]=p;
		mat[qf][qc]=q; 
		imprimir (mat, contdin, contvid);		
		Sleep (500);
	} //while resp!='x'
} // INT JUEGO 
// ------------------------------------
