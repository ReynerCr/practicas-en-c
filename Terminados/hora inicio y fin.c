#include <stdio.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <conio.h>

int main(){
	int h1, h2, hf1, hf2, h11, h22;
	char resp;
	do {
	printf ("Ingrese la hora de inicio y fin del juego (militar y separados la hora de los minutos en espacios; seguidas):  \n");
	fflush (stdin);
	scanf ("%d %d %d %d", &h1, &h11, &h2, &h22);
	system ("cls");

	if (h1<24 && h2<24 && h11<60 && h22<60) {
		
		if (h1==h2 && h11==h22 && h1==h11) {
			printf ("El juego duro 24 hora(s) y 0 minuto(s) ");
			system ("pause");
			return 0;
		}
		if (h1==h2 && h11>h22) {
			hf1=24-1;
			hf2=h11-h22;
			printf ("El juego duro %d hora(s) y %d minuto(s) ", hf1, hf2);
			system ("pause");
			return 0;
		}
		if (h1==h2 && h11<h22) {
			hf1=0;
			hf2=h22-h11;
			printf ("El juego duro %d hora(s) y %d minuto(s) ", hf1, hf2);
			system ("pause");
			return 0;
		}
		if (h2>=h1) {
			hf1=h2-h1;
		}
		if (h2<=h1) {
			hf1=(h2+24)-h1;
		}
		if (h1<h2 && h11>h22) {
			hf1=(h2-h1)-1;
			hf2=(h22+60)-h11;
			printf ("El juego duro %d hora(s) y %d minuto(s) ", hf1, hf2);
			system ("pause");
			return 0;
		}
		if (h11>=h22) {
			hf2=(h22+60)-h11;
		}
		if (h11<=h22) {
			hf2= h22-h11;
		}
		printf ("El juego duro %d hora(s) y %d minuto(s) ", hf1, hf2);
		system ("pause");
		return 0;
	}
	if (h1>=24 || h2>=24 || h11>=60 || h22>=60) {
		h1=0; h2=0; h11=0; h22=0;
		printf ("Un numero ingresado no es valido para la operacion, desea volver a ingresar valores? S/N");
		resp=tolower (getch());
		system ("cls");
	}
	} while (resp=='s'); 
	
	system ("pause");
	return 0;
}
	

