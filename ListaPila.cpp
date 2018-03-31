
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pila.h"

class NodoLP
{
public:
	Pila *pila;
	char nombre[50];
	NodoLP(char *nombre);
	NodoLP *siguiente;
};

NodoLP::NodoLP(char *nombre){
	
	pila=new Pila();
	strcpy(this->nombre,nombre);
	siguiente=NULL;
}

class ListaLP
{
public:

	NodoLP *inicio, *aux, *aux2, *fin;
	ListaLP(void);
	int nodos;	
	void Insertar(char *nombre);
	void Borrar(char *nombre);
	
};

ListaLP::ListaLP(void){
	aux=aux2=inicio=NULL;
	nodos=0;
}

void ListaLP::Insertar(char *nombre){
	if (this->nodos==0){

		this->fin=this->inicio=new NodoLP(nombre);
		this->nodos++;
	}else{
		//Lugar = 0 significa que se inserta en el final
		
		this->aux=new NodoLP(nombre);
		this->fin->siguiente=this->aux;
		this->fin=this->aux;
		this->nodos++;

	}
	
}


void ListaLP::Borrar(char *nombre){
	if (this->nodos<=0||this->inicio==NULL){

		printf("\nLa lista esta vacia\n");

	}else{
		//Lugar = 0 significa que se inserta en el final
		if (this->nodos==1)
		{
			delete this->fin;
			this->nodos--;
			this->inicio=this->fin=this->aux=this->aux2=NULL;
		}else{

			this->aux=this->inicio;

			while(this->aux!=NULL){

				if(strcmp(this->aux->siguiente->nombre,nombre)){
					this->aux=this->aux->siguiente;
				}

			}

			this->aux2=this->aux->siguiente;
			this->aux->siguiente=this->aux2->siguiente;
			delete(this->aux2);
			this->nodos--;		
		}

	}
}



int main(int argc, char const *argv[])
{
	ListaLP *lista = new ListaLP();

	lista->Insertar("1");

	lista->Insertar("2");

	lista->Insertar("3");
	
	lista->Insertar("4");

	lista->aux=lista->inicio;

	while(lista->aux!=NULL){

		lista->aux->pila->Insertar("1");
		lista->aux->pila->Insertar("2");
		lista->aux->pila->Insertar("3");
	
		printf("%s\n", lista->aux->nombre);
		
		lista->aux->pila->Mostrar();
		
		lista->aux->pila->Extraer();
		
		lista->aux->pila->Mostrar();

		lista->aux=lista->aux->siguiente;

	}

	return 0;
}