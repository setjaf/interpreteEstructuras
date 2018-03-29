class NodoC
{
public:
	NodoC(int dato);
	int valor;
	NodoC *siguiente;
};

class Cola
{
public:
	Cola(void);
	NodoC *inicio, *aux, *aux2, *fin;
	int nodos;
	void Insertar(int dato);
	void Mostrar(void);
	void Borrar(void);
};


NodoC::NodoC(int dato){
	valor=dato;
	siguiente=NULL;
}


Cola::Cola(void){
	aux=aux2=inicio=NULL;
	nodos=0;
}

void Cola::Insertar(int dato){
	if (this->nodos==0){

		this->fin=this->inicio=new NodoC(dato);
		this->nodos++;
	}else{

		this->aux=new NodoC(dato);
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
			printf("%d - Posicion:%d\n",this->aux->valor,i);
			this->aux=this->aux->siguiente;
		}
	}

}


void Cola::Borrar(void){
	if (this->nodos<=0||this->inicio==NULL){

		printf("\nLa cola esta vacia\n");

	}else{
		//Lugar = 0 significa que se inserta en el final
		if (this->nodos==1)
		{
			printf("El número que sacaste es: %d",this->fin->valor);
			delete this->fin;
			this->nodos--;
			this->inicio=this->fin=this->aux=this->aux2=NULL;
		}
		else{
			printf("El número que sacaste es: %d",this->inicio->valor);
            this->aux=this->inicio;
			this->aux2=this->aux->siguiente;
			delete(this->aux);			
			this->nodos--;
			this->inicio=this->aux2;

		}

	}
}