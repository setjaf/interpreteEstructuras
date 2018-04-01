class NodoLC
{
public:
	Cola *cola;
	char nombre[50];
	NodoLC(char *nombre);
	NodoLC *siguiente;
};

NodoLC::NodoLC(char *nombre){

	cola=new Cola();
	strcpy(this->nombre,nombre);
	siguiente=NULL;
}

class ListaLC
{
public:

	NodoLC *inicio, *aux, *aux2, *fin;
	ListaLC(void);
	int nodos;	
	void Insertar(char *nombre);
	void Borrar(char *nombre);
	void Mostrar(char *nombre);
	
};

ListaLC::ListaLC(void){
	aux=aux2=inicio=NULL;
	nodos=0;
}

void ListaLC::Insertar(char *nombre){
	if (this->nodos==0){

		this->fin=this->inicio=new NodoLC(nombre);
		this->nodos++;
	}else{
		//Lugar = 0 significa que se inserta en el final
		
		this->aux=new NodoLC(nombre);
		this->fin->siguiente=this->aux;
		this->fin=this->aux;
		this->nodos++;

	}
	
}




void ListaLC::Borrar(char *nombre){
	if (this->nodos<=0||this->inicio==NULL){

		printf("\nNo se han creado Colas\n");

	}else{
		//Lugar = 0 significa que se inserta en el final
		if (this->nodos==1 && !strcmp(this->fin->nombre,nombre))
		{
			delete this->fin;
			printf("\nSe ha borrado %s\n",nombre);
			this->nodos--;
			this->inicio=this->fin=this->aux=this->aux2=NULL;
		}else{
			this->aux=this->inicio;

			if (!strcmp(this->aux->nombre,nombre))
			{
				this->aux2=this->aux->siguiente;
				this->inicio=this->aux2;
				delete(this->aux);
				printf("\nSe ha borrado %s\n",nombre);
				this->nodos--;

			}else{

				while(this->aux!=NULL && strcmp(this->aux->siguiente->nombre,nombre)){
					
					this->aux=this->aux->siguiente;

				}
				if(this->aux!=NULL){	

					this->aux2=this->aux->siguiente;
					
					if (this->aux2==this->fin)
					{
						this->fin=this->aux;
					}

					this->aux->siguiente=this->aux2->siguiente;
					delete(this->aux2);
					printf("\nSe ha borrado %s\n",nombre);
					this->nodos--;
				}else{
					printf("\n No se encontró el nombre indicado\n");
				}


			}

				
		}

	}
}
