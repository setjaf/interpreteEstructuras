
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"


class NodoLL
{
public:
	Lista *lista;
	char nombre[50];
	NodoLL(char *nombre);
	NodoLL *siguiente;
};

NodoLL::NodoLL(char *nombre){

	lista=new Lista();
	strcpy(this->nombre,nombre);
	siguiente=NULL;
}

class ListaLL
{
public:

	NodoLL *inicio, *aux, *aux2, *fin;
	ListaLL(void);
	int nodos;	
	void Insertar(char *nombre);
	void Borrar(char *nombre);
	
};

ListaLL::ListaLL(void){
	aux=aux2=inicio=NULL;
	nodos=0;
}

void ListaLL::Insertar(char *nombre){
	if (this->nodos==0){

		this->fin=this->inicio=new NodoLL(nombre);
		this->nodos++;
	}else{
		//Lugar = 0 significa que se inserta en el final
		
		this->aux=new NodoLL(nombre);
		this->fin->siguiente=this->aux;
		this->fin=this->aux;
		this->nodos++;

	}
	
}


void ListaLL::Borrar(char *nombre){
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
	ListaLL *lista = new ListaLL();

	lista->Insertar("1");

	lista->Insertar("2");

	lista->Insertar("3");
	
	lista->Insertar("4");

	lista->aux=lista->inicio;

	while(lista->aux!=NULL){

		lista->aux->lista->Insertar("1");
		lista->aux->lista->Insertar("2");
		lista->aux->lista->Insertar("3");
	
		printf("%s\n", lista->aux->nombre);
		
		lista->aux->lista->Mostrar();
		
		lista->aux->lista->Extraer();
		
		lista->aux->lista->Mostrar();

		lista->aux=lista->aux->siguiente;

	}

	return 0;
}