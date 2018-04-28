//PROGRAMA PARA CALCULAR EL TIEMPO TRANSCURRIDO ENTRE DOS HORAS DISTINTAS, NO MAS DE 24 HORAS

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int main () {
	int h1, h2, hf1, hf2, h11, h22, formato, ampm;
	// h1=hora inicio; h2=hora fin; h11=minutos inicio; h22=minutos fin; formato=formato de horas; ampm= am o pm en 12 horas; hf1=hora final; hf2=minutos finales
	char resp;
	do {
		do {
			printf ("Programa para calcular el tiempo transcurrido entre dos momentos distintos. (no mas de 24 horas)\n\nSeleccione el formato de las horas:\n");
			printf ("1. Formato de 12 horas\n2. Formato de 24 horas\n\n");
			scanf ("%d", &formato);
		
			if (formato!=1 && formato!=2) {
				printf ("No es una opcion valida, reingrese.");
				fflush (stdin);
				getch ();
				formato=0;
			}
			
			system ("cls");
		} while (formato!=1 && formato!=2);
		
		switch (formato) {
			case 1: //formato de 12 horas
				do { //HORA DE INICIO
					printf ("Seleccione cual sera el formato de la hora de inicio\n1.AM\n2.PM\n");
					scanf ("%d", &ampm);
					if (ampm!=1 && ampm!=2) {
						printf ("No es una opcion valida, reingrese");
						fflush (stdin);
						getch ();			
						}	
					system ("cls");	
				} while (ampm!=1 && ampm!=2);
				do {
					printf ("Ingrese la hora de inicio separando las horas de los minutos ");
					scanf ("%d %d", &h1, &h11);
					
					if ((h1<1 || h1>12) || (h11<0 && h11>59)) {
						printf ("Alguno de los valores no es correcto, reingrese");
						fflush (stdin);
						getch ();		
					}//if
					system ("cls");
				} while ((h1<0 || h1>=13) || (h11<0 || h11>=60));
				
				if (ampm==2) {
					h1=h1+12;
					if (h1>=24) {
					h1=h1-24;
					}
				}
				// FIN HORA INICIO
				//--------------------------
				
				do { //HORA FIN
					printf ("Seleccione cual sera el formato de la hora de finalizacion\n1.AM\n2.PM\n");
					scanf ("%d", &ampm);
					if (ampm!=1 && ampm!=2) {
						printf ("No es una opcion valida, reingrese");
						fflush (stdin);
						getch ();			
					}	
					system ("cls");	
					} while (ampm!=1 && ampm!=2);
				do {
					printf ("Ingrese la hora de fin separando las horas de los minutos ");
					scanf ("%d %d", &h2, &h22);
					
					if ((h2<1 || h2>12) || (h22<0 && h22>59)) {
						printf ("Alguno de los valores no es correcto, reingrese");
						fflush (stdin);
						getch ();		
					}//if
					system ("cls");
				} while ((h2<1 || h2>=13) || (h22<0 || h22>=60));
				
				if (ampm==2) {
					h2=h2+12;
					if (h1>=24) {
					h1=h1-24;
					}
				}
				//FIN HORA FINALIZACION
				break;
					
			case 2: //formato de 24 horas
					do {//hora inicio
					printf ("Ingrese la hora de inicio separando las horas de los minutos ");
					scanf ("%d %d", &h1, &h11);
					
					if ((h1<0 || h1>23) || (h11<0 && h11>59)) {
						printf ("Alguno de los valores no es correcto, reingrese");
						fflush (stdin);
						getch ();		
					}//if
					system ("cls");
				} while ((h1<0 || h1>23) || (h11<0 || h11>=60)); //fin hora inicio 
				
				do { //hora fin
					printf ("Ingrese la hora de fin separando las horas de los minutos ");
					scanf ("%d %d", &h2, &h22);
					
					if ((h2<0 || h2>23) || (h22<0 && h22>59)) {
						printf ("Alguno de los valores no es correcto, reingrese");
						fflush (stdin);
						getch ();		
					}//if
					system ("cls");
				} while ((h2<0 || h2>23) || (h22<0 || h22>=60)); //fin hora de fin
				break;	
		} //switch
		system ("cls");
		
		//Incio de calculos para determinar el tiempo transcurrido			
		if (h1==h2 && h11==h22) {
			printf ("Tiempo transcurrido es de: 0 hora(s) y 0 minuto(s) ");
		}
		
		else if (h1==h2 && h11>h22) {
			hf1=24-1;
			hf2=h11-h22;
			printf ("Tiempo transcurrido es de: %d hora(s) y %d minuto(s) ", hf1, hf2);
		}
		
		else if (h1==h2 && h11<h22) {
			hf1=0;
			hf2=h22-h11;
			printf ("Tiempo transcurrido es de: %d hora(s) y %d minuto(s) ", hf1, hf2);
		}
		
		else if (h1<h2 && h11>h22) {
			hf1=(h2-h1)-1;
			hf2=(h22+60)-h11;
			printf ("Tiempo transcurrido es de: %d hora(s) y %d minuto(s) ", hf1, hf2);	
		}
		
		else {
			if (h2>=h1) {
				hf1=h2-h1;
			}
			
			else if (h2<=h1) {
				hf1=(h2+24)-h1;
			}
				
			if (h11>h22) {
				hf2=(h22+60)-h11;
			}
			
			else if (h11<=h22) {
				hf2=h22-h11;
			}
			
			printf ("Tiempo transcurrido es de: %d hora(s) y %d minuto(s)", hf1, hf2);
		}//else if
		
		printf ("\n");
		system ("pause");
		//fin de calculos para determinar el tiempo transcurrido	
		system ("cls");
		printf ("Desea calcular otro tiempo transcurrido entre dos horas? S-N");
		fflush (stdin);
		resp=getch();
		system ("cls");
	} while (resp=='s' || resp=='S'); 
	
	system ("pause");
	return 0;
}
