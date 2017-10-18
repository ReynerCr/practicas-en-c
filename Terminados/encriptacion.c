#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define C 101

int main () {
	int imprimir;
	char codigo[C], i, comprobacion[C], z;
	do {  //CICLO PARA CASOS DE PRUEBA
		gets (codigo);
		fflush (stdin);
		imprimir=1;
		for (i=0; i<C; i++) {   //CONDICIONES
			z=0;
			if (i==0 && codigo[i]==70 && codigo[i+1]==73 && codigo[i+2]==78 && codigo[i+3]==0) {
				return 0;
			}
			
			if (codigo[i]==90) {
				codigo[i]=65;
				z=1;
			}
			
			if (((codigo[i]>=65 && codigo[i]<90) && z==0) || codigo[i]==32 || codigo[i]==0) {
				if (codigo[i]==0) {
					break;
				}
				if (codigo[i]==32) {
					codigo[i]=32;
					continue;
				}
				codigo[i]=codigo[i]+1;
			}
			
			if ((codigo[i]<64 && codigo[i]!=32) || codigo[i]>90) {
				if (codigo[i]==0) {
					break;
				}
				imprimir=0;
			}
			
		}  //FIN CONDICIONES
		
		//CONDICION DE IMPRESION
		if (imprimir==1) {
			printf ("%s\n\n", codigo);
		}
		if (imprimir==0) {
			printf ("\n");
			imprimir=1;
		}
		//----------------------
	} while (imprimir!=3);
	system ("pause");
	return 0;
}
