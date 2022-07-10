#include <stdlib.h>
#include <stdio.h>

struct nodo {
	int data;
	struct nodo* siguiente;
};

struct cola{
	struct nodo *primero, *ultimo;
};

struct nodo* crearNodo(int data){
struct nodo* nuevo = (struct nodo*) malloc(sizeof(struct nodo));
nuevo->data = data;
nuevo->siguiente=NULL;
return nuevo;
}

struct cola* crearCola(){
	struct cola* c = (struct cola*) malloc(sizeof(struct cola));
	c->primero = c->ultimo = NULL;
	return c;
}

void agregar (int data, struct cola* *c){
	struct nodo* nuevo = crearNodo(data);
	if((*c)->primero==NULL){
		(*c)->primero = (*c)->ultimo = nuevo;
	}else {
		(*c)->ultimo->siguiente=nuevo;
	(*c)->ultimo = nuevo;
	}
	
}

void eliminar(struct cola* *c){
if ((*c)->primero == NULL)	
{
	printf("La cola esta vacia \n");
}
else {
	
struct nodo* eliminado = (*c)->primero;

(*c)->primero = eliminado->siguiente;
if ((*c)->primero==NULL) {
	(*c)->ultimo = NULL;
}
free(eliminado);
printf ("La mesa se ha eliminado de la lista de espera \n");
	
}

}

void mostrar(struct cola* *c){
	if((*c)->primero==NULL) {
	printf("La cola esta vacia \n");	
	}else {
	
	printf("Mesa %d \n", (*c)->primero->data);
}
}

int main(){
	struct cola* c = crearCola();
	int repetidor = true;
	int opcion;

	while(repetidor){
printf ("Introduzca el numero de la opcion de su preferencia: \n 1) Agregar mesa a la lista de espera \n 2) Mostrar la primera mesa en la lista de espera \n 3) Eliminar la primera mesa de la lista de espera \n 4) Finalizar operaciones\n");
scanf ("%d", &opcion);
switch(opcion){
	case 1:
	int mesa;
	printf("Introduzca el numero de la mesa \n");
	scanf ("%d", &mesa);
	agregar(mesa,&c);
	printf ("La mesa ha sido agregada a la lista de espera satisfactoriamente \n"); 
	system("pause");
system ("cls");
	break;
	case 2:
		mostrar(&c);
		system("pause");
system ("cls");
	break;
	case 3:
		eliminar(&c);
system("pause");
system ("cls");
	break;
	case 4:
		repetidor = false;
	break;
	default:
		printf("Introduzca una opcion validad \n");
		system("pause");
system ("cls");
break;
}

}

	return 0;
}

