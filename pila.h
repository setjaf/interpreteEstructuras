class NodoP{
	public:
		char dato[50];
		NodoP *anterior;	
		NodoP(char *dato_ext);
};


class Pila{
	public:
		NodoP *tope,*inicio,*aux;
		Pila();
		void Insertar (char *dato_ext);
		void Mostrar (void);
		void Extraer (void);	
};

/*
---------------- Constructores ----------------
*/

/***************** NodoP **********************/

NodoP::NodoP(char *dato_ext){
	strcpy(dato,dato_ext);
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
void Pila::Insertar(char *dato_ext){
	
	if(!this->tope){
		this->tope = new NodoP(dato_ext);
		this->inicio = tope;
	}else{
		this->aux=this->tope;
		this->tope=new NodoP(dato_ext);
		this->tope->anterior=this->aux;
	}

}

void Pila::Extraer(void){

	if(this->inicio==NULL){

		printf("Pila esta vacia\n");

	}else if(this->tope->anterior!=NULL){

		this->aux = this->tope->anterior;

		printf("\nEl dato que acabas de sacar de la pila es: %s \n", this->tope->dato);

		delete(this->tope);
		
		this->tope = this->aux;
	}else{

		printf("\nEl dato que acabas de sacar de la pila es: %s \n", this->tope->dato);

		delete(this->tope);

		this->inicio=this->tope=this->aux=NULL;

	}

			

}

void Pila::Mostrar(void){
	if(this->inicio==NULL){

		printf("Pila esta vacia\n");

	}else{
		printf("\nEl valor que esta en el tope de la lista es: %s\n", this->tope->dato);
	}
	
}


/*
---------------- Terminan Metodos --------------
*/