#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
/*
Desarrollar:

1. Funcion que calcule el indice academico de cada estudiante  lISTO :)
2. Funcion que genere un listado de estudiantes con indice mayor a 6
3. Mostrar por estudiante un listado de materias aprobadas y reprobadas.
4. Mostrar Nombre, cedula y carrera del mejor estudiante.
5. Mostrar un listado de estudiantes ordenado por cedula.
6.Calcular el porcentaje de materias aprobadas por estudiante.
7. Calcular el porcentaje de materias reprobadas por estudiantes.

*/
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
#define MAX 40
#define S 50

typedef struct{
	char nombre[30];
	float nota;
	int uc;
}materias;
typedef struct {
	char nombre[50];
	int cedula;
	char carrera[50];
	int NumMat;
	float IA;
	materias semestre[MAX];	
}estudiante;

int cargar_materia(materias *M, float *IA, float *UC2);
void cargar_estudiante(estudiante *X);
void imprimir(estudiante Im);

int main(int argc, char *argv[]) {
	
	estudiante sec[S];
	int i, tsi, cont=0;
	char ts[2];
	printf("\n\t\tNumero de estudiantes de la seccion:  ");
	scanf("%s", &ts);
	
	do {
			for (i=0; i<2; i++) {
				if (isdigit(ts[i]!=0)) {
					cont++;
				}
				else {
					cont=0;
				}
			}
			if (cont=0) {
				system ("cls");
				printf ("\n\t\tIngrese un valor numerico:  ");
				scanf ("%s", &ts);
			}
	} while (cont<2);
	
	tsi=atoi(ts);
	for(i=0;i<tsi;i++){
		cargar_estudiante(&sec[i]);
	}//for
	system("cls");
	
	for(i=0;i<tsi;i++){
		imprimir(sec[i]);
		if(i%3==0 && i!=0){
			printf("\n\n\t");
			system("PAUSE");
		}
			
	}//for
	return 0;
}

void cargar_estudiante(estudiante *X){ //carga UN estudiante
	int i;
	float IA2, UC, UC2=0;
	float IA=0;
	system("CLS");
	printf("\n\t\t\t* Datos del Estudiante *\n\n");
	printf("\n\t\tNombre: ");
	fflush(stdin);
	gets(X->nombre);
	printf("\n\t\tCedula: ");
	scanf("%d",&X->cedula);
	printf("\n\t\tCarrera: ");
	fflush(stdin);
	gets(X->carrera);
	printf("\n\t\tNumero de Materias: ");
	scanf("%d",&X->NumMat);
	for(i=0;i<X->NumMat;i++){
		cargar_materia(&X->semestre[i], &IA2, &UC2);
		IA=IA+IA2;
		UC=UC+UC2;
	}
	X->IA=IA/UC;
}
	
int cargar_materia(materias *M, float *IA2, float *UC2){//carga UNA materia
	system("CLS");
	printf("\n\t\t\t* Datos de la Asignatura *\n\n");
	printf("\n\t\tNombre: ");
	fflush(stdin);
	gets(M->nombre);
	printf("\n\t\tNota: ");
	scanf("%f",&M->nota);
	printf("\n\t\tUC: ");
	scanf("%d",&M->uc);
	*IA2=(M->nota)*(M->uc);
	*UC2=M->uc;
}

void imprimir(estudiante Im){ //imprime una estructura
	printf("\n\n\n\t\t\t* Datos del estudiante *\n\n");
	printf("\t\tNombre: %s",Im.nombre);
	printf("\n\t\tCedula: %d",Im.cedula);
	printf("\n\t\tCarrera: %s",Im.carrera);
	printf("\n\t\tIndice academico: %.2f", Im.IA);
	/*Completar la informacion del estudiante*/
}
