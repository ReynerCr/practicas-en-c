#include <stdio.h >
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <math.h>
#define PF 10
#define PC 10
#define ABA 80
#define ARRI 72
#define DER 77
#define IZQ 75

int main() {
	int i, j, pj, jl1, jl2, jc, jf, contdin;
	char resp;
	// mapita
	char mat[PF][PC]={"1111111111",
				      "1213011131",
				      "1011011101",
				      "1000000001",
				      "1300000101",
				      "1101111111",
				      "1100011031",
				      "1311011011",
				      "1000000031",
				      "1111111111"};
	
	//controles basicos			      
	printf ("Controles:\n\nArriba\t\tAbajo\nIzquierda\tDerecha\n\nPulse una tecla DIFERENTE a las FLECHAS para continuar ");
	getch();
	system ("cls");
	fflush (stdin);
	jl1=8;
	jl2=8;
	jc=1;
	jf=1;
	contdin=0;
	
	// impresion de mapita por primera vez			 
	  mat[jf][jc]='2';
		for (i=0; i<10; i++) {
			printf ("\n");	
			for (j=0; j<10; j++) {
				if (mat[i][j]=='0') {
					printf (" ");
				}
				if (mat[i][j]=='2') { 
					printf ("@");
				}
				if (mat[i][j]=='3') {
					printf ("$");
				}
				if (mat[i][j]=='1') {
					printf ("#");
				}
			}
		}
		// primera impresión de contador.
		printf ("\n\n$=%d/6", contdin);
	
	//tecla, juego y reimpresiones de mapa
	resp=0;
	while(resp!='x') {
		resp=0;
		resp=getch();
		fflush (stdin);
		
		mat[jf][jc]='0';
		//control del personaje y condiciones de victoria/derrota.
		if (resp==ABA) {
			if (mat[jf+1][jc]=='3') {
				contdin++;
				jf++;
				if (contdin==6) {
				system ("CLS");
				printf ("Felicitaciones.\n");
				system ("pause");	
				return 0;
				} 			 	
			}
			else if (mat[jf+1][jc]=='1') {
				system ("CLS");
				printf ("Perdiste.\n");
				system ("pause");
				return 0;
			}
			if (mat[jf+1][jc]=='0' && mat[jf+1][jc]!='3' && mat[jf+1][jc]!='1') {
				jf++;
			}

		}
		if (resp==ARRI) {
			if (mat[jf-1][jc]=='3') {
				contdin++;
				jf--;
				if (contdin==6) {
				system ("CLS");
				printf ("Felicitaciones.\n");
				system ("pause");
				return 0;	
				} 	
			
			}
			else if (mat[jf-1][jc]=='1') {
				system ("CLS");
				printf ("Perdiste.\n");
				system ("pause");
				return 0;
			}
			if (mat[jf-1][jc]=='0' && mat[jf-1][jc]!='3' && mat[jf-1][jc]!='1') {
				jf--;
			}
		}
		if (resp==DER) {
			if (mat[jf][jc+1]=='3') {
				contdin++;
				jc++;
				if (contdin==6) {
				system ("CLS");
				printf ("Felicitaciones.\n");
				system ("pause");	
				return 0;
				} 		 	
			}
			else if (mat[jf][jc+1]=='1') {
				system ("CLS");
				printf ("Perdiste.\n");
				system ("pause");
				return 0;
			}
			if (mat[jf][jc+1]=='0' && mat[jf][jc+1]!='3' && mat[jf][jc+1]!='1') {
				jc++;
			}
		}
		if (resp==IZQ) {
			if (mat[jf][jc-1]=='3') {
				contdin++;
				jc--;
				if (contdin==6) {
				system ("CLS");
				printf ("Felicitaciones.\n");
				system ("pause");	
				return 0;
				};
			}
			else if (mat[jf][jc-1]=='1') {
				system ("CLS");
				printf ("Perdiste.\n");
				system ("pause");
				return 0;
			}
			if (mat[jf][jc-1]=='0' && mat[jf][jc-1]!='3' && mat[jf][jc-1]!='1') {
				jc--;
			}
		}
		
		//reimpresión de mapita
		mat[jf][jc]='2';		
		system("CLS");
		for (i=0; i<10; i++) {
			printf ("\n");	
			for (j=0; j<10; j++) {
				if (mat[i][j]=='0') {
					printf (" ");
				}
				if (mat[i][j]=='2') { 
					printf ("@");
				}
				if (mat[i][j]=='3') {
					printf ("$");
				}
				if (mat[i][j]=='1') {
					printf ("#");
				}
			}
		}
	// impresión de contador.
	printf ("\n\n$=%d/6", contdin);
	} //while
	
	system ("pause");
	return 0;
}
