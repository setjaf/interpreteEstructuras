class NodoC
{
public:
	NodoC(char *dato_ext);
	char dato[50];
	NodoC *siguiente;
};

class Cola
{
public:
	Cola(void);
	NodoC *inicio, *aux, *aux2, *fin;
	int nodos;
	void Insertar(char *dato_ext);
	void Mostrar(void);
	void Extraer(void);
};


NodoC::NodoC(char *dato_ext){
	strcpy(dato,dato_ext);
	siguiente=NULL;
}


Cola::Cola(void){
	aux=aux2=inicio=NULL;
	nodos=0;
}

void Cola::Insertar(char *dato_ext){
	if (this->nodos==0){

		this->fin=this->inicio=new NodoC(dato_ext);
		this->nodos++;
	}else{

		this->aux=new NodoC(dato_ext);
		this->fin->siguiente=this->aux;
		this->fin=this->aux;
		this->nodos++;
		printf("\nNodoCs %d\n",this->nodos);

	}
	
}

void Cola::Mostrar(void){
	if (nodos==0)
	{
		printf("\nLa cola esta vacia\n");
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


void Cola::Extraer(void){
	if (this->nodos<=0||this->inicio==NULL){

		printf("\nLa cola esta vacia\n");

	}else{
		//Lugar = 0 significa que se inserta en el final
		if (this->nodos==1)
		{
			printf("El número que sacaste es: %s",this->fin->dato);
			delete this->fin;
			this->nodos--;
			this->inicio=this->fin=this->aux=this->aux2=NULL;
		}
		else{
			printf("El número que sacaste es: %s",this->inicio->dato);
            this->aux=this->inicio;
			this->aux2=this->aux->siguiente;
			delete(this->aux);			
			this->nodos--;
			this->inicio=this->aux2;

		}

	}
}