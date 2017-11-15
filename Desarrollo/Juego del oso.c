#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <windows.h>
#include <time.h>
#define ABA 80  //flecha abajo
#define ARRI 72 //flecha arriba
#define DER 77  //flecha derecha
#define IZQ 75  //flecha izquierda
//LIBRERIAS Y DEFINE
//-----------------------------------------


typedef struct {
	char nombre[20];
	int victorias, perdidas, oso, ganador, palabras, dado;
}jugador;
//ESTRUCTURA
//-----------------------------------------


void inicializar (int F, int C, int mat[F][C]);
void pedirnombres (jugador *X, jugador *Y);
void juego (int F, int C, char turno, jugador *A, jugador *B);
void imprimir (int F, int C, int mat[F][C]);
void respuesta (char unsigned resp, int *cc, int *cf, int F, int C, int mat[F][C], int validacion[F][C]);
void oso (int F, int C, int mat[F][C], int validacion[F][C], jugador **X, char turno);
//PROTOTIPOS
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
}//FIN GOTOXY
//-----------------------------------------


int main () {
	jugador A, B;
	int F, C, contjuego;
	char turno;
	printf ("Ingrese tama%co de la matriz (FxC) minimo 8x8 y maximo 20x20\n", 164);
	scanf ("%d %d", &F, &C);
	
	while ((F<8 || F>20) || (C<8 || C>20)) {
		system ("cls");
		printf ("Ingrese de nuevo  ");
		scanf ("%d %d", &F, &C);
	}
	system ("cls");
 	
 	pedirnombres (&A, &B);
 	srand (time(NULL));
 	
 	contjuego=0;
	while (contjuego<=3) {
		do {
			A.dado=rand()%6+1;
			B.dado=rand()%6+1;
		} while (A.dado==B.dado);
 		printf ("\nNúmero obtenido del dado de %s: %d\n", A.nombre, A.dado);
 		printf ("\nNúmero obtenido del dado de %s: %d", B.nombre, B.dado);
 		fflush (stdin);
 		getch ();
 		system ("cls");
		if (A.dado>B.dado) {
			turno='A';
		}
		else {
			turno='B';
		}
		juego (F, C, turno, &A, &B);
		contjuego++;
	}
	
	fflush (stdin);
	getch ();
} //FIN MAIN
//-----------------------------------------


void pedirnombres (jugador *X, jugador *Y) {
	printf ("Nombre de jugador 1?   ");
 	fflush (stdin);
 	gets (X->nombre);
	printf ("\nNombre de jugador 2?   ");
	fflush (stdin);
	gets (Y->nombre);
 	system ("cls");
}//FIN PEDIRNOMBRES
//-----------------------------------------


void inicializar (int F, int C, int mat[F][C]) {
	int i, j;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			mat[i][j]=0;
		}
	}
} //FIN INICIALIZAR
//-----------------------------------------

//   3=O verde;  4=S verde; 5=O roja; 6=Sroja; 7=O amarilla; 8=S amarilla; 
void imprimir (int F, int C, int mat[F][C]) {
	int i, j;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			if (mat[i][j]==0) {  // puntico
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				printf ("%c ", 250);
			}
			if (mat[i][j]==1) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				printf ("O ");
			}
			if (mat[i][j]==2) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				printf ("S ");
			}
			if (mat[i][j]==9) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				printf ("_ ");
			}
			if (mat[i][j]==3) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
				printf ("O ");
			}
			if (mat[i][j]==4) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
				printf ("S ");
			}
			if (mat[i][j]==5) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),13);
				printf ("O ");
			}
			if (mat[i][j]==6) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),13);
				printf ("S ");
			}
			if (mat[i][j]==7) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
				printf ("O ");
			}
			if (mat[i][j]==8) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
				printf ("S ");
			}
		}
		printf ("\n");
	}
}//FIN IMPRIMIR
//-----------------------------------------


void juego (int F, int C, char turno, jugador *A, jugador *B) {
	char resp;
	int cf=4;   //cursor fila
	int cc=4;   //cursor columna
	int mat[F][C], validacion[F][C];
	inicializar (F, C, mat);
	inicializar (F, C, validacion);
	mat[cf][cc]=9;
	resp=0;
	while (1!=2) {
		if (mat[cf][cc]==0) 
			mat[cf][cc]=9;
			
		imprimir (F, C, mat);
		if (mat[cf][cc]==9)
			mat[cf][cc]=0;
		
		if (turno=='A')
			printf ("\n\n Turno:%s", A->nombre);
		
		else 
			printf ("\n\n Turno:%s", B->nombre);
		
		fflush (stdin);
		resp=getch();
		
		if (resp=='S')
			resp='s';
			
		if (resp=='O')
			resp='o';
			
		switch (turno) {
			case 'A':			
				respuesta (resp, &cc, &cf, F, C, mat, validacion);
				break;
				
			case 'B':
				respuesta (resp, &cc, &cf, F, C, mat, validacion);
				break;			
		}
		
		
		if (resp=='s' || resp=='o') {
			if (turno=='A') {
				oso (F, C, mat, validacion, &A, turno);
				turno='B';
			}
			else  {
				oso (F, C, mat, validacion, &B, turno);
				turno='A';
			}
		}	
				
		system ("cls");
	} //while infinito
}//FIN JUEGO
//-----------------------------------------


