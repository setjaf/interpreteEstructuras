//Librerias base
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Importación de archivos declaración de estructuras
#include "cola.h"
#include "pila.h"
#include "lista.h"

#include "ListaPila.h"
#include "ListaCola.h"
#include "ListaLista.h"

char acciones[9][10]={"crea","inserta","borra","muestra","extrae","vacia","anexa","limpia","salir"};
char objetos[3][10]={"pila","cola","lista"};
char calificativos[5][15]={"impares","pares","menor","mayor","aleatorios"};
int accionesN=9, objetosN=3,califN=5;
/************************** Declaracion de funciones ********************************************/
int isnumber(char *string);

void crear(int cantidad, char **nombres,ListaLL *lista, ListaLP *pila, ListaLC *cola);

void inserta(char **nombres,int cuantos, char *numero, int calif, int calif1, ListaLL *Llista, ListaLP *Lpila, ListaLC *Lcola);

void borra(int cantidad, char **nombres,ListaLL *lista, ListaLP *pila, ListaLC *cola);

/************************** Termina**************************************************************/

int main(int argc, char const *argv[])
{
	int numNombres=0;
	char **nombres=(char **)malloc(numNombres*sizeof(char **));
	int tarea[6]={0,0,0,0,0,0};
	char opc[200], *palabra, numero[50]={'\0'};
	ListaLL *lista = new ListaLL();
	ListaLP *pila = new ListaLP();
	ListaLC *cola = new ListaLC();

	do{
		printf("\nIntroduce lo que deseas hacer:\n");
		gets(opc);

		palabra=strtok(opc," ");

		while(palabra!=NULL){


			for (int i = 0; i < accionesN; ++i)
			{
				
				if(!strcmp(acciones[i],palabra)){
					tarea[0]=i+1;
					i=accionesN;
				}

			}

			for (int i = 0; i < objetosN; ++i)
			{
				
				if(strncmp(objetos[i],palabra,strlen(objetos[i]))==0){

					numNombres++;

					nombres=(char **)realloc(nombres,numNombres*sizeof(char **));
					
					nombres[numNombres-1]=(char *)calloc(50,sizeof(char *));

					strcpy(nombres[numNombres-1],palabra);

					tarea[1]=numNombres;

					i=objetosN;

				}

			}

			if (!strcmp(palabra,"numero"))
			{
				tarea[2]=1;
			}else if (!strcmp(palabra,"numeros"))
			{
				tarea[2]=2;
			}

			if(isnumber(palabra)){
				strcpy(numero,palabra);
				tarea[3]=1;
			}



			palabra=strtok(NULL," ");

		}

		switch(tarea[0]){

			case 1:
				crear(tarea[1],nombres,lista,pila,cola);
			break;

			case 2:
				inserta(nombres,tarea[2],numero,0,0,lista,pila,cola);
			break;

			case 3:
				borra(tarea[1],nombres,lista,pila,cola);
			break;

			case 9:
				printf("\nGracias por haber venido :)\n");
			break;

		}

		numNombres=0;

		nombres=(char **)realloc(nombres,numNombres*sizeof(char **));
		memset(numero,'\0',sizeof(numero));

	}while(tarea[0]!=9);


	return 0;
}




/*---------------------------- Inicia definicion de las funciones del interprete ------------------------------------*/
void crear(int cantidad, char **nombres,ListaLL *lista, ListaLP *pila, ListaLC *cola){

	for (int j = 0; j < cantidad; ++j)
	{

				
		
			switch(nombres[j][0]){
				case 'p':
					pila->Insertar(nombres[j]);
					printf("\nSe creo la pila: %s\n",pila->fin->nombre);
				break;

				case 'c':
					cola->Insertar(nombres[j]);
					printf("\nSe creo la cola: %s\n",cola->fin->nombre);
				break;

				case 'l':
					lista->Insertar(nombres[j]);
					printf("\nSe creo la lista: %s\n",lista->fin->nombre);
				break;
			}

		

	}

	
}
/**************************************************************************************************************/
void inserta(char **nombres,int cuantos, char *numero, int calif, int calif1,ListaLL *Llista, ListaLP *Lpila, ListaLC *Lcola){


	switch(nombres[0][0]){
		case 'p':
			if (cuantos==1 || cuantos==0 )
			{
				Lpila->aux=Lpila->inicio;
				//Se busca en la lista de pilas la pila con el nombre indicado

				if(numero[0]=='\0'){
					printf("\nIndica el numero que deseas Insertar\n");
					Lpila->aux=NULL;
				}

				while(Lpila->aux!=NULL){

					//Cuando se encuentra, se llama al metodo Insertar y se agrega el dato

					if (!strcmp(nombres[0],Lpila->aux->nombre))
					{
						Lpila->aux->pila->Insertar(numero);
						Lpila->aux->pila->Mostrar();
					}

					Lpila->aux=Lpila->aux->siguiente;

				}

			}
		break;

		case 'c':

			if (cuantos==1 || cuantos==0)
			{
				Lcola->aux=Lcola->inicio;
				if(numero[0]=='\0'){
					printf("\nIndica el numero que deseas Insertar\n");
					Lcola->aux=NULL;
				}

				while(Lcola->aux!=NULL){

					if (!strcmp(nombres[0],Lcola->aux->nombre))
					{
						Lcola->aux->cola->Insertar(numero);
						Lcola->aux->cola->Mostrar();
					}

					Lcola->aux=Lcola->aux->siguiente;

				}

			}

		break;

		case 'l':

			if (cuantos==1 || cuantos==0)
			{
				Llista->aux=Llista->inicio;
				if(numero[0]=='\0'){
					printf("\nIndica el numero que deseas Insertar\n");
					Llista->aux=NULL;
				}

				while(Llista->aux!=NULL){

					if (!strcmp(nombres[0],Llista->aux->nombre))
					{
						Llista->aux->lista->Insertar(numero);
						Llista->aux->lista->Mostrar();
					}

					Llista->aux=Llista->aux->siguiente;

				}

			}

		break;
	}
		

}
/*************************************************************************************************************/
void borra(int cantidad, char **nombres, ListaLL *lista, ListaLP *pila, ListaLC *cola){
	printf("\nBorrando ando\n");

	for (int j = 0; j < cantidad; ++j)
	{

				
		
			switch(nombres[j][0]){
				case 'p':
					pila->Borrar(nombres[j]);
				break;

				case 'c':
					cola->Borrar(nombres[j]);
				break;

				case 'l':
					lista->Borrar(nombres[j]);
				break;
			}

		

	}
}
/*--------------------------------------------------------------------------------------------------------*/

/***************************************** IsNumber *******************************************************/
int isnumber(char *string){
	/*Esta funcion verifica se el string es un numero flotante +(1), flotante -(2), entero +(3), entero -(4), si no es ninguno de estos devuelve (0) */
	bool point=false,negative=false;

	for (int i = 0; i < strlen(string); ++i)
	{

		if(string[i]<48 || string[i]>57){
			if(string[i]==46){
				if (point)
				{
					return 0;
				}else{
					point=true;
				}
			}else if(string[i]==45){
				if (negative || i!=0)
				{
					return 0;
				}else{
					negative=true;
				}
			}else{
				return 0;
			}
		}
	}

	if (point && !negative)
	{
		return 1;
	}else if (point && negative)
	{
		return 2;
	}else if (!point && !negative)
	{
		return 3;
	}else{
		return 4;
	}

	
}
/*************************************************************************************************************/