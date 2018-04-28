#include <stdio.h >  //librerías
#include <stdlib.h>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#define PF 23  //PUNTO FILA
#define PC 21  //PUNTO COLUMNA
#define ABA 80  //flecha abajo
#define ARRI 72 //flecha arriba
#define DER 77  //flecha derecha
#define IZQ 75  //flecha izquierda
#define a 201  //esquina
#define b 205  //barra horizontal
#define c 187  //esquina
#define d 186  //barra vertical
#define f 200  //esquina
#define g 188  //esquina
#define o 250  //comestibles
#define p 64   //pacman
#define v 202  //"t"
#define y 204  //"t"
#define z 185  //"t"
#define h 203  //"t"
#define n 196  //cierre de cajita fantasmas
#define t 79   //powerup
#define k 32   //espacio
#define q 225  //fantasma 1
#define r 81   //fantasma 2
#define s 227  //fantasma 3
#define u 169  //fantasma 4
// FIN LIBRERIAS Y DEFINE
//---------------------------------------------

void mapita (int mat[PF][PC], int matcomp[PF][PC], int nivel);
void imprimir (int mat[PF][PC], int contdin, int contvid);
void fantasmatonto (int mat[PF][PC], int *ftf, int *ftc, int *dirft);
void fantasmainteligente (int mat [PF][PC], int *fit, int *fic, int *dirfi);
int juego (int mat[PF][PC], int nivel);
// DECLARACION DE FUNCIONES
// ---------------------------------------------



void gotoxy( int column, int line )
  {
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
  }

int wherex()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.X;
  }

int wherey()
  {
  CONSOLE_SCREEN_BUFFER_INFO csbi;
  COORD                      result;
  if (!GetConsoleScreenBufferInfo(
         GetStdHandle( STD_OUTPUT_HANDLE ),
         &csbi
         ))
    return -1;
  return result.Y;
  }
//GOTOXY
//-----------------------------------------------


int main() {
	int mat[PF][PC], matcomp[PF][PC], nivel;
	printf ("Controles:\n\nArriba\t\tAbajo\nIzquierda\tDerecha\nPulse una tecla DIFERENTE a las FLECHAS para continuar.\nPulse X para salir.");
	fflush (stdin);
	getch ();
	system ("cls");
	mapita (mat, matcomp, nivel);
	juego (mat, nivel);
	return 0;
} // INT MAIN
//----------------------------------------------


void mapita (int mat[PF][PC], int matcomp[PF][PC], int nivel) {
	//matriz para mostrar al usuario
	matcomp[PF][PC]={{a, b, b, b, b, b, b, b, b, b, h, b, b, b, b, b, b, b, b, b, c},  //20 contando desde 0
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
					
	   //matriz para comprobar cosillas				
	mat[PF][PC]={{a, b, b, b, b, b, b, b, b, b, h, b, b, b, b, b, b, b, b, b, c},  //20 contando desde 0
      				 	 {d, o, o, o, o, o, o, o, o, o, d, o, o, o, o, o, o, o, o, o, d},
	      			 	 {d, o, a, b, c, o, a, b, c, o, d, o, a, b, c, o, a, b, c, o, d},
	     				 {d, t, d, k, d, o, d, k, d, o, d, o, d, k, d, o, d, k, d, t, d},
	      				 {d, o, f, b, g, o, f, b, g, o, d, o, f, b, g, o, f, b, g, o, d},
	      				 {d, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, o, d},
	        			 {d, o, b, b, b, o, d, o, b, b, h, b, b, o, d, o, b, b, b, o, d},
	        			 {d, o, o, o, o, o, d, o, o, o, d, o, o, o, d, o, o, o, o, o, d},
	      			  	 {f, b, b, b, c, o, y, b, b, k, d, k, b, b, z, o, a, b, b, b, g},
	      			  	 {k, k, k, k, d, o, d, k, k, k, k, k, k, k, d, o, d, k, k, k, k},
	      				 {b, b, b, b, g, o, d, k, a, n, n, n, c, k, d, o, f, b, b, b, b},
	      			  	 {k, k, k, k, k, o, k, k, d, k, k, k, d, k, k, o, k, k, k, k, k},  //12 mitad u 11 contando desde 0
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
     			  	 
} // VOID MAPITA
//------------------------------------------



void imprimir (int mat[PF][PC], int contdin, int contvid) {
	int i, j;
	for (i=0; i<PF; i++) { 
		for (j=0; j<PC; j++) {
			if (mat[i][j]==o) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);	
			}
			else if (mat[i][j]==p) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
			}
			else if (mat[i][j]==q) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
			}
			else if (mat[i][j]==t) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),6);
			}
			else if (mat[i][j]==r) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),11);
			}
			else if (mat[i][j]==s) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),13);
			}
			else if (mat[i][j]==u) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
			}
			else if (mat[i][j]!=k){
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),9);
			}
			printf ("%c", mat[i][j]);
   		}
   		printf ("\n");
    }
    SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
    printf ("\n\n%c=%d/172\t\t@=%d", o, contdin, contvid);
} // VOID IMPRIMIR
//------------------------------------------


