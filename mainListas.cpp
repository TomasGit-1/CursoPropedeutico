#include <iostream>
using namespace std;

class Nodo
{
	private:
		int dato;
		Nodo *siguiente;	
	public:
		Nodo(int);    //constructor
		int getDato(){return dato;}
		void setDato(int d){dato=d;}
		Nodo * getSiguiente(){return siguiente;}
		void setSiguiente(Nodo *s){siguiente=s;}
		 
};

Nodo::Nodo(int dato){
    this->dato = dato;
	this->siguiente = NULL;
}

class Lista
{
	private:
		Nodo *cabeza;
    	void agregarRecursivo(Nodo *, int );
    	void imprimirRecursivo(Nodo *);
    	void eliminarRecursivo(Nodo *, int );
    	bool existeRecursivo(Nodo *, int );
	public:
    	Lista(){this->cabeza == NULL;}
    	void eliminar(int );
    	void agregar(int ); 
    	void imprimir();  //agegar sobrecarga <<
    	bool existe(int);   
};

void Lista::agregarRecursivo(Nodo *n, int dato){
    if (n->getSiguiente() == NULL)
        n->setSiguiente( new Nodo(dato));
    else 
        this->agregarRecursivo(n->getSiguiente(), dato);
}

void Lista::imprimirRecursivo(Nodo *n){
    if (n != NULL) {
        std::cout << "Tenemos " << n->getDato() << std::endl;
        this->imprimirRecursivo(n->getSiguiente());
    }
}

void Lista::eliminarRecursivo(Nodo *n, int dato){ 
    if (n == NULL)
        return;
    if (n->getDato() == dato && n == this->cabeza){
        Nodo *temporal = this->cabeza;
        if (this->cabeza->getSiguiente() != NULL){
            this->cabeza = this->cabeza->getSiguiente();
            delete temporal;
        }
        else
            this->cabeza = NULL;
        return;
	}
    if (n->getSiguiente() != NULL && n->getSiguiente()->getDato() == dato) {
    	Nodo *temporal = n->getSiguiente();
        if (n->getSiguiente() != NULL)
                n->setSiguiente(n->getSiguiente()->getSiguiente());
    	delete temporal;
    }
    else 
        this->eliminarRecursivo(n->getSiguiente(), dato);
}

bool Lista::existeRecursivo(Nodo *n, int dato){
        if (n == NULL)
            return false;
        if (n->getDato() == dato)
            return true;
        return this->existeRecursivo(n->getSiguiente(), dato);
    }
 
void Lista::eliminar(int dato){
        this->eliminarRecursivo(this->cabeza, dato);
}

void Lista::agregar(int dato){
    if (this->cabeza == NULL)
        this->cabeza = new Nodo(dato);
    else
        this->agregarRecursivo(this->cabeza, dato);    
}

void Lista::imprimir(){
    cout << "Imprimiendo " << std::endl;
    this->imprimirRecursivo(this->cabeza);
}
    
bool Lista::existe(int dato){
    return this->existeRecursivo(this->cabeza, dato);
}


int main()
{
    Lista l;
    cout<<"lista sin nodos\n";
    l.imprimir();
    l.agregar(1);
    cout<<"lista con 1 nodo\n";
    l.imprimir();
    l.eliminar(1);
    l.agregar(2);
    l.agregar(3);
    l.agregar(4);
    l.agregar(5);
    cout<<"lista con 4 nodos\n";
    l.imprimir();
    l.eliminar(3);
    cout<<"lista con 3 nodos\n";
    l.imprimir();
    l.agregar(3);
    l.eliminar(1);
    l.eliminar(2);
    l.eliminar(3);
    l.eliminar(4);
    l.eliminar(5);
    l.imprimir();
    cout<<"lista con n nodos\n";
    l.agregar(123);
    l.agregar(123);
    l.agregar(123);
    l.agregar(123);
    l.agregar(88);
    l.agregar(123);
    l.agregar(123);
    l.agregar(88);
    l.agregar(123);
    l.agregar(88);
    l.agregar(60);
    l.imprimir();
    
    //agregar a la clase un método que recibe como parametro una lista,
	// y crea una nueva lista sin elementos reptidos
    // el metodo se llamara compactar(parametros);  
    // código de prueba de compactar()
    //Lista sinDuplicados();
    //sinDuplicados->compactar(l);
    //sinDuplicados->imprimir();
}
