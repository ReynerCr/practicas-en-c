#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#define C 101

int main () {
	int contador, mal;
	char codigo[C], i, comprobacion[C], z;
	contador=0;   mal=0;
	do {  //CICLO PARA CASOS DE PRUEBA
		gets (codigo);
		fflush (stdin);
		
		for (i=0; i<C; i++) {   //CONDICIONES
			z=0;
			if (codigo[i]==70 && codigo[i+1]==73 && codigo[i+2]==78 &&codigo[i-1]==0) {
				contador=3;
				return 0;
			}
			
			if (codigo[i]==90) {
				codigo[i]=65;
				z++;
			}
			
			if (((codigo[i]>=65 && codigo[i]<=90) && z!=1) || codigo[i]==32) {
				
				if (codigo[i]==32) {
					codigo[i]=32;
					printf ("%c", codigo[i]);
					continue;
				}
				
				codigo[i]=codigo[i]+1;
				printf ("%c", codigo[i]);
			}
			else {
				mal++;
				break;
			}
		}  //FIN CONDICIONES
				//CONDICION DE IMPRESION
		if (mal==1) {
			mal=0;
		}
		if (mal==0) {
			printf ("\n\n");
		}

		//----------------------
	} while (contador!=3);
	system ("pause");
	return 0;
}
