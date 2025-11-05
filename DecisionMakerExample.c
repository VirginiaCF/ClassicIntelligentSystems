/* Programa ejemplo de interaccion para toma de desiciones
Autor: Virginia Corral Flores
Fecha: Agosto 2021
Descripcion: Este es un recomendador de libros que usa solo euristica.
*/

#include <stdio.h>
#include <stdlib.h>

//Variables globales
char nombre[40], adiv[40];
int respuesta, persona, sino, i, j, set, seleccion;

void espera(int z){
	for (j=1; j<=z; j++)
	for(i=1; i<19999999; i++){
		continue;
	}
}

int main()
{
	espera(12);
	printf("\nSoy:\n 1.Hombre 2.Mujer 3.Hombre joven 4.Mujer joven ");
	espera(1);
	printf("\r 1.Hombre 2.Mujer 3.Hombre joven 4.Mujer joven "); espera(1);
	printf("\r 1.Hombre 2.Mujer 3.Hombre joven 4.Mujer joven "); espera(1);
	printf("\r 1.Hombre 2.Mujer 3.Hombre joven 4.Mujer joven "); espera(1);
	printf("\r 1.Hombre 2.Mujer 3.Hombre joven 4.Mujer joven ");
	espera(1);
	printf("\r 1.Hombre 2.Mujer 3.Hombre joven 4.Mujer joven ");
	scanf("%d", &persona);
	switch (persona){
		case 1: // Masculino, formal
		printf("\nBienvenido!\n");
		printf("Me das tu nombre por favor? ");
		scanf("%s", nombre);
		printf("\nMuy bien, %s, puedo recomendarte libros clasicos, te parece bien
			LOS 3 MOSQUETEROS? \n1.SI 2.Explorar mas ", nombre);
		scanf("%d", &sino);
		if (sino == 1){
			printf("\nGracias, sennor %s, Tu seleccion ha sido:\n\n+++ Los 3
			Mosqueteros\n", nombre);
		}else{
			printf("\nAyudame un poco, seleccionando lo que buscas:\n"); espera(4);
			printf("1.Algo como Sherlock Holmes\n2.Clasicos\n3.Novelas actuales\
			n"); espera(9);
			printf("Cual es tu seleccion? ");
			scanf("%d", &set);
			switch (set){
				case 1: //Masculino, misterio
				printf("\nSelecciona de nuestra coleccion:\n");
				printf("1. Sherlock Holmes\n2. Historias de Agatha Cristy\n3.
				Misterios anonimos\n"); espera(9);
				printf("Tu seleccion... ");
				scanf("%d", &seleccion);
				printf("\nGracias, sennor %s, Tu seleccion ha sido:\n\n+++ ",
						nombre);
				switch (seleccion){
					case 1:
					printf("Sherlock Holmes\n");
					break;
					case 2:
					printf("Historias de Agatha Cristy\n");
					break;
					case 3:
					printf("Misterios anonimos\n");
					break;
				}
				break;
				case 2: //Masculino, clasicos
				printf("Selecciona de nuestra coleccion:\n");
				printf("1. La Iliada\n2. 100 annos de soledad\n3. Mas alla del bien
						y del mal\n"); espera(9);
				printf("Tu seleccion... ");
				scanf("%d", &seleccion);
				printf("\nGracias, sennor %s, Tu seleccion ha sido:\n\n+++ ",
						nombre);
				switch (seleccion){
					case 1:
					printf("Sherlock Holmes\n");
					break;
					case 2:
					printf("Historias de Agatha Cristy\n");
					break;
					case 3:
					printf("Misterios anonimos\n");
					break;
				}
			}
		}
		break;
		case 2: // Femenino, formal
		printf("\nHola y bienvenida!\n");
		printf("Me das tu nombre por favor? ");
		scanf("%s", nombre);
		printf("Estimada %s, puedo recomendarte libros clasicos, te parece bien LO
				QUE EL VIENTO SE LLEVO?\n1.SI 2.Explorar mas ", nombre);
		scanf("%d", &sino);
		if (sino == 1){
			printf("\nGracias, %s, Tu seleccion ha sido:\n\n+++ Lo que el viento se
					llevo\n", nombre);
		}else{
			printf("\nAyudame un poco, seleccionando lo que buscas:\n"); espera(4);
			printf("1.Novelas\n"); espera(4);
			printf("2.Ensayos y autoayuda\n"); espera(4);
			printf("3.Lugares\n"); espera(4);
			printf("Cual es tu seleccion? ");
			scanf("%d", &set);
			switch (set){
				case 1: //Femenino Novela
				printf("\nSelecciona de nuestra coleccion:\n");
				printf("1. Los pilares de la tierra\n2. Paris era una fiesta\n3.
						Navidad en las montannas\n"); espera(9);
				printf("Tu seleccion... ");
				scanf("%d", &seleccion);
				printf("\nGracias, %s, Tu seleccion ha sido:\n\n+++ ", nombre);
				switch (seleccion){
					case 1:
					printf("Los pilares de la tierra\n");
					break;
					case 2:
					printf("Paris era una fiesta\n");
					break;
					case 3:
					printf("Navidad en las montannas\n");
					break;
				}
				break;
				case 2: //Femenino ensayo
				printf("\nSelecciona de nuestra coleccion:");
				printf("1. Elenisima\n2. Vida actual y exito\n3. Sor Juana y las
						trampas de la fe\n"); espera(9);
				printf("Tu seleccion... ");
				scanf("%d", &seleccion);
				printf("\nGracias, %s, Tu seleccion ha sido:\n\n+++ ", nombre);
				switch (seleccion){
					case 1:
					printf("Elenisima\n");
					break;
					case 2:
					printf("Vida actual y exito\n");
					break;
					case 3:
					printf("Sor Juana y las trampas de la fe\n");
					break;
				}
			}
		}
	}
	return 0;
}