void fantasmatonto (int mat [PF][PC], int *ftf, int *ftc, int *dirft) {
	int ftf1, ftc1, dirft1, procam;
	ftf1=*ftf;
  	ftc1=*ftc;

	while (*ftf==ftf1 && *ftc==ftc1) { 
		if (*dirft==0) {
	  		if (*ftf==11 && *ftc==0) {
				*ftf=11;
				*ftc=20;
			}
 	 		if (mat[*ftf][*ftc-1]==k || mat[*ftf][*ftc-1]==o) {
	 			*ftc=*ftc-1;
			}
			else {
	 			*dirft=rand()%4;
			}
			if (mat[*ftf-1][*ftc]==k || mat[*ftf-1][*ftc]==o || mat[*ftf+1][*ftc]==k || mat[*ftf+1][*ftc]==o) {
				procam=rand()%3;
				if (procam==0) {
					*dirft=rand()%4;
				}
			}
		} //DIRQ IZQUIERDA
		
		else if (*dirft==1) {
			if (*ftf==11 && *ftc==20) {
				*ftf=11;
				*ftc=0;
			}
			if (mat[*ftf][*ftc+1]==k || mat[*ftf][*ftc+1]==o) {
				*ftc=*ftc+1;
			}
			else {
	 			*dirft=rand()%4;
			}
			if (mat[*ftf-1][*ftc]==k || mat[*ftf-1][*ftc]==o || mat[*ftf+1][*ftc]==k || mat[*ftf+1][*ftc]==o) {
				procam=rand()%3;
				if (procam==2) {
					*dirft=rand()%4;
				}
			}
		} //DIRQ DERECHA
		
		else if (*dirft==2) {
			if (mat[*ftf+1][*ftc]==k || mat[*ftf+1][*ftc]==o) {
				*ftf=*ftf+1;
			}
			else {
	 			*dirft=rand()%4;
			}
			if (mat[*ftf][*ftc+1]==k || mat[*ftf][*ftc+1]==o || mat[*ftf][*ftc-1]==k || mat[*ftf][*ftc-1]==o) {
				procam=rand()%3;
				if (procam==1) {
					*dirft=rand()%4;
				}
			}
		} //DIRQ ABAJO
		
		else if (*dirft==3) {
			if (mat[*ftf-1][*ftc]==k || mat[*ftf-1][*ftc]==o) {
				*ftf=*ftf-1;
			}
			else {
	 			*dirft=rand()%4;
			}
			if (mat[*ftf][*ftc+1]==k || mat[*ftf][*ftc+1]==o || mat[*ftf][*ftc-1]==k || mat[*ftf][*ftc-1]==o) {
				procam=rand()%3;
				if (procam==0) {
					*dirft=rand()%4;
				}
			}
		} //DIRQ ARRIBA
	} // while ftf==ftf1 && ftc==ftc1
	
} // INT FANTASMATONTO
//----------------------------------------


void fantasmainteligente (int mat [PF][PC], int *fit, int *fic, int *dirfi) {
	//fit y fic=fantasma inteligente fila/columna;   dirfi=direccion fantasma inteligente
	
}//VOID fantasmainteligente
//----------------------------------------

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
	srand(time(NULL));
  	dirq=rand()%2;
	imprimir (mat, contdin, contvid);
	
	//tecla, juego 
	resp=0;
  	
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
		
 	 	// CUANDO ESTÉ A 4 CASILLAS DE DISTANCIA DE PACMAN, QUE LE PERSIGA if matqf-4==FJ {seguir pacman}; 
	//	printf ("Funcion juego: qf=%d, qc=%d ", qf, qc);
	//	system ("pause");
		//reimpresión de mapita
		system("CLS");
		mat[jf][jc]=p;
		mat[qf][qc]=q; 
		imprimir (mat, contdin, contvid);		
		Sleep (100);
	} //while resp!='x'
} // INT JUEGO 
// ---------------------------------------

