#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct Nodo {
	char nombre[50];
	struct Nodo* siguiente;
} Nodo;
typedef struct Lista {
	Nodo* cabeza;
	int longitud;
} Lista;

struct Lista* crearLista(){
	struct Lista* lista = (struct Lista*) malloc(sizeof(struct Lista));
	lista->cabeza = NULL;
	lista->longitud = 0;
	return lista;
}
Nodo* CrearNodo(char *nombre){
	Nodo* nodo = (Nodo*) malloc (sizeof (Nodo));
	strncpy(nodo->nombre, nombre, 50);
	nodo->siguiente=NULL;
	return nodo;
}
void DestruirNodo(Nodo* nodo) {
	free(nodo);
}
void insertarComienzo(Lista* lista, char *nombre){
	Nodo* nodo = CrearNodo(nombre);
	nodo->siguiente = lista->cabeza;
	lista->cabeza = nodo;
	lista->longitud++;
	}
void insertarFinal(Lista* lista, char *nombre){
	Nodo*nodo = CrearNodo(nombre);
	if (lista->cabeza == NULL) {
		lista->cabeza = nodo;
	} else {
Nodo* puntero = lista->cabeza;
	while (puntero->siguiente){
		puntero = puntero->siguiente;	
}
puntero->siguiente = nodo;
}
lista->longitud++;
}
void InsertarN(int n, Lista* lista, char *nombre){
	n = n-1;
	Nodo* nodo = CrearNodo(nombre);
	if (lista->cabeza == NULL) {
		lista->cabeza == nodo;
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		} if (posicion != n){
			printf ("\n Ningun invitado se encuentra en esta posicion \n El valor se agregara al final de la lista \n");
			}
		nodo->siguiente = puntero->siguiente; //Conectamos el nuevo nodo con el nodo que va despues
		puntero->siguiente = nodo; 
		// Conectamos el nodo con el que le precede
	}
	lista->longitud++;
}
void Obtener(int n, Lista* lista){
	if (lista->cabeza == NULL){
		printf ("\n La lista esta vacia \n");
	} else {
			Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < n && puntero->siguiente){
			puntero = puntero->siguiente;
			posicion++;
		}
		if (posicion != n){
			printf ("\n Ningun invitado se encuentra en esta posicion \n");
		}else {
		printf("\n%s\n",&puntero->nombre);
	}
	}
}
int longitud(Lista* lista) {
	return lista->longitud;
}
void EliminarPrincipio(Lista* lista){
	if(lista->cabeza){
	Nodo* eliminado = lista->cabeza;
	lista->cabeza = lista->cabeza->siguiente;
	DestruirNodo(eliminado);
	lista->longitud--;
	printf ("Se ha eliminado el invitado de la lista\n");
}  else {
	printf("\n La lista ya se encuentra vacia \n");
}
}
void EliminarUltimo(Lista* lista){
	if(lista->cabeza){
		if(lista->cabeza->siguiente) {
		
		Nodo* puntero = lista->cabeza;
		while (puntero->siguiente->siguiente){
			puntero = puntero->siguiente;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente=NULL;
		DestruirNodo(eliminado);
		lista->longitud--;
		printf ("Se ha eliminado el invitado de la lista\n");
	} else {
		Nodo* eliminado = lista->cabeza;
		lista->cabeza = NULL;
		DestruirNodo(eliminado);
		lista->longitud--;
		printf ("Se ha eliminado el invitado de la lista\n");
	}
	} else{
		printf ("\n La lista ya se encuentra vacia \n");
	}
}
void EliminarN(int n, Lista* lista){
	if (lista->cabeza) {
		if (n == 0) {
			Nodo* eliminado = lista->cabeza;
			lista->cabeza = lista->cabeza->siguiente;
			DestruirNodo(eliminado);
			lista->longitud--;
			printf ("Se ha eliminado el invitado de la lista\n");
		} else if (n < lista->longitud) {
			Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while(posicion < (n - 1)) {
			puntero = puntero->siguiente;
			posicion++;
		}
		Nodo* eliminado = puntero->siguiente;
		puntero->siguiente = eliminado->siguiente;
		DestruirNodo(eliminado);
		lista->longitud--;	
		printf ("Se ha eliminado el invitado de la lista\n");
		}else{
			printf("\n No hay ningun invitado en esta posicion \n");
		}
	}
}
void MostrarLista(Lista* lista){
	if (lista->cabeza == NULL){
		printf("\n La lista se encuentra vacia \n");
	} else {
		Nodo* puntero = lista->cabeza;
		int posicion = 0;
		while (posicion < lista->longitud){
			printf(" %s \n", &puntero->nombre);
			puntero = puntero->siguiente;
			posicion++;
		}
	}
}


int main(){
	struct Lista* l = crearLista();
	int repetidor = true;
	int opcion;
	while (repetidor){
	
	printf ("Introduzca el numero de la opcion de su preferencia: \n");
	printf ("1 Agregar invitado \n");
	printf ("2 Buscar una posicion en la lista \n");
	printf ("3 Mostrar la lista completa \n");
	printf ("4 Saber cuantos invitados tiene la lista \n");
	printf ("5 Eliminar un invitado de la lista \n");
	printf ("6 Finalizar operaciones\n");
	scanf ("%d", &opcion);
	switch (opcion){
		case 1: 
		char nombre[50];
		int opcionAgregar;
		printf ("Introduzca el numero de la opcion de su preferencia: \n");
		printf ("1 Agregar al comienzo \n");
		printf ("2 Agregar al final \n");
		printf ("3 Introducir una posicion especifica \n");
		printf ("Introduzca otro numero para cancelar operacion \n");
		scanf ("%d", &opcionAgregar);
		switch(opcionAgregar){
			case 1: 
			printf ("\nIntroduzca el nombre del invitado \n");
			scanf ("%s", &nombre);
			insertarComienzo(l,nombre);
			break;
			case 2: 
			printf ("\nIntroduzca el nombre del invitado \n");
			scanf ("%s", &nombre);
			insertarFinal(l,nombre);
			break;
			case 3:
				int n;
			printf ("\nIntroduzca el nombre del invitado \n");
			scanf ("%s", &nombre);
			printf("Introduzca la posicion en la que desea introducir al invitado \n");
			scanf ("%d", &n);
			InsertarN(n,l,nombre);
			break;
			default:
			break;
		}
		system("pause");
system ("cls");
		break;
		case 2:
		int n; 
		printf("Introduzca la posicion en la que desea introducir al invitado \n");
		scanf ("%d", &n);
		Obtener(n,l);
		system("pause");
system ("cls");
		break;
		case 3:
		MostrarLista(l);
		system("pause");
system ("cls");
		break;
		case 4:	
		printf ("La lista tiene %d invitados \n", longitud(l));
		system("pause");
system ("cls");
		break;
		case 5:
		int opcionEliminar;
		printf ("Introduzca el numero de la opcion de su preferencia: \n");
		printf ("1 Eliminar al comienzo \n");
		printf ("2 Eliminar al final \n");
		printf ("3 Introducir una posicion especifica \n");
		printf ("Introduzca otro numero para cancelar operacion \n");
		scanf ("%d", &opcionEliminar);
		switch(opcionEliminar) {
			case 1: 
			EliminarPrincipio(l);
			break;
			case 2: 
			EliminarUltimo(l);
			break;
			case 3: 
			int n; 
		printf("Introduzca la posicion en la que desea introducir al invitado \n");
		scanf ("%d", &n);
		EliminarN (n,l);
		
		default:
		break;
		}
		system("pause");
system ("cls");
		break;
		case 6:
			repetidor = false;
	break;
	default:
		printf("Introduzca una opcion validad \n");
		system("pause");
system ("cls");
	}

}
	return 0;
}
