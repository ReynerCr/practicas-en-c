#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <dos.h>
#include <windows.h>
#define F 30  //FILA
#define C 32  //COLUMNA
#define ESC 27 // ESCAPE (tecla)
//LIBRERIAS Y DEFINE
//---------------------------

void inicializaciondemapa (int mat[F][C]);   //Su nombre lo dice: rellena el mapa de 0;
int generarcelulas (int mat[F][C], int *g);  //Funcion que permite poner celulas vivas en el mapa;
int copiarmatriz (int origina[F][C], int copia[F][C]);  //Lo que dice su nombre;
void imprimir (int mat[F][C]);  //Imprimir mapa;
int juego (int mat[F][C]);  //Juego;
//PROTOTIPOS
//---------------------------


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
//---------------------------------------------


int main () {
	int mat[F][C];
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE), 10);
	printf ("\t\t\tEl juego de la vida\n\n%c", 207);
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
	printf ("=c%clula viva\n%c=c%clula muerta\n\n", 130, 250, 130);
	inicializaciondemapa (mat);
	juego (mat);
	return 0;
} // INT MAIN
//----------------------------


void inicializaciondemapa (int mat[F][C]) {
	int i, j;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			if (j==0 || j==31) {
				mat[i][j]=2;
				continue;
			}
			mat[i][j]=0;
		}
	}
} // INT MAPA
//-----------------------------


