#include <iostream>
using namespace std;

const int TamanioPredet = 10;

template < class T >
class Arreglo {
	public:
		// constructores
		Arreglo(int suTamanio = TamanioPredet); //Arreglo(), Arreglo(int)
		Arreglo(const Arreglo & rhs);
		~Arreglo(){ delete [] apTipo; }
		// operadores
		Arreglo & operator=(const Arreglo &);
		T & operator[](int desplazamiento){ 
			return apTipo[ desplazamiento ]; 
		}	 
		const T & operator[](int desplazamiento) const { 
			return apTipo[ desplazamiento ] ; 
		}
		// métodos de acceso 
		int getTamanio() const { 
			return suTamanio; 
		}
		friend ostream & operator<<(ostream &os, const Arreglo &vector ){
			if(vector.getTamanio()==0)
				os <<"\n[ Arreglo vacio ]";
			else{
				cout<<"\n"; 
				for(int i=0; i< vector.getTamanio(); i++){
   					os << "["<< i<<"]: "<<vector[i]<<"\n";
  				}
   				os <<"]";
			}
		}		

	private:
		T * apTipo; 
		int suTamanio;
};


template < class T >
Arreglo< T >::Arreglo(int tamanio): suTamanio(tamanio) //implementacion de Arreglo(int suTamanio = TamanioPredet);
{ 	apTipo = new T[ tamanio ]; // (int *)malloc(size(int)*tamaño)
	T *temp;
	for (int i = 0; i < tamanio; i++) {
		temp=new T(); 
		apTipo[i] = *temp;
	}
}

// constructor de copia 
template < class T >
Arreglo< T >::Arreglo(const Arreglo & rhs){
	suTamanio = rhs.ObtenerTamanio(); 
	apTipo = new T[ suTamanio ];
	for (int i = 0; i < suTamanio; i++) 
		apTipo[ i ] = rhs[ i ];
}

// operator= 
template < class T >
Arreglo< T > & Arreglo< T >::operator=(const Arreglo & rhs){
	if (this == &rhs) 
		return *this; 
	delete [] apTipo;
	suTamanio = rhs.ObtenerTamanio(); 
	apTipo = new T[ suTamanio ]; 
	for (int i = 0; i < suTamanio; i++) 
		apTipo[ i ] = rhs[ i ]; 
	return *this;
}


class Animal {
	public:
	Animal(int, int);
	Animal(){suPeso=1;suEdad=1;};
	~Animal() {} 
	int ObtenerPeso() const { return suPeso; } 
	int ObtenerEdad() const { return suEdad; } 
	friend ostream & operator<<(ostream &os, const Animal &a ){
		os <<"su peso es: " << a.suPeso << " su edad es: " << a.suEdad;
	}
	private:
		int suPeso;
		int suEdad;
};

Animal::Animal(int peso, int edad)
{	suPeso=peso;
	suEdad=edad;
}

int main(int argc, char** argv) {
	Arreglo< int > arregloEntero;
	Arreglo< double > arregloDouble;
	
	for (int i=0;i<10;i++){
		arregloEntero[ i ]=i+1;
		arregloDouble[ i ] =double(i)+0.1;
	}		
	
	cout <<arregloEntero;
	cout <<arregloDouble;
	
	Arreglo< Animal > bosque(20);
	Animal *apAnimal;
	for (int i=0;i<10;i++){
			apAnimal=new Animal(i+10,i*5);
		bosque[i]=*apAnimal;
	}
	cout << bosque;
	
	return 0;
}
