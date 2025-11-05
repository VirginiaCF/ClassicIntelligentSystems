// Algoritmo de busqueda en profundidad, con profundidad limitada
// aplicado al rompecabezas de 8 piezas con vacio.
// Autor Virginia Corral Flores
// Agosto 2021
// Para la clase de Sistemas Inteligentes

#include <stdio.h>
#include <stdlib.h>
#define profundidad 10 // Este es el limite de profundidad

// Variables globales
// Inicializacion del tablero
int inicio[3][3] = { {1, 2, 3},
					 {8, 0, 4},
					 {7, 6, 5}
					};
// Inicializacion del objetivo
int fin[3][3] = { {1, 2, 3},
				  {8, 5, 6},
				  {7, 4, 0}
				};
int arbol[3][3][200]; //guarda el tablero para cada nodo generado
int coord[2][200]; //coord[0] => x coord[1] => y
int padrehijo[2][200]; //padre[0] guarda el nodo padre, padre[1] guarda el nodo actual
int opcion[200]; //guarda 0-arriba, 1-derecha, 2-abajo, 3-izquierda, movimiento aplicado.
int solucion[200];
int padre, actual, x, y, z, mov, meta, encontrado;

void imprimenodo(int n){
	for (int i=0; i<3; i++){
		printf("\n");
		for (int j=0; j<3; j++){
			printf(" %d", arbol[i][j][n]);
		}
	}
	printf("\n");
}

int main()
{
	//Inicializar recorrido del arbol en profundidad, con profundidad limitada
	padre = 0;
	actual = 1;
	//guardamos el nodo padre, y las coordenadas del vacio
	for (x=0; x<3; x++){
		for (y=0; y<3; y++){
			arbol[x][y][padre] = inicio[x][y];
			if (arbol[x][y][padre] == 0 ){
				coord[0][padre] = x;
				coord[1][padre] = y;
			}
		}
	}
	//iniciamos con opcion invalida
	opcion[padre] = -1;
	//guardamos la relacion
	padrehijo[0][padre] = padre;
	padrehijo[1][padre] = padre;
	// visualizamos la configuracion inicial
	imprimenodo(padre);
	mov = 0;
	encontrado = 0;
	// Una vez que los datos del nodo padre se terminaron de llenar, iniciamos el ciclo principal
	while (!encontrado){
		// Expandir nodo actual
		// Primero copiar el nodo del padre al hijo actual
		for (x=0; x<3; x++){
			for (y=0; y<3; y++){
				arbol[x][y][actual] = arbol[x][y][padre];
			}
		}
		//Recuperar las coordenadas del vacio
		x = coord[0][padre];
		y = coord[1][padre];
		//printf("\nRecuperando coordenadas\n x = %d, y = %d\n", x, y);
		// guardamos indice de nodo padre y nodo hijo
		padrehijo[0][actual] = padre;
		padrehijo[1][actual] = actual;
		//printf("\nGuardando padre-hijo: %d - %d \n", padrehijo[0][actual], padrehijo[1][actual]);
		// Realizar el movimiento del vacio que corresponde.
		// En busqueda en profundidad, siempre va hacia abajo con el movimiento 1
		// y solo cuando se regresa, realiza otras opciones de movimientos
		//printf("\nRealizar movimiento.....\n");
		switch (mov){
			case 0: //mover arriba
			if (( x != 0 ) && ( opcion[padre] != 2)){
				//printf("\nMover arriba");
				arbol[x][y][actual] = arbol[x-1][y][actual];
				arbol[x-1][y][actual] = 0;
				coord[0][actual] = x-1;
				coord[1][actual] = y;
				opcion[actual] = 0;
				actual++;
				break;
			}
			else{
				// No se pudo realizar este movimiento, vamos al que sigue
				// Nota que no hay break, para usar los datos ya cargados del nodo
				mov++;
			}
			case 1: // mover derecha
			if (( y != 2 ) && ( opcion[padre] != 3) ){
				//printf("\nMover derecha");
				arbol[x][y][actual] = arbol[x][y+1][actual];
				arbol[x][y+1][actual] = 0;
				coord[0][actual] = x;
				coord[1][actual] = y+1;
				opcion[actual] = 1;
				actual++;
				break;
			}
			else{
				// No se pudo realizar este movimiento, vamos al que sigue
				mov++;
			}
			case 2: // mover abajo
			if (( x != 2 ) && ( opcion[padre] != 0) ){
				//printf("\nMover abajo");
				arbol[x][y][actual] = arbol[x+1][y][actual];
				arbol[x+1][y][actual] = 0;
				coord[0][actual] = x+1;
				coord[1][actual] = y;
				opcion[actual] = 2;
				actual++;
				break;
			}
			else{
				// No se pudo realizar este movimiento, vamos al que sigue
				mov++;
			}
			case 3: // mover izquierda
			if (( y != 0 ) && ( opcion[padre] != 1 ) ){
				//printf("\nMover izquierda");
				arbol[x][y][actual] = arbol[x][y-1][actual];
				arbol[x][y-1][actual] = 0;
				coord[0][actual] = x;
				coord[1][actual] = y-1;
				opcion[actual] = 3;
				actual++;
				break;
			}
			else{
				// No se pudo realizar este movimiento, pero como era el ultimo, va a quedar uno invalido
				// guardamos evidencia de esta opcion invalida para iniciar el retorno por el arbol
				mov++;
			}

		} //switch

		// Si la opcion es invalida, mov excede el 3, es porque debemos regresar un nivel mas,
		// o sea regresamos un nivel en el que ya no quedan opciones, entonces hay que regresar otro.
		if ( mov > 3 ){
			mov = opcion[padre] + 1;
			padre--;
			//printf("\n regresando un nivel, movimiento excede limite,\n Padre es ahora: %d", padre);
			actual = padre+1;
			imprimenodo(padre);

		}
		else{ // el arbol esta generandose correctamente
			// Primero revisamos si no alcanzamos la profundidad limite, en ese caso hay que regresar un
			nivel
			if ( actual == profundidad+1 ){
				mov = opcion[padre] + 1;
				padre--;
				actual = padre + 1;
				//printf("\nRegresando un nivel, padre= %d\n", padre);
				imprimenodo(padre);
				//printf("\n mov = %d\n", mov);
			}
			else{
				// No hay que regresar aun
				imprimenodo(actual-1); //Es actual-1 porque actual ya fue avanzado en cuanto se genero el nodo
				//Realizamos Prueba de meta, revisando el objetivo
				meta = 1;
				for (x=0; x<3; x++){
					for(y=0; y<3; y++){
						if (arbol[x][y][actual-1] != fin[x][y] ){
							meta = 0;
						}
					}
				}
				if ( meta == 1){
					x=0;
					actual--;
					z = actual;
					printf("\n..... RESULTADO");
					while( actual != 0){
						//solucion[z] = opcion[actual];
						solucion[x] = padrehijo[1][actual];
						actual = padrehijo[0][actual];
						x++;
					}
					for (x=z; x>=0; x--){
						imprimenodo(solucion[x]);
					}
					encontrado = 1;
				}
				// Por ultimo, avanzamos el padre a un nivel nuevo.
				padre++;
				mov = 0;
				//getch();
			}
		}

		//Fin del arbol
		if (padre < 0){
			// Si regresamos tanto que el padre ya no tiene opciones, es porque ya se termino de expandir todo el arbol.
			printf("\n\nLa solucion no se encontro en una profundidad de %d\n", profundidad);
			break;
		}

	} //while

	printf("\n\nPrograma terminado\n");
	return 0;
}