int generarcelulas (int mat[F][C], int *g) {
	int i, j, k, fm, cm, n, vreinicio, contt;
	char respg;
	respg='s';
	fflush (stdin);
	k=0;
	n=0;
	fm=1;
	cm=1;
	contt=0;
	if (*g==1) {  //REPETICION
		while (respg=='s') {
			n=0;
			printf ("1. Utilizar la configuraci%cn actual (o la primera en caso de no hacer cambios).\n2. A%cadir c%clulas. \n3. Eliminar c%clulas.\n", 162, 164, 130, 130);
			scanf ("%d", &vreinicio);
			system ("CLS");
			contt=0;
			
	        for (i=0; i<F; i++) { //comprobación de 1 en la matriz
				for (j=0; j<C; j++) {
					if (mat[i][j]==1) {
						contt++;
					}
				}
			} //contt
			switch (vreinicio) {
				case 1:
					respg='n';
					break;
					
				case 2:
					do { //PEDIR NUMERO DE CELULAS QUE SE AÑADIRAN
						printf ("Ingrese n%cmero de c%clulas que quiere agregar.\n", 163, 130);
						scanf ("%d", &n);
						system ("CLS");
					} while (n<1 || n>=(C*C)-contt); 
					
					
					for(k=0;k<n;k++) {
						imprimir (mat);
						printf ("\n\nIngrese fila y columna (1-%d) separadas con un espacio.\n", F);
						scanf ("%d %d", &fm, &cm);
						system ("cls");	
						while (((fm>F || fm<1) || (cm>C || cm<1)) || ((fm>F || fm<1) && (cm>C || cm<1)) || mat[fm-1][cm]==1) {	
							system ("cls");
							imprimir (mat);
							printf ("\n\nReingrese la fila y columna (1-%d) desde el %cltimo punto.\n", F, 163, 160, 163);
							scanf ("%d %d", &fm, &cm);
							if (mat[fm-1][cm]==1) {
								fm=0;
								cm=0;
							}
						} // while
						if (mat[fm-1][cm]!=1 || mat[fm][cm]!=2) {
							mat[fm-1][cm]=1;
						}
						system ("cls");
						imprimir (mat);
					} // FOR k=0
					printf ("\n\n%cDesea realizar otra acci%cn? s/n\n", 168, 162);
					respg=tolower(getch());
					break;
				
				case 3: 
					if (contt>5) {
						do { //PEDIR NUMERO DE CELULAS QUE SE ELIMINARAN
							imprimir (mat);
							printf ("\n\nIngrese numero de c%clulas que quiere eliminar, m%cnimo deben existir 5.\n", 130, 161);
							fflush (stdin);
							scanf ("%d", &n);
							system ("CLS");
						} while (contt-n<5);
						
						for(k=0;k<n; k++) {
							imprimir (mat);
							printf ("\n\nIngrese fila y columna (1-%d) separadas con un espacio.\n", F);
							scanf ("%d %d", &fm, &cm);
							system ("cls");
							while (((fm>F || fm<1) || (cm>C || cm<1)) || ((fm>F || fm<1) && (cm>C || cm<1))) {	
								system ("cls");
								imprimir (mat);
								printf ("\n\nReingrese la fila y columna (1-%d) desde el %cltimo punto.\n", F, 163, 160, 163);
								scanf ("%d %d", &fm, &cm);		
							} // while
							if (mat[fm-1][cm]==1) {
								mat[fm-1][cm]=0;
							}
							imprimir (mat);
							printf ("\n\n");
						} // FOR k=0
					} //CONDICION DE CELULAS INICIALES VALIDA PARA ELIMINAR
					
					if (contt==5) {
						printf ("No es posible eliminar m%cs, solo hay 5 celulas vivas.", 160);
						getch();
					}// CONDICION DE CELULAS INICIALES NO VALIDA PARA ELIMINAR
					
					system ("cls");
					printf ("%cDesea realizar otra acci%cn? s/n\n", 168, 162);
					respg=tolower(getch());
					break;
					
				default:
					system ("cls");
					printf ("%cDesea continuar sin hacer m%cs cambios? s/n", 168, 160);
					respg=tolower(getch());
					break;
			} 
			system ("CLS");
		} //while respg=='s';	
	} //IF *G==1;
	
	
	if (*g==0){    //PRIMERA VEZ
	
		do { //PEDIR NUMERO DE CELULAS QUE SE INGRESARAN
			n=0;
			printf ("Ingrese n%cmero de celulas vivas que quiere (min 5, max 900): ", 163);
			scanf ("%d", &n);
		} while (n<5 || n>=C*C);
		
		
		system ("CLS");
		for (k=0; k<n; k++) {
			imprimir (mat);
			printf ("\n\nIngrese fila y columna (1-%d) separadas con un espacio para validar la posici%cn:\n", F, 162);
			scanf ("%d %d", &fm, &cm);
			while (((fm>F || fm<1) || (cm>C || cm<1)) || ((fm>F || fm<1) && (cm>C || cm<1)) || mat[fm-1][cm]==1) {	
				system ("cls");
				imprimir (mat);
				printf ("\n");
				printf ("Reingrese la fila y columna (1-%d) desde el %cltimo punto, y si est%c bien, luego contin%ce ingresando:\n", F, 163, 160, 163);
				scanf ("%d %d", &fm, &cm);
				if (mat[fm-1][cm]==1 || mat[fm-1][cm]==2) {
					fm=0;
					cm=0;
				}
			} //WHILE
			if (mat[fm-1][cm]==0) {
				mat[fm-1][cm]=1;
			}
			system ("cls");	
			imprimir (mat);
			printf ("\n");
		}   //FOR K=0
	} //FIN PRIMERA VEZ
	*g=2;
	k=0;
	system ("CLS");
} // INT GENERARCELULAS
//------------------------------------------


int copiarmatriz (int original[F][C], int copia[F][C]) {
	int i, j;
	for (i=0; i<F; i++) {
		for (j=0; j<C; j++) {
			copia[i][j]=original[i][j];
		}
	}
} // INT COPIARMATRIZ
//------------------------------------------

void imprimir (int mat[F][C]) {
	int i, j;
	system ("CLS");
	for (i=0; i<F; i++) {
		printf ("\n");
		for (j=0; j<C; j++) {
			if (mat[i][j]==0) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
				printf ("%c", 250);
			}
			
			else if (mat[i][j]==1) {
				SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),10);
				printf ("%c", 207);
			}
		} //FOR J=0
	} //FOR I=0
	SetConsoleTextAttribute (GetStdHandle (STD_OUTPUT_HANDLE),15);
} //INT IMPRIMIR
//-----------------------------


