#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <windows.h>
#include <time.h>
#define ABA 80  //flecha abajo
#define ARRI 72 //flecha arriba
#define DER 77  //flecha derecha
#define IZQ 75  //flecha izquierda
//librerias y define
//-----------------------------------------------

typedef struct {
	int pf, pc, dir;
	char nombre[20];
}personaje;
//ESTRUCTURA
//-----------------------------------------------


void inicializar (int mat[20][20]);
void imprimir (int mat[20][20]);
void juego (personaje *jugador, personaje *tron, int mat[20][20]);
//PROTOTIPOS
//-----------------------------------------------

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
	int mat[20][20], i;
	personaje jugador, tron;
	inicializar (mat);
	jugador.pf=1;
	jugador.pc=1;
	tron.pf=18;
	tron.pc=18;
	mat[jugador.pf][jugador.pc]=1;
	mat[tron.pf][tron.pc]=2;
	printf ("ingrese nombre: ");
	fflush (stdin);
	gets (jugador.nombre);
	system ("cls");
	juego (&jugador, &tron, mat);
}// MAIN
//-----------------------------------------------


void inicializar (int mat[20][20]) {
	int i, j;
	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			mat[i][j]=0;
			if (i==0 || j==0 || i==19 || j==19) {
				mat[i][j]=9;
			}
		}
	}
}//INICIALIZAR
//-----------------------------------------------


void imprimir (int mat[20][20]) {
	int i, j;
	for (i=0; i<20; i++) {
		for (j=0; j<20; j++) {
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
			if (mat[i][j]==0) {
				printf (" ");
			}
			else if (mat[i][j]==9) {
				printf ("#");
			}
			else if (mat[i][j]==1) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
				printf ("@");
			}
			else if (mat[i][j]==2) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
				printf ("O");
			}
			else if (mat[i][j]==3) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),12);
				printf ("%c",176);
			}
			else if (mat[i][j]==4) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
				printf ("%c", 176);
			}
			SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
		}//for j
		printf ("\n");
	}//for i
}//IMPRIMIR
//-----------------------------------------------


void juego (personaje *jugador, personaje *tron, int mat[20][20]) {
	char resp;
	resp=0;
	jugador->dir=0;
	tron->dir=0;
	while (resp!='x') {
		imprimir (mat);
		fflush (stdin);
		if (kbhit()) 
			resp=getch();
		
		switch (resp) {
			case ARRI:
				if (mat[jugador->pf-1][jugador->pc]==0)
					jugador->dir=ARRI;
				break;
			case ABA:
				if (mat[jugador->pf+1][jugador->pc]==0)
					jugador->dir=ABA;
					break;
			case DER:
				if (mat[jugador->pf][jugador->pc+1]==0)
					jugador->dir=DER;
				break;
			case IZQ:
				if (mat[jugador->pf][jugador->pc-1]==0)
					jugador->dir=IZQ;
				break;
				
		}
		
		if (jugador->dir!=0) {
			mat[jugador->pf][jugador->pc]=3;
			mat[tron->pf][tron->pc]=4;
		}
			
		switch (jugador->dir) {
			case IZQ:
				jugador->pc=jugador->pc-1;
				break;
			case DER:
				jugador->pc=jugador->pc+1;
				break;
			case ARRI:
				jugador->pf=jugador->pf-1;
				break;
			case ABA:
				jugador->pf=jugador->pf+1;
				break;
		}
		if (mat[jugador->pf][jugador->pc]!=0 && mat[jugador->pf][jugador->pc]!=1) {
			printf ("perdiste.\n");
			system ("pause");
			return 0;
		}
		
		mat[jugador->pf][jugador->pc]=1;
		mat[tron->pf][tron->pc]=2;
		Sleep (150);
		system ("cls");
	} 
}//VOID JUEGO
//-----------------------------------------------
