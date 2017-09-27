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
#define q 169  //fantasma 1
#define r 81   //fantasma 2
#define s 227  //fantasma 3
#define u 225  //fantasma 4



int main() {
	//Declaración de variables
	int i, j, pj, jc, jf, contdin, conttdin, dirq, qf, qc;
	char resp;
	
	// mapita
	int mat[PF][PC]={{a, b, b, b, b, b, b, b, b, b, h, b, b, b, b, b, b, b, b, b, c},  //20 contando desde 0
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
   
	//controles basicos         
	printf ("Controles:\n\nArriba\t\tAbajo\nIzquierda\tDerecha\nPulse una tecla DIFERENTE a las FLECHAS para continuar.\nPulse X para salir.");
	getch();
	system ("cls");
	fflush (stdin);
	jf=17;
	jc=10;
	qf=9;
	qc=10;
	contdin=0;
 
	// impresion de mapita por primera vez    
	mat[jf][jc]=p;
	conttdin=0;
	srand(time(NULL));
	for (i=0; i<PF; i++) {
		printf ("\n"); 
		for (j=0; j<PC; j++) {
			printf ("%c", mat[i][j]);
    	/*	if (mat[i][j]==a || mat[i][j]==b || mat[i][j]==c|| mat[i][j]==d|| mat[i][j]==f|| mat[i][j]==g|| mat[i][j]==h|| mat[i][j]==y|| mat[i][j]==z || mat[i][j]==v) {				
				system ("color 09");
				printf ("%c", mat[i][j]);
			}
			if (mat[i][j]==p) {
				system ("color 06");
				printf ("%c", mat[i][j]);
			}							 	 //BUSCAR COMO IMPRIMIR EN COLORCITO BONITO.
			if (mat[i][j]==o) {
				system ("color 07");
				printf ("%c", mat[i][j]);
			}
			if (mat[i][j]==t) {
				system ("color 04");
				printf ("%c", mat[i][j]);
			} */
     		/*if (mat[i][j]==o) {
    			conttdin++;
			} SI AÑADO MAS COMESTIBLES*/
   		}
    }
    printf ("\n\n%c=%d/172", o, contdin);
  // si añado más comestibles  printf ("\n\n%c=%d/174", o, contdin);
 
	//tecla, juego y reimpresiones de mapa
	resp=0;
	while(resp!='x') {
		resp=0;
		
		// escaneo de tecla contínuo
	//	if (kbhit()) 
		resp=getch();
		
  		mat[jf][jc]=k;
  		mat[qf][qc]=k;
  		
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

 	 	} //IZQUIERDA
 	 	
		dirq=rand()%4;
 	 	if (dirq==0) {
 	 		if (mat[qf][qc-1]==k || mat[qf][qc-1]==o) {
 	 			qc--;
			}
		} //DIRQ IZQUIERDA
		
		if (dirq==1) {
			if (mat[qf][qc+1]==k || mat[qf][qc+1]==o) {
				qc++;
			}
		} //DIRQ DERECHA
		
		if (dirq==2) {
			if (mat[qf+1][qc]==k || mat[qf+1][qc]==o) {
				qf++;
			}
		} //DIRQ ABAJO
		
		if (dirq==3) {
			if (mat[qf-1][qc]==k || mat[qf-1][qc-1]==o) {
				qf--;
			}
		} //DIRQ ARRIBA
  		// IDEA PARA QUE EL FANTASMA NO SEA TAN LOCO: QUE CUANDO LLEGUE A UNA PARED YENDO DESDE ESA DIRECCIÓN, COMPRUEBE SI EN OTRA PUEDE IR
  		// CUANDO ESTÉ A 4 CASILLAS DE DISTANCIA DE PACMAN, QUE LE PERSIGA if matqf-4==FJ {seguir pacman};
		//reimpresión de mapita
		system("CLS");
		mat[jf][jc]=p;
		mat[qf][qc]=q; 
		for (i=0; i<PF; i++) {
				printf ("\n"); 
				for (j=0; j<PC; j++) {
    				printf ("%c", mat[i][j]);
			}
		}
		// impresión de contador.
		printf ("\n\n%c=%d/172", o, contdin);
		printf ("\n\naleatorio=%d", dirq);
		//Sleep (25);
		
	} //while
 
	system ("pause");
	return 0;
} //int main
