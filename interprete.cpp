#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char const *argv[])
{
	char opc[200], *palabra, nombre[30];
	char acciones[8][50]={"crea","inserta","borra","muestra","extrae","vacia","anexa","limpia"};
	char objetos[3][50]={"pila","cola","lista"};
	int tarea[4]={0,0,0,0}, accionesN=8, objetosN=3;



	printf("Introduce lo que deseas hacer:\n");
	gets(opc);

	palabra=strtok(opc," ");

	while(palabra!=NULL){

		for (int i = 0; i < accionesN; ++i)
		{
			
			if(strcmp(acciones[i],palabra)==0){
				printf("\nLa accion es: %s\n",acciones[i]);
				tarea[0]=i+1;
				i=accionesN;
			}

		}

		for (int i = 0; i < objetosN; ++i)
		{
			
			if(strncmp(objetos[i],palabra,strlen(objetos[i]))==0){
				printf("\nEl Objeto es: %s\n",palabra);
				tarea[1]=i+1;
				i=objetosN;
			}

		}	

		if (tarea[0]==0 || tarea[1]==0)
		{
			palabra=strtok(NULL," ");
		}else{
			palabra=NULL;
		}
		

	}


	if (tarea[0]==0)
	{
		printf("\nIndica una accion que entienda\n");
	}

	


	return 0;
}