class NodoL
{
public:
	NodoL(char *dato_ext);
	char dato[50];
	NodoL *siguiente;
};

class Lista
{
public:
	Lista(void);
	NodoL *inicio, *aux, *aux2, *fin;
	int nodos;
	void Insertar(char *dato_ext, int lugar);
	void Mostrar(void);
	void Extraer(int lugar);
	void Ordenar(void);
};

NodoL::NodoL(char *dato_ext){
	strcpy(dato,dato_ext);
	siguiente=NULL;
}

Lista::Lista(void){
	aux=aux2=inicio=NULL;
	nodos=0;
}

void Lista::Insertar(char *dato_ext, int lugar=0){
	if (this->nodos==0){

		this->fin=this->inicio=new NodoL(dato_ext);
		this->nodos++;
	}else{
		//Lugar = 0 significa que se inserta en el final
		if (lugar==0 || lugar>nodos)
		{

			this->aux=new NodoL(dato_ext);
			this->fin->siguiente=this->aux;
			this->fin=this->aux;
			this->nodos++;

		}else if(lugar==1){

			this->aux2=new NodoL(dato_ext);
			this->aux2->siguiente=this->inicio;
			this->inicio=this->aux2;
			this->nodos++;
		}else{

			this->aux2=new NodoL(dato_ext);
			this->aux=this->inicio;

			for (int i = 1; i < lugar-1; ++i)
			{
				this->aux=this->aux->siguiente;
			}

			this->aux2->siguiente=this->aux->siguiente;
			this->aux->siguiente=this->aux2;
			this->nodos++;

		}

	}
	
}

void Lista::Mostrar(void){
	if (nodos==0)
	{
		printf("\nLa lista esta vacia\n");
	}else{
		this->aux=inicio;
		int i=0;
		while(this->aux!=NULL){
			i++;
			printf("%s - Posicion:%d\n",this->aux->dato,i);
			this->aux=this->aux->siguiente;
		}
	}

}


void Lista::Extraer(int lugar=0){
	if (this->nodos<=0||this->inicio==NULL){

		printf("\nLa lista esta vacia\n");

	}else{
		//Lugar = 0 significa que se inserta en el final
		if (this->nodos==1)
		{
			delete this->fin;
			this->nodos--;
			this->inicio=this->fin=this->aux=this->aux2=NULL;
		}
		else if (lugar==0 || lugar>=nodos)
		{
            this->aux=this->inicio;
            while(this->aux->siguiente->siguiente!=NULL){
				this->aux=this->aux->siguiente;
			}
			this->aux2=this->aux->siguiente;
			delete(this->aux2);			
			this->nodos--;
			this->fin=this->aux;
			this->fin->siguiente=NULL;

		}else if(lugar==1){

			this->aux=this->inicio->siguiente;
			delete(this->inicio);
			this->nodos--;
			this->inicio=this->aux;

		}else{
			this->aux=this->inicio;
			for (int i = 1; i < lugar-1; ++i)
			{
				this->aux=this->aux->siguiente;
			}
			this->aux2=this->aux->siguiente;
			this->aux->siguiente=this->aux2->siguiente;
			delete(this->aux2);
			this->nodos--;		}

	}
}