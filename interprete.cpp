#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int isnumber(char *string);


int main(int argc, char const *argv[])
{
	char opc[200], *palabra,numero[50]={'\0'};
	int numNombres=0;
	char **nombres=(char **)malloc(numNombres*sizeof(char **));
	char acciones[8][10]={"crea","inserta","borra","muestra","extrae","vacia","anexa","limpia"};
	char objetos[3][10]={"pila","cola","lista"};
	char calificativos[5][15]={"impares","pares","menor","mayor","aleatorios"};
	int tarea[6]={0,0,0,0,0,0}, accionesN=8, objetosN=3,califN=5,i=0;


	printf("Introduce lo que deseas hacer:\n");
	gets(opc);

	palabra=strtok(opc," ");

	while(palabra!=NULL){

		if (!strcmp(palabra,"numero"))
		{
			tarea[2]=1;
		}else if (!strcmp(palabra,"numeros"))
		{
			tarea[2]=2;
		}


		switch(isnumber(palabra)){
			case 1:
				strcpy(numero,palabra);
				tarea[3]=1;
				printf("Tenemos un flotante positivo: %f \n",atof(numero));
			break;

			case 2:
				strcpy(numero,palabra);
				tarea[3]=1;
				printf("Tenemos un flotante negativo: %f \n",atof(numero));
			break;

			case 3:
				strcpy(numero,palabra);
				tarea[3]=1;
				printf("Tenemos un entero positivo: %d \n",atoi(numero));
			break;

			case 4:
				strcpy(numero,palabra);
				tarea[3]=1;
				printf("Tenemos un entero negativo: %d \n",atoi(numero));
			break;
		}


		for (int i = 0; i < accionesN; ++i)
		{
			
			if(!strcmp(acciones[i],palabra)){
				printf("\nLa accion es: %s\n",acciones[i]);
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

				tarea[1]=i+1;
				i=objetosN;
			}

		}	


		for (int i = 0; i < califN; ++i)
		{
			
			if(!strcmp(calificativos[i],palabra)){
				printf("\nEl calificativo es: %s\n",palabra);
			}

		}

		
		if (tarea[0]==0 || tarea[1]==0 || tarea[2]==0)
		{
			palabra=strtok(NULL," ");
		}else{
			palabra=NULL;
		}
		

	}

	for (int i = 0; i < numNombres; ++i)
	{
		printf("\nEl Objeto es: %s\n",nombres[i]);
	}


	if (tarea[0]==0)
	{
		printf("\nIndica una accion que entienda\n");
	}

	


	return 0;
}


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