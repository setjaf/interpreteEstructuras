//Librerias base
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Importación de archivos declaración de estructuras
#include "cola.h"
#include "pila.h"
#include "lista.h"

#include "ListaPila.h"
#include "ListaCola.h"
#include "ListaLista.h"


char acciones[9][10]={"crea","inserta","borra","muestra","extrae","anexa","limpia","salir"};
char objetos[3][10]={"pila","cola","lista"};
char calificativos[5][15]={"impares","pares","menor","mayor","aleatorios"};
int accionesN=8, objetosN=3,califN=5;
/************************** Declaracion de funciones ********************************************/
int isnumber(char *string);

void crear(int cantidad, char **nombres,ListaLL *lista, ListaLP *pila, ListaLC *cola);

void inserta(char **nombres,int cuantos, char *numero, int calif, int calif1, ListaLL *Llista, ListaLP *Lpila, ListaLC *Lcola);

void borra(int cantidad, char **nombres,ListaLL *lista, ListaLP *pila, ListaLC *cola);

void muestra(char **nombres,ListaLL *lista, ListaLP *pila, ListaLC *cola);
/************************** Termina**************************************************************/

int main(int argc, char const *argv[])
{
	int numNombres=0,numCalif=0;
	char **nombres=(char **)malloc(numNombres*sizeof(char **));
	int tarea[6]={0,0,0,0,0,0};
	char opc[200], *palabra, numero[50]={'\0'};
	ListaLL *lista = new ListaLL();
	ListaLP *pila = new ListaLP();
	ListaLC *cola = new ListaLC();

	srand(time(NULL));

	do{
		for (int i = 0; i < 6; ++i)
		{
			tarea[i]=0;
		}
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

			if (!strcmp(palabra,"pares"))
			{
				tarea[4]=1;
			}else if (!strcmp(palabra,"impares"))
			{
				tarea[4]=2;
			}

			if (!strcmp(palabra,"aleatorios"))
			{
				tarea[5]=1;
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
				if(tarea[1]>0)
					inserta(nombres,tarea[2],numero,tarea[4],tarea[5],lista,pila,cola);
				else
					printf("\n Ingresa un nombre que sea valido\n");
			break;

			case 3:
				borra(tarea[1],nombres,lista,pila,cola);
			break;

			case 4:
				muestra(nombres,lista,pila,cola);
			break;

			case 8:
				printf("\nGracias por haber venido :)\n");
			break;

			default:
				printf("\nIngresa una instruccion valida\n");

		}

		numNombres=0;
		
		nombres=(char **)realloc(nombres,numNombres*sizeof(char **));
		memset(numero,'\0',sizeof(numero));

	}while(tarea[0]!=8);


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
void inserta(char **nombres,int cuantos, char *numero, int calif, int calif1, ListaLL *Llista, ListaLP *Lpila, ListaLC *Lcola){

	int numeroI=0;

	switch(nombres[0][0]){
		case 'p':
			if (cuantos==1 || cuantos==0 )
			{
				
				Lpila->aux=Lpila->inicio;
				//Se busca en la Lpila de pilas la pila con el nombre indicado

				if(numero[0]=='\0'){
					printf("\nIndica el numero que deseas Insertar\n");
					Lpila->aux=NULL;
				}

				while(Lpila->aux!=NULL && strcmp(nombres[0],Lpila->aux->nombre)){

					Lpila->aux=Lpila->aux->siguiente;	
					
				}

				if (Lpila->aux!=NULL)
				{
					Lpila->aux->pila->Insertar(numero);
					Lpila->aux->pila->Mostrar();
				}else{
					printf("\n No se encuentra el nombre que indicaste\n");
				}
				
			}else if(cuantos==2){

				Lpila->aux=Lpila->inicio;

				if(numero[0]=='\0'){
					printf("\nIndica la cantidad de numeros que deseas Insertar\n");
					Lpila->aux=NULL;
				}

				while(Lpila->aux!=NULL && strcmp(nombres[0],Lpila->aux->nombre)){

					Lpila->aux=Lpila->aux->siguiente;	
					
				}

				if (Lpila->aux!=NULL)
				{
					int k=atoi(numero);

					for (int i = 0; i < k; ++i)
					{

						if (calif1)//Entra en esta opcion si son aleatorios
						{
							if (calif==1)
							{
								do{
									numeroI=rand();
								}while(numeroI%2);
							}else if(calif==2){

								do{

									numeroI=rand();

								}while(!(numeroI%2));

							}else{
								numeroI=rand();
							}
							
						}
						else{//Entra si no son aleatorios

							if (calif==1){

								int j=0;
								do{
									numeroI=i+j;
									j++;
								}while(numeroI%2);

							}else if(calif==2){
								int j=0;
								do{

									numeroI=i+j;
									j++;

								}while(!(numeroI%2));

							}else{

								numeroI=i;

							}

						}
						sprintf(numero,"%d",numeroI);
						Lpila->aux->pila->Insertar(numero);
						Lpila->aux->pila->Mostrar();
					}
				}else{
					printf("\n No se encuentra el nombre que indicaste\n");
				}


			}
		break;

		case 'c':

			if (cuantos==1 || cuantos==0)
			{
				Lcola->aux=Lcola->inicio;
				//Se busca en la Lcola de pilas la pila con el nombre indicado

				if(numero[0]=='\0'){
					printf("\nIndica el numero que deseas Insertar\n");
					Lcola->aux=NULL;
				}

				while(Lcola->aux!=NULL && strcmp(nombres[0],Lcola->aux->nombre)){

					Lcola->aux=Lcola->aux->siguiente;	
					
				}

				if (Lcola->aux!=NULL)
				{
					Lcola->aux->cola->Insertar(numero);
					Lcola->aux->cola->Mostrar();
				}else{
					printf("\n No se encuentra el nombre que indicaste\n");
				}

			}else if(cuantos==2){

				Lcola->aux=Lcola->inicio;

				if(numero[0]=='\0'){
					printf("\nIndica la cantidad de numeros que deseas Insertar\n");
					Lcola->aux=NULL;
				}

				while(Lcola->aux!=NULL && strcmp(nombres[0],Lcola->aux->nombre)){

					Lcola->aux=Lcola->aux->siguiente;	
					
				}

				if (Lcola->aux!=NULL)
				{
					int k=atoi(numero);

					for (int i = 0; i < k; ++i)
					{

						if (calif1)//Entra en esta opcion si son aleatorios
						{
							if (calif==1)
							{
								do{
									numeroI=rand();
								}while(numeroI%2);
							}else if(calif==2){

								do{
									
									numeroI=rand();

								}while(!(numeroI%2));

							}else{
								numeroI=rand();
							}
							
						}
						else{//Entra si no son aleatorios

							if (calif==1){

								int j=0;
								do{
									numeroI=i+j;
									j++;
								}while(numeroI%2);

							}else if(calif==2){
								int j=0;
								do{

									numeroI=i+j;
									j++;

								}while(!(numeroI%2));

							}else{

								numeroI=i;

							}

						}
						sprintf(numero,"%d",numeroI);
						Lcola->aux->cola->Insertar(numero);
						Lcola->aux->cola->Mostrar();
					}
				}else{
					printf("\n No se encuentra el nombre que indicaste\n");
				}


			}

		break;

		case 'l':

			if (cuantos==1 || cuantos==0)
			{
				Llista->aux=Llista->inicio;
				//Se busca en la Llista de pilas la pila con el nombre indicado

				if(numero[0]=='\0'){
					printf("\nIndica el numero que deseas Insertar\n");
					Llista->aux=NULL;
				}

				while(Llista->aux!=NULL && strcmp(nombres[0],Llista->aux->nombre)){

					Llista->aux=Llista->aux->siguiente;	
					
				}

				if (Llista->aux!=NULL)
				{
					Llista->aux->lista->Insertar(numero);
					Llista->aux->lista->Mostrar();
				}else{
					printf("\n No se encuentra el nombre que indicaste\n");
				}

			}else if(cuantos==2){

				Llista->aux=Llista->inicio;

				if(numero[0]=='\0'){
					printf("\nIndica la cantidad de numeros que deseas Insertar\n");
					Llista->aux=NULL;
				}

				while(Llista->aux!=NULL && strcmp(nombres[0],Llista->aux->nombre)){

					Llista->aux=Llista->aux->siguiente;	
					
				}

				if (Llista->aux!=NULL)
				{
					int k=atoi(numero);

					for (int i = 0; i < k; ++i)
					{

						if (calif1)//Entra en esta opcion si son aleatorios
						{
							if (calif==1)
							{
								do{
									numeroI=rand();
								}while(numeroI%2);
							}else if(calif==2){

								do{
									
									numeroI=rand();

								}while(!(numeroI%2));

							}else{
								numeroI=rand();
							}
							
						}
						else{//Entra si no son aleatorios

							if (calif==1){

								int j=0;
								do{
									numeroI=i+j;
									j++;
								}while(numeroI%2);

							}else if(calif==2){
								int j=0;
								do{

									numeroI=i+j;
									j++;

								}while(!(numeroI%2));

							}else{

								numeroI=i;

							}

						}
						sprintf(numero,"%d",numeroI);
						Llista->aux->lista->Insertar(numero);						
					}
					Llista->aux->lista->Mostrar();
				}else{
					printf("\n No se encuentra el nombre que indicaste\n");
				}


			}

		break;
	}
		
}
/*************************************************************************************************************/
void borra(int cantidad, char **nombres, ListaLL *lista, ListaLP *pila, ListaLC *cola){

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

void muestra(char **nombres, ListaLL *lista, ListaLP *pila, ListaLC *cola){
	int i=0;
	switch(nombres[0][0]){
		case 'p':

			if(!strcmp(nombres[0],"pilas")){
				i=1;
				printf("\nLas pilas disponibles existentes son:\n");
			}

			pila->aux=pila->inicio;
			
			while(pila->aux!=NULL && strcmp(nombres[0],pila->aux->nombre)){
				if(i){
					printf("\n* %s \n",pila->aux->nombre);
				}
				pila->aux=pila->aux->siguiente;	

				
			}
			if (pila->aux!=NULL)
			{
				pila->aux->pila->Mostrar();
			}else{
				if(!i){
					printf("\n No se encuentra el nombre que indicaste\n");
				}
			}

		break;

		case 'c':

			if(!strcmp(nombres[0],"colas")){
				i=1;
				printf("\nLas colas disponibles existentes son:\n");
			}

			cola->aux=cola->inicio;
			
			while(cola->aux!=NULL && strcmp(nombres[0],cola->aux->nombre)){

				if(i){
					printf("\n* %s \n",cola->aux->nombre);
				}

				cola->aux=cola->aux->siguiente;	

				
			}
			if (cola->aux!=NULL)
			{
				cola->aux->cola->Mostrar();
			}else{
				if(!i){
					printf("\n No se encuentra el nombre que indicaste\n");
				}
			}
		break;

		case 'l':

			if(!strcmp(nombres[0],"listas")){
				i=1;
				printf("\nLas listas disponibles existentes son:\n");
			}

			lista->aux=lista->inicio;
			
			while(lista->aux!=NULL && strcmp(nombres[0],lista->aux->nombre)){

				if(i){
					printf("\n* %s \n",lista->aux->nombre);
				}

				lista->aux=lista->aux->siguiente;	

				
			}
			if (lista->aux!=NULL)
			{
				lista->aux->lista->Mostrar();
			}else{
				if(!i){
					printf("\n No se encuentra el nombre que indicaste\n");
				}
				
			}

		break;
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