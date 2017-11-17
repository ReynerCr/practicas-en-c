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
void imprimir (int F, int C, int mat[F][C], int cf, int cc);
void respuesta (char unsigned resp, int *cc, int *cf, int F, int C, int mat[F][C], int validacion[F][C], int *aux);
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
	int F, C, contjuego, contdado;
	char turno;
	printf ("Ingrese tama%co de la matriz (FxC) minimo 8x8 y maximo 20x20\n", 164);
	scanf ("%d %d", &F, &C);
	
	while ((F<8 || F>20) || (C<8 || C>20)) {
		system ("cls");
		printf ("Ingrese de nuevo  ");
		fflush (stdin);
		scanf ("%d %d", &F, &C);
	}
	system ("cls");
 	
 	pedirnombres (&A, &B);
 	srand (time(NULL));
 	
 	contjuego=0;
 	contdado=0;
	while (contjuego<=3) {
		do {
			Sleep (300);
			system ("cls");
			A.dado=rand()%6+1;
			B.dado=rand()%6+1;
			printf ("Numero obtenido del dado de %s: [%d]\n", A.nombre, A.dado);
 			printf ("\nNumero obtenido del dado de %s: [%d]", B.nombre, B.dado);
 			contdado++;
		} while (A.dado==B.dado || contdado<=3);
 		
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
void imprimir (int F, int C, int mat[F][C], int cf, int cc) {
	int i, j;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			if (mat[i][j]==0) {  // punto
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				if (cf==i && cc==j) 
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),31);
				printf ("%c ", 250);
			}
			if (mat[i][j]==1) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				if (cf==i && cc==j) 
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),31);
				printf ("O ");
			}
			if (mat[i][j]==2) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				if (cf==i && cc==j) 
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),31);
				printf ("S ");
			}
			
			if (mat[i][j]==3) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
				if (cf==i && cc==j)
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),26);
				printf ("O ");
			}
			if (mat[i][j]==4) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
				if (cf==i && cc==j)
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),26);
				printf ("S ");
			}
			if (mat[i][j]==5) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
				if (cf==i && cc==j)
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),28);
				printf ("O ");
			}
			if (mat[i][j]==6) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
				if (cf==i && cc==j)
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),28);
				printf ("S ");
			}
			if (mat[i][j]==7) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
				if (cf==i && cc==j)
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),30);
				printf ("O ");
			}
			if (mat[i][j]==8) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),14);
				if (cf==i && cc==j)
					SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),30);
				printf ("S ");
			}
		SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
		}//for j
		printf ("\n");
	}//for i
}//FIN IMPRIMIR
//-----------------------------------------


void juego (int F, int C, char turno, jugador *A, jugador *B) {
	char resp;
	int cf=4;   //cursor fila
	int cc=4;   //cursor columna
	int mat[F][C], validacion[F][C], aux;
	inicializar (F, C, mat);
	inicializar (F, C, validacion);
	resp=0;
	while (1!=2) {
			
		imprimir (F, C, mat, cf, cc);
		
		if (turno=='A')
			printf ("\n\n Turno:%s", A->nombre);
		
		else 
			printf ("\n\n Turno:%s", B->nombre);
		
		aux=0;
		fflush (stdin);
		resp=getch();
		
		if (resp=='S')
			resp='s';
			
		if (resp=='O')
			resp='o';
			
		switch (turno) {
			case 'A':			
				respuesta (resp, &cc, &cf, F, C, mat, validacion, &aux);
				break;
				
			case 'B':
				respuesta (resp, &cc, &cf, F, C, mat, validacion, &aux);
				break;			
		}
		
		if ((resp=='s' || resp=='o') && aux==1) {
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


void respuesta (char unsigned resp, int *cc, int *cf, int F, int C, int mat[F][C], int validacion[F][C], int *aux) {
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
			if (mat[*cf][*cc]==0) {
				validacion[*cf][*cc]=2;
				mat[*cf][*cc]=2;
				*aux=1;
			}
			break;
		
		case 'o': 
			if (mat[*cf][*cc]==0) {
				mat[*cf][*cc]=1;
				validacion[*cf][*cc]=1;
				*aux=1;
			}
			break;
	}
}//FIN RESPUESTA
//-----------------------------------------

//   3=O verde;  4=S verde; 5=O roja; 6=Sroja; 7=O amarilla; 8=S amarilla; 
void oso (int F, int C, int mat[F][C], int validacion[F][C], jugador **X, char turno) {
	int i, j;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			if (i+2<F && validacion[i][j]==1 && validacion[i+1][j]==2 && validacion[i+2][j]==1) {
				if (turno=='A') {
					if (mat[i][j]==1) {
						mat[i][j]=5;
						
						if (mat[i+1][j]==(4 || 2)) {
							if (mat[i+1][j]==4)
								mat[i+1][j]=8;
							else if (mat[i+1][j]==2) 
								mat[i+1][j]=6;
						}
						if (mat[i+2][j]==(3 || 1)) {
							if (mat[i+2][j]==3)
								mat[i+2][j]=7;
							else if (mat[i+2][j]==1) 
								mat[i+2][j]=5;
						}
					}//mat==1
				}//turno=='A'
				
				if (turno=='B') {
					if (mat[i][j]==1) {
						mat[i][j]=3;
						if (mat[i+1][j]==(6 || 2)) {
							if (mat[i+1][j]==6)
								mat[i+1][j]=8;
							else if (mat[i+1][j]==2) 
								mat[i+1][j]=4;
						}
						if (mat[i+2][j]==(5 || 1)) {
							if (mat[i+2][j]==5)
								mat[i+2][j]=7;
							else if (mat[i+1][j]==1) 
								mat[i+1][j]=3;
						}
					}//mat==1					
				}//turno 'B'
			}//oso en vertical bajando
			
		/*	if (i-2>0 && validacion[i][j]==1 && validacion[i-1][j]==2 && validacion[i-2][j]==1) {
				if (turno=='A') {
					if (mat[i][j]==1) {
						mat[i][j]=5;
						var++;
						if (mat[i-1][j]==(4 || 8)) {
							var++;
							if (mat[i-1][j]==4)
								mat[i-1][j]=8;
						}
					
						if (mat[i-2][j]==(3 || 7)) {
							var++;
							if (mat[i-2][j]==3)
								mat[i-2][j]=7;
						}
						
						if (var==3) {
							continue;
						}//var==3
						mat[i-1][j]=6;
						mat[i-2][j]=5;
					}//mat==1
				}//turno=='A'
				
				if (turno=='B') {
					if (mat[i][j]==1) { 
						mat[i][j]=3;
						var++;
						if (mat[i-1][j]==(6 || 8)) {
							var++;
							if (mat[i-1][j]==6)
								mat[i-1][j]=8;
						}
					
						if (mat[i-2][j]==(5 || 7)) {
							var++;
							if (mat[i-2][j]==5)
								mat[i-2][j]=7;
						}
						
						if (var==3) {
							continue;
						}//var==3
						mat[i-1][j]=4;
						mat[i-2][j]=3;
					}//mat==1					
				}//turno 'B'
			}//oso en vertical subiendo	
			*/
		}//for j
	}	//for i
}//FIN OSO
//-----------------------------------------
