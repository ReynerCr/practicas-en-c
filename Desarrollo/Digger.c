#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <windows.h>
#define DER 77
#define IZQ 75
#define ARRI 72
#define ABA 80
#define F 13
#define C 17

void mapa (int map[F][C], int niv);
int copiar (int matorig[F][C], int matcopia[F][C]);
void imprimir (int map[F][C],int nivel);
int juego (int map[F][C],int nivel);

int main(int argc, char *argv[]) {
	int nivel,campo[F][C];
	nivel=1;
	mapa (campo,nivel);
	juego (campo,nivel);
	return 0;
}//main

void mapa (int map[F][C], int niv) {
	int niv1[F][C]= {{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
					 {7, 0, 1, 1, 1, 6, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 7},
					 {7, 0, 1, 1, 2, 2, 1, 1, 2, 1, 1, 0, 1, 6, 1, 1, 7},
					 {7, 0, 1, 6, 2, 2, 1, 1, 2, 1, 1, 0, 1, 1, 1, 1, 7},
					 {7, 0, 1, 1, 2, 2, 6, 1, 2, 6, 1, 0, 1, 2, 2, 2, 7},
					 {7, 0, 1, 1, 2, 2, 1, 1, 2, 1, 1, 0, 1, 2, 2, 2, 7},
					 {7, 0, 0, 1, 2, 2, 1, 1, 2, 1, 1, 0, 1, 2, 2, 2, 7},  // 6 desde 0 
					 {7, 1, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 7},
					 {7, 1, 1, 0, 1, 1, 1, 6, 1, 6, 1, 0, 1, 1, 1, 1, 7},
					 {7, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 1, 7},
					 {7, 2, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 2, 7},
					 {7, 2, 2, 1, 1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 2, 2, 7},  //11,9=pos personaje contando desde 0
					 {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}};
					 
					 copiar(niv1, map);
					 // 7=muro del juego, 0=espacio, 1=tierra, 2=esmeraldas
					 //3=jugador, 4=enemigo y 5=enemigo excavador, 6=bolsa de $
					
} // void mapa

int copiar(int matorig[F][C],int matcopia[F][C]){
	int i,j;
	for(i=0;i<F;i++)
		for(j=0;j<C;j++)
			matcopia[i][j]=matorig[i][j];
	
}//copiar

void imprimir (int map[F][C], int nivel) {
	int i, j;
	system ("CLS");
	for(i=0;i<F;i++){
		printf("\n");
		for(j=0;j<C;j++){
			if (map[i][j]==1)
				printf ("#");
			if (map[i][j]==0)
				printf (" ");
			if (map[i][j]==6)
				printf ("$");
			if (map[i][j]==2)
				printf ("*");
			if (map[i][j]==3)
				printf ("@");
			if (map[i][j]==4)
				printf ("+");
			if (map[i][j]==5)
				printf ("P");
			if (map[i][j]==7)
				printf ("/");
		}//for
	}//for
} //void imprimir

int juego (int map[F][C], int nivel) {
	int DF, DC, contv, contdin;
	char resp;
	DF=11;
	DC=8;
	contv=3;
	contdin=0;
	map[DF][DC]=3;
	imprimir (map, nivel);
	printf ("\n\n$=%d\t@=%d", contdin, contv);
	resp=0;
	while (resp!='x') {
		resp=0;
		resp=getch();
		map[DF][DC]=0;
		
		if (resp==ARRI) {
			if (map[DF-1][DC]==0 || map[DF-1][DC]==1 || map[DF-1][DC]==2) {
				if (map[DF-1][DC]==2) {
					contdin=contdin+25;
				}
				DF--;
			}
		} //ARRIBA
		
		if (resp==ABA) {
			if (map[DF+1][DC]==0 || map[DF+1][DC]==1 || map[DF+1][DC]==2) {
				if (map[DF+1][DC]==2) {
					contdin=contdin+25;
				}
				DF++;
			}
		} //ABAJO
		
		if (resp==IZQ) {
			if (map[DF][DC-1]==0 || map[DF][DC-1]==1 || map[DF][DC-1]==2) {
				if (map[DF][DC-1]==2) {
					contdin=contdin+25;
				}
				DC--;
			}
		} //IZQUIERDA
		
		if (resp==DER) {
			if (map[DF][DC+1]==0 || map[DF][DC+1]==1 || map[DF][DC+1]==2) {
				if (map[DF][DC+1]==2) {
					contdin=contdin+25;
				}
				DC++;
			}
		} //DERECHA
		
		map[DF][DC]=3;
		imprimir (map, nivel);
		printf ("\n\n$=%d\t@=%d", contdin, contv);
	}
}