void respuesta (char unsigned resp, int *cc, int *cf, int F, int C, int mat[F][C], int validacion[F][C]) {
	switch (resp) {
		case ABA:
			if (*cf+1!=F) 
				*cf=*cf+1;
			break;
			
					
		case ARRI:
			if (*cf-1!=-1) 
				*cf=*cf-1;
			break;
					
					
		case DER:
			if (*cc+1!=C)  
				*cc=*cc+1;
			break;
					
					
		case IZQ :
			if (*cc-1!=-1) 
				*cc=*cc-1;
			break;
		
		
		case 's':
			if (mat[*cf][*cc]==0 && mat[*cf][*cc]!=9) {
				validacion[*cf][*cc]==2;
				mat[*cf][*cc]=2;
			}
			break;
		
		
		case 'o': 
			if (mat[*cf][*cc]==0 && mat[*cf][*cc]!=9) {
				mat[*cf][*cc]=1;
				validacion[*cf][*cc]==1;
			}
			break;
	}
}//FIN RESPUESTA
//-----------------------------------------

//   3=O verde;  4=S verde; 5=O roja; 6=Sroja; 7=O amarilla; 8=S amarilla; 
void oso (int F, int C, int mat[F][C], int validacion[F][C], jugador **X, char turno) {
	int i, j, var;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			var=0;
			
			if (i+2<F && validacion[i][j]==1 && validacion[i+1][j]==2 && validacion[i+2][j]==1) {
				if (turno=='A') {
					if (mat[i][j]==1) { 
						mat[i][j]=5;
						var++;
					}
					if (mat[i+1][j]==(3 || 7))
						var++;
					
					if (mat[i+2][j]==(3 || 7));
						var++;
						
					if (var==3) {
						mat[i][j]=5;
						if (mat[i+1][j]==3) {
							mat[i+1][j]=8;
							var++;
						}
						if (mat[i+2][j]==3) {
							mat[i+2][j]=7;
							var++;
						}
						if (var==5) {
							continue;
						}
					}
					var=0;
					mat[i+1][j]=6;
					mat[i+2][j]=5;
				}
				if (turno=='B') {
					if (mat[i][j]==1) { 
						mat[i][j]=3;
						var++;
					}
					if (mat[i+1][j]==(6 || 8))
						var++;
					
					if (mat[i+2][j]==(5 || 7));
						var++;
						
					if (var==3) {
						mat[i][j]=3;
						if (mat[i+1][j]==6) {
							mat[i+1][j]=8;
							var++;
						}
						if (mat[i+2][j]==5) {
							mat[i+2][j]=7;
							var++;
						}
						if (var==5) {
							continue;
						}
					}
					var=0;
					mat[i+1][j]=4;
					mat[i+2][j]=3;
				}
			}//oso en vertical bajando
			
		/*	if (i+2<F && validacion[i][j]==1 && validacion[i+1][j]==2 && validacion[i+2][j]==1) {
				if (turno=='A') {
					if (mat[i][j]==1 { 
						mat[i][j]=5;
						var++;
					}
					if (mat[i+1][j]==(3 || 7))
						var++;
					
					if (mat[i+2][j]==(3 || 7));
						var++
						
					if (var==3) {
						mat[i][j]=5;
						if (mat[i+1][j]==3) {
							mat[i+1][j]==8;
							var++;
						}
						if (mat[i+2][j]==3) {
							mat[i+2][j]==7
							var++;
						}
						if (var==5) {
							continue;
						}
					}
					var=0;
					mat[i+1][j]=6;
					mat[i+2][j]=5;
				}
				if (turno=='B') {
					if (mat[i][j]==1 { 
						mat[i][j]=3;
						var++;
					}
					if (mat[i+1][j]==(6 || 8))
						var++;
					
					if (mat[i+2][j]==(5 || 7));
						var++
						
					if (var==3) {
						mat[i][j]=3;
						if (mat[i+1][j]==6) {
							mat[i+1][j]==8;
							var++;
						}
						if (mat[i+2][j]==5) {
							mat[i+2][j]==7
							var++;
						}
						if (var==5) {
							continue;
						}
					}
					var=0;
					mat[i+1][j]=4;
					mat[i+2][j]=3;
				}
			}//oso en vertical subiendo*/
			
		/*	if (i-2>=0 && validacion[i][j]==1 && validacion[i+1][j]==2 || ) && validacion[i+2][j]==1) {
				if (turno=='A') {
					if (validacion[i][j]==3 && validacion[i+1][j]== && validacion[i+2][j]==1)
					
				}
			}//oso en vertical subiendo
			
			if (j+2<C && mat[i][j]==1 && mat[i][j+1]==2 && mat[i][j+2]==1) {
				
			}//oso en horizontal 
			
			if (i+2<F && j+2<C mat[i][j]==1 && mat[i+1][j+1]==2 && mat[i+2][j+2]==1) {
				
			}//oso en diagonal
			
			if (i+2<F && j-2<C && mat[i][j]==1 && mat[i+1][j-1]==2 && mat[i+2][j-2]==1) {
				
			}//oso en diagonal*/
			
		}//for j
	}	//for i
}//FIN OSO
//-----------------------------------------
