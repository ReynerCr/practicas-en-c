#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define ESC 32
//LIBRERIAS Y DEFINE
//-------------------------------------


typedef struct {
	char nombre[18];
	int mat[5][5];  //cart�n
	int B[5], I[5], N[5], G[5], O[5];
	int aciertos, falto, ganador;
}carton;
//ESTRUCTURA
//-------------------------------------


void imprimir (carton J, int i);
void imprimirr (carton J1, carton J2, carton J3, carton J4, int var);
void compararcarton (carton *J1, carton *J2, carton *J3, carton *J4, int var, int varaux);
void llenarcarton (carton *J);
void imprimiruno (carton J);
void bombo (int *num, int vect[75]);
void inicializarv (int vect[75]);
void comprobarnum (int num, carton *J, int opcion, int *comp);
void inicializark (int var, int k[var]);
//PROTOTIPOS
//-------------------------------------


//GOTOXY-------------------------------
void gotoxy( int column, int line ) {
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
//-------------------------------------


int main () {
	int var, varaux, i, k, opcion, num, vect[75], comp;
	char resp;
	comp=0;
	carton J1, J2, J3, J4;
	J1.aciertos=0;
	J2.aciertos=0;
	J3.aciertos=0;
	J4.aciertos=0;
	printf ("\t\t\tBingo.\n");
	printf ("Elija la cantidad de jugadores, minimo 2 y maximo 4.\n"); 
	scanf ("%d", &var);
	while (var<2 || var>4) {
		system ("cls");
		printf ("Reingrese un numero valido de jugadores (min 2, max 4).\n");
		fflush (stdin);
		scanf ("%d", &var);
	}//while
	varaux=1;
	int k1[var];
	do {
		system ("cls");	
		printf ("Ingrese nombre (max 10 caracteres) de jugador %d\n", varaux);
		fflush (stdin);
		switch (varaux) {
			case 1:
				gets (J1.nombre);
				break;
			case 2:
				gets (J2.nombre);
				break;
			case 3:
				gets (J3.nombre);
				break;
			case 4:
				gets (J4.nombre);
				break;
		}//switch
		varaux++;
		system ("cls");
	} while (varaux<=var);
	varaux=1;
	
	srand (time(NULL));
	do {
		printf ("Jugador %d:  ", varaux);
		switch (varaux) {
			case 1:
				printf ("%s\n", J1.nombre);
				llenarcarton (&J1);
				break;
			case 2:
				printf ("%s\n", J2.nombre);
				llenarcarton (&J2);
				break;
			case 3:
				printf ("%s\n", J3.nombre);
				llenarcarton (&J3);
				break;
			case 4:
				printf ("%s\n", J4.nombre);
				fflush (stdin);
				getch ();
				llenarcarton (&J4);
				break;
		}//switch
		varaux++;
	}while (varaux<=var);
	
	opcion=-1;
	system ("cls");
	
	while (opcion<1 || opcion>8) {
		printf ("\t\t\tPatrones para ganar el juego:\n\n");
		printf ("Lineas:\n\t1.Horizontal.\n\t2.Vertical.\n\t3.Diagonal.\n\nCruz:\n\t4.Pequena.\n\t5.Grande.\n\n\tMarco:\n\t6.Externo.\n\t7.Interno.\n\n8.Cubrir todo.");
		fflush (stdin);
		scanf ("%d", &opcion);
		if (opcion<1 || opcion>8) {
			printf ("\nNumero no valido, pulse una tecla cualquiera y luego reingrese la opcion.");
			fflush (stdin);
			getch ();
		}
		system ("cls");
	}//while
	//compararcarton (&J1, &J2, &J3, &J4, var, varaux);
	varaux=1;
	while (varaux<=var) {
		switch (varaux) {
			case 1:
				imprimiruno (J1);
				printf ("\n\nDesea rehacer el carton? s/n");
				fflush (stdin);
				resp=tolower(getch());
				if (resp=='s') {
					llenarcarton (&J1);
					varaux--;
				}
				break;
			case 2:
				imprimiruno (J2);
				printf ("\n\nDesea rehacer el carton? s/n");
				fflush (stdin);
				resp=tolower(getch());
				if (resp=='s') {
					llenarcarton (&J2);
					varaux--;
				}
				break;
			case 3:
				imprimiruno (J3);
				printf ("\n\nDesea rehacer el carton? s/n");
				fflush (stdin);
				resp=tolower(getch());
				if (resp=='s') {
					llenarcarton (&J3);
					varaux--;
				}
				break;
			case 4:
				imprimiruno (J4);
				printf ("\n\nDesea rehacer el carton? s/n");
				fflush (stdin);
				resp=tolower(getch());
				if (resp=='s') {
					llenarcarton (&J4);
					varaux--;
				}
				break;
		}//switch
		varaux++;
		system ("cls");
	}//while varaux
	
	system ("cls");
	imprimirr (J1, J2, J3, J4, var);
	printf ("\n\nPresione cualquier teclar para comenzar.");
	inicializarv (vect);
	inicializark (var, k1);
	i=0;
	while (i!=2) {
		fflush (stdin);
		getch ();
		system ("cls");
		bombo (&num, vect);
		for (varaux=1; varaux<=var; varaux++) {
			switch (varaux) {
				case 1:
					comprobarnum (num, &J1, opcion, &comp);
					if (comp>0) {
						k1[0]=1;
					}
					break;
				case 2:
					comprobarnum (num, &J2, opcion, &comp);
					if (comp>0) {
						k1[1]=2;
					}
					break;
				case 3:
					comprobarnum (num, &J3, opcion, &comp);
					if (comp>0) {
						k1[2]=3;
					}
					break;
				case 4:
					comprobarnum (num, &J4, opcion, &comp);
					if (comp>0) {
						k1[3]=4;
					}
					break;
			}//switch
		}//for varaux
		
		imprimirr (J1, J2, J3, J4, var);
		printf ("\n\n\t\t\tNumero:%d\n\n", num);
		if (comp>0) {
			switch (comp) {
				case 1:
					for (k=0; k<var; k++) {			
						if (k1[k]>0) {
							if (k1[k]==1) {
								printf ("El ganador es: %s\n", J1.nombre);
							}
							else if (k1[k]==2) {
								printf ("El ganador es: %s\n", J2.nombre);
							}
							else if (k1[k]==3) {
								printf ("El ganador es: %s\n", J3.nombre);
							}
							else if (k1[k]==4) {
								printf ("El ganador es: %s\n", J4.nombre);
							}		
						}//K1[k]>)1
					}//for k
					break;
				default:
					for (varaux=1; varaux<=comp; varaux++) {
						for (k=0; k<var; k++) {
							if (k1[k]>0) {
								printf ("Empate entre: ");
									if (k1[k]==1) {
										printf ("%s, ", J1.nombre);
									}
									if (k1[k]==2) {
										printf ("%s, ", J2.nombre);
									}
									if (k1[k]==3) {
										printf ("%s, ", J3.nombre);
									}
									if (k1[k]==4) {
										printf ("%s ", J4.nombre);
									}						
							
							}//K1[k]>)1
						}//for k
					}//for varaux
					break;				
			}//switch
			i=2;
		}//if comp>=0
	}//while
		fflush (stdin);
	getch ();
		fflush (stdin);
	getch ();
		fflush (stdin);
	getch ();
	fflush (stdin);
	getch ();
	system ("cls");
	
	fflush (stdin);
	getch ();
	printf ("\n\nPresione una tecla para salir.");
	fflush (stdin);
	getch ();
	return 0;
}//MAIN
//-------------------------------------


void inicializark (int var, int k[var]) {
	int i, j;
	for (i=0; i<var; i++) {
		k[i]=0;
	}//for
}//INICIALIZARK
//-------------------------------------


void bombo (int *num, int vect[75]) {
	int i;
	*num=rand()%75+1;
	for (i=0; i<75; i++) {
		if (*num==vect[i]) {
			*num=rand()%75+1;
			i=-1;
			continue;
		}
		if (vect[i]==-1) {
			vect[i]=*num;
			break;
		}	
	}//for i
}//BOMBO
//-------------------------------------

void comprobarnum (int num, carton *J, int opcion, int *comp) {
	int i, j, aux;
	aux=0;
	for (i=0; i<5; i++) {
		for (j=0; j<5; j++) {
			if (J->mat[i][j]==num) {
				J->aciertos=J->aciertos+1;
				J->mat[i][j]=-2;
				if (opcion==1) {
					if (J->mat[i][0]==-2 && J->mat[i][1]==-2 &&  (J->mat[i][2]==-2 || J->mat[i][2]==-5) && J->mat[i][3]==-2 && J->mat[i][2]==-2) {
						J->ganador=1;
						if (aux==0) {
							*comp=*comp+1;
							aux=1;
						}
					}//if
				}//if opcion=1		
				if (opcion==2) {
					if (J->mat[0][j]==-2 && J->mat[1][j]==-2 &&  (J->mat[2][j]==-2 || J->mat[2][j]==-5) && J->mat[3][j]==-2 && J->mat[4][j]==-2) {
						J->ganador=1;
						if (aux==0) {
							*comp=*comp+1;
							aux=1;
						}
					}//if
				}//if opcion=2	
			}//if de igual a numero de bombo
		}//for j
	}//for i
}//COMPROBARNUM
//-------------------------------------


void inicializarv (int vect[75]) {
	int i=0;
	for (i=0; i<75; i++) {
		vect[i]=-1;
	}//for i
}//INICIALIZARV
//-------------------------------------


void compararcarton (carton *J1, carton *J2, carton *J3, carton *J4, int var, int varaux) {
	int i, j, k, B, I, N , G, O, repe;
	for (varaux=2; varaux<=var; varaux++) {
		for (j=0; j<5; j++) {
			for (i=0; i<5; i++) {
				for (k=0; k<5; k) {
					switch (varaux) {
						case 2:
							if (J2->mat[i][j]==J1->mat[k][j]) {
								repe++;
							}//if
							break;
						case 3:
							if (J3->mat[i][j]==J2->mat[k][j]) {
								repe++;
							}
							if (J3->mat[i][j]==J1->mat[k][j]) {
								repe++;
							}
							break;
						case 4:
							if (J4->mat[i][j]==J3->mat[k][j]) {
								repe++;
							}
							if (J4->mat[i][j]==J2->mat[k][j]) {
								repe++;
							}
							if (J4->mat[i][j]==J1->mat[k][j]) {
								repe++;
							}
							break;
					}//switch 
					
					if (repe>=3) {
						switch (j) {
							case 0:
								J2->mat[i][j]=rand()%15+1;
								break;
							case 1:
								J2->mat[i][j]=rand()%15+16;
								break;
							case 2:
								J2->mat[i][j]=rand()%15+31;
								break;
							case 3:
								J2->mat[i][j]=rand()%15+46;
								break;
							case 4:
								J2->mat[i][j]=rand()%15+61;
								break;					
						}//switch j
						k=-1;
						repe=2;
					}//if repe>=3
					k++;						
				}//for k
			}//for i
			repe=0;
		}//for j
	}//for varaux
}//COMPARARCARTON
//-------------------------------------


void llenarcarton (carton *J) {
	int i, j, aux;
	for (j=0; j<5; j++) {
		for (i=0; i<5; i++) {
			aux=0;
			switch (j) {
				case 0://B
					J->mat[i][j]=rand()%15+1;
					while (aux<i) {
						if (J->mat[i][j]==J->mat[aux][j]) {
							J->mat[i][j]=rand()%15+1;
							aux=-1;
						}
						aux++;
					}//while
					J->B[i]=J->mat[i][j];
					break;
				case 1://I
					J->mat[i][j]=rand()%15+16;
					while (aux<i) {
						if (J->mat[i][j]==J->mat[aux][j]) {
							J->mat[i][j]=rand()%15+16;
							aux=-1;
						}
						aux++;
					}//while
					J->I[i]=J->mat[i][j];
					break;
				case 2://N
					if (i==2) {
						J->mat[i][j]=-5;
						J->N[i]=J->mat[i][j];
						continue;
					}
					J->mat[i][j]=rand()%15+31;
					while (aux<i) {
						if (J->mat[i][j]==J->mat[aux][j]) {
							J->mat[i][j]=rand()%15+31;
							aux=-1;
						}
						aux++;
					}//while
					J->N[i]=J->mat[i][j];
					break;
				case 3://G
					J->mat[i][j]=rand()%15+46;
					while (aux<i) {
						if (J->mat[i][j]==J->mat[aux][j]) {
							J->mat[i][j]=rand()%15+46;
							aux=-1;
						}
						aux++;
					}//while
					J->G[i]=J->mat[i][j];
					break;
				case 4://O
					J->mat[i][j]=rand()%15+61;
					while (aux<i) {
						if (J->mat[i][j]==J->mat[aux][j]) {
							J->mat[i][j]=rand()%15+61;
							aux=-1;
						}
						aux++;
					}//while
					J->O[i]=J->mat[i][j];
					break;
			}//switch j
		}//for i
	}//for j
}//LLENARCARTON
//-------------------------------------


void imprimirr (carton J1, carton J2, carton J3, carton J4, int var) {
	int i, varaux, espacios, j;
	for (i=0; i<var; i++) {
		printf ("B  I  N  G  O      ");
	}//for i=0
	varaux=1;
	printf ("\n");
	
	for (i=0; i<5; i) {
		if (varaux==1) 
			imprimir (J1, i);
		else if (varaux==2) 
			imprimir (J2, i);
		else if (varaux==3)	
			imprimir (J3, i);
		else if (varaux==4) 
			imprimir (J4, i);
		printf ("     ");
		varaux++;
		if (varaux>var) {
			printf ("\n");
			varaux=1;
			i++;
		}
	}//for varaux=1
	for (i=1; i<=var; i++) {
		espacios=0;
		switch (i) {
			case 1:
				printf ("%s", J1.nombre);
				for (j=0; j<18; j++) {
					if (J1.nombre[j]!='\0') {
						espacios++;
					}
					else  {
						espacios=18-espacios;
						break;
					}
				}//for j
				break;
			case 2:
				printf ("%s", J2.nombre);
				for (j=0; j<18; j++) {
					if (J2.nombre[j]!='\0')
						espacios++;
					else {
						espacios=18-espacios;
						break;
					}
				}//for j
				
				break;
			case 3:
				printf ("%s", J3.nombre);
				for (j=0; j<18; j++) {
					if (J3.nombre[j]!='\0')
						espacios++;
					else {
						espacios=18-espacios;
						break;
					}
				}//for j
				
				break;
			case 4:
				printf ("%s", J4.nombre);
				for (j=0; j<18; j++) {
					if (J4.nombre[j]!='\0')
						espacios++;
					else {
						espacios=18-espacios;
						break;
					}
				}//for j
				break;
		}//switch
		for (j=0; j<=espacios; j++) {
			printf (" ");
		}
	}//for i=0
}//IMPRIMIRR
//-------------------------------------


void imprimir (carton J, int i) {
	int j;
	for (j=0; j<5; j++) {
		if (J.mat[i][j]==-5) {
			printf ("   ");
			continue;
		}
		if (J.mat[i][j]==-2) {
			printf ("##");
			if (j<4) 
					printf (" ");
			continue;
		}
		if (J.mat[i][j]<=9)
			printf ("0%d", J.mat[i][j]);
		if (J.mat[i][j]>9)
			printf ("%d", J.mat[i][j]);
		if (j<4) 
			printf (" ");
	}//for j
}//IMPRIMIR
//-------------------------------------


void imprimiruno (carton J) {
	int i, j;
	printf ("B  I  N  G  O\n");
	for (i=0; i<5; i++) {
		for (j=0; j<5; j++) {
			if (J.mat[i][j]==-5) {
				printf ("   ");
				continue;
			}
			if (J.mat[i][j]==-2) {
				printf ("##");
				if (j<4) 
					printf (" ");
				continue;
			}
			if (J.mat[i][j]<=9)
			printf ("0%d", J.mat[i][j]);
			if (J.mat[i][j]>9)
				printf ("%d", J.mat[i][j]);
			if (j<4) 
				printf (" ");
		}//for j
		printf ("\n");
	}//for i
	printf ("%s", J.nombre);
}//IMPRIMIRUNO
//-------------------------------------
