class NodoP{
	public:
		int valor;
		NodoP *anterior;	
		NodoP(int valor_ext);
};


class Pila{
	public:
		NodoP *tope,*inicio,*aux;
		Pila();
		void insertar (int valor_ext);
		void mostrar (void);
		void extraer (void);	
};

/*
---------------- Constructores ----------------
*/

/***************** NodoP **********************/

NodoP::NodoP(int valor_ext){
	valor=valor_ext;
	anterior=NULL;
}

/**************** Pila ************************/

Pila::Pila(){
	this->tope=this->inicio=this->aux=NULL;
}

/*
------------ Terminan Constructores -----------
*/


/*
------------------ Metodos --------------------
*/

/****************** Pila **********************/
void Pila::insertar(int valor_ext){
	
	if(!this->tope){
		this->tope = new NodoP(valor_ext);
		this->inicio = tope;
	}else{
		this->aux=this->tope;
		this->tope=new NodoP(valor_ext);
		this->tope->anterior=this->aux;
	}

}

void Pila::extraer(void){

	if(this->inicio==NULL){

		printf("Cola esta vacia\n");

	}else if(this->tope->anterior!=NULL){

		this->aux = this->tope->anterior;

		printf("\nEl dato que acabas de sacar de la pila es: %d \n", this->tope->valor);

		delete(this->tope);
		
		this->tope = this->aux;
	}else{

		printf("\nEl dato que acabas de sacar de la pila es: %d \n", this->tope->valor);

		delete(this->tope);

		this->inicio=this->tope=this->aux=NULL;

	}

			

}

void Pila::mostrar(void){
	if(this->inicio==NULL){

		printf("Cola esta vacia\n");

	}else{
		printf("\nEl valor que esta en el tope de la lista es: %d\n", this->tope->valor);
	}
	
}


/*
---------------- Terminan Metodos --------------
*/