int juego (int mat[F][C]) {
	int i, j, reinicio[F][C], celvivas, nacimiento[F][C], celviv, celmuertas, G, contigual, generaciones;   //G y *g condición de reinicio
	float porcnac, porcfall, contnac, contfall, contotal, total;
	char resp;
	G=0;
	
	generarcelulas (mat, &G);
	copiarmatriz (mat, reinicio);
	
	do {   //CICLO PARA LAS REPETICIONES ---------------------------------------------------------------------------------------------------------------
		contnac=contotal;	
		generaciones=1;
		generarcelulas (mat, &G);
		imprimir (mat);
		printf ("\nGeneraciones: %d", generaciones);
		resp=0;
		porcnac=0;   porcfall=0;
		do {  //CICLO PARA SIMULACION -------------------------------------------------------
			Sleep (80);
			celvivas=0;  celviv=0;  celmuertas=0;  contigual=0;  total=0;
			if (kbhit()) {   //ESCANEO DE TECLA CONTINUO
				resp=getch();
				fflush (stdin);
  			}
  			generaciones++;
			for (i=0; i<F; i++) {
				for (j=0; j<C; j++) {
					nacimiento[i][j]=0;  //INICIALIZACION DE LA MATRIZ NACIMIENTO EN 0, QUE SIRVE PARA CUANDO NO SE CUMPLE CONDICION DE NACIMIENTO
					
					//CONDICIONES DE CELULAS VECINAS:
					if (mat[i-1][j]==1) {
						celvivas++;
					}
					if (mat[i-1][j-1]==1) {
						celvivas++;
					}
					if (mat[i][j-1]==1) {
						celvivas++;
					}
					if (mat[i][j+1]==1) {
						celvivas++;
					}
					if (mat[i+1][j-1]==1) {
						celvivas++;
					}
						if (mat[i-1][j+1]==1) {
						celvivas++;
					}
					if (mat[i+1][j]==1) {
						celvivas++;
					}
					if (mat[i+1][j+1]==1) {
						celvivas++;
					}
					//FIN DE CONDICIONES DE CELULAS VECINAS.
					if (mat[i][j]==2) {
						nacimiento[i][j]=2;
					}
					if ((celvivas==2 || celvivas==3) && mat[i][j]==1) {
						nacimiento[i][j]=1;
					} //SUPERVIVENCIA
						
					if ((celvivas>=4 || celvivas<2) && mat[i][j]==1) {
						contfall++;
					}  //CONTADOR DE FALLECIMIENTO
					
					if (celvivas==3 && mat[i][j]==0) {
						nacimiento[i][j]=1;
						contnac++;
					} //NACIMIENTO Y CONTADOR

					if (nacimiento[i][j]==1) {
						celviv++;
					} //CONTADOR DE CELULAS VIVAS
					
					else {
						celmuertas++;
					}  //CONTADOR DE CELULAS MUERTAS
					
					if (nacimiento[i][j]==mat[i][j]) {
						contigual++;
					}  //IGUALDAD DE MATRICES
					
					celvivas=0;  //LIMPIAR CELVIVAS
				} // FOR J=0;	
			} //FOR I=0;
			
			//CONDICIONES PARA SALIDA AUTOMATICA
			if (contigual==F*C) {
				resp=ESC;
			}
			if (celmuertas==F*C) {
				resp=ESC;
			}
			//-------------------------------
			
			copiarmatriz (nacimiento, mat);
			system ("CLS"); //BORRADO DE PANTALLA Y REIMPRESION
			imprimir (mat);
			printf ("\nGeneraciones: %d\n", generaciones);
		} while (resp!=ESC);  //FIN SIMULACION-------------------------------------------------------
		total=contnac+contfall;
		porcnac=(contnac/total)*100;
		porcfall=(contfall/total)*100;
		printf ("\a\n%c nacimiento: %.2f\t%c fallecimiento: %.2f\n", 37, porcnac, 37, porcfall);
		printf ("Vivas=%d;  Muertas=%d;", celviv, celmuertas);
		printf ("\n\n%cDesea reiniciar la simulaci%cn? s/n", 168 ,162);
		resp=tolower(getch());
		
		if (resp=='s') {
			G=1;
			copiarmatriz (reinicio, mat);
			system ("cls");
		}
		contnac=0;  contfall=0;
	} while (resp=='s');  // DO WHILE DE REINICIO ---------------------------------------------------------------------------------------
}  //INT JUEGO
//-----------------------------
