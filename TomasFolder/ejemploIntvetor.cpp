#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

class IntVector{
	private:
		int *data;
		unsigned int size;
	public:
		IntVector();
		IntVector(IntVector &);
		IntVector(unsigned int);
		~IntVector(){};
		void set(unsigned int, int);
		int get(unsigned int);
		void imprimir();
		IntVector & operator= (const IntVector &);
		
	friend ostream& operator << (ostream &os, const IntVector &vector ){
		if(vector.size==0)
			os <<"\n[ Vector vacio ]";
		else{
			os <<"\n[ ";
			for(int i=0; i< vector.size; i++){
   				os <<vector.data[i]<<" ";
  			}
   			os <<"]"<<endl;
		}
	}
		
	friend istream& operator >> (istream &i, IntVector &vector){
		if(vector.size==0)
			cout <<"\n[ Vector es de tama�o 0 ]";
		else{
			
		    cout << "Introducir valores para el vector:  \n";
			for(int i=0; i< vector.size; i++){
				cout<<"["<<i<<"]->";
				cin >> vector.data[i];
			}
		}
		i.ignore();
		return i;
	}
	
	int  &operator []( int indice ) { return data[indice]; }

  	IntVector  &operator ()( int indice1, int indice2 ){
		cout<<"Generando vector"<<endl;
		
		IntVector t;
		t.size = indice2 - indice1;
		t.data=(int *)malloc (sizeof(int)* t.size);
		cout<<t;
		int cont = indice1;
		for (int i = 0 ; i < indice2; i++){
			t.data[i]= this->data[indice1];
			indice1++;
		}
		cout<<t;
		return t;
		/*
		this->size = indice2 - indice1;
		this->data=(int *)malloc (sizeof(int)*this->size);
		for (int i=0; i<this->size;i++ ){
			this->set(i,1);
		}
		*/
		/*
		IntVector t;

		//size = indice2 - indice1;
		this->size = (indice2 - indice1);
		t.data = (int *)malloc (sizeof(int)*(indice2 - indice1));
		for (int i = 0 ; i < indice2; i++){
			t[i]= this->data[indice1];
			indice1++;
		}
		cout<<t;
		return *this;
		*/
	}
	  	
	
};

IntVector::IntVector()
{
	this->size=0;
	this->data=(int *)malloc (sizeof(int));
	this->data[0]=0;
}


IntVector::IntVector(unsigned int size)
{
	this->size=size;
	this->data=(int *)malloc (sizeof(int)*size);
	for (int i=0;i<size;i++)
		this->data[i]=0;
}

IntVector::IntVector(IntVector & otro)
{
	this->size=otro.size;
	this->data=(int *)malloc (sizeof(int)*(this->size));
	for (int i=0;i<this->size;i++)
		this->data[i]=otro.data[i];
}

void IntVector::imprimir()
{
	if(this->size==0)
		cout <<"\n[ Vector vacio ]";
	else{
		cout <<"\n[ ";
		for(int i=0; i< this->size; i++){
   			cout <<this->data[i]<<" ";
  		}
   		cout <<"]"<<endl;
   }
}

void IntVector::set(unsigned int pos, int valor)
{
	if(pos<this->size)
		this->data[pos]=valor;
	else{
		int *t;
		t=(int *)malloc (sizeof(int)*pos+1);
		for(int i=0; i< this->size; i++)
			t[i]=this->data[i];
		for(int i=this->size; i< pos; i++)
			t[i]=0;	
		t[pos]=valor;
		this->data=t;
		this->size=pos+1;
	}
}

int IntVector::get(unsigned int pos)
{
	if(pos<this->size)
		return this->data[pos];
	else{
		cout <<"\nindice fuera de rango ";
		return 0;	
	}	
}

IntVector & IntVector::operator= (const IntVector & ladoDerecho)
{
    if(this == &ladoDerecho)
		return *this; 
	else{
		this->size=ladoDerecho.size;
		this->data=(int *)malloc (sizeof(int)*this->size);
		for (int i=0; i<this->size;i++ ){
			this->set(i,ladoDerecho.data[i]);
		}
		return *this;
	}
	
}



int main(){
	IntVector v1;
	/*
	IntVector v2(10);
	
	for (int i=0; i<10;i++ ){
		v1.set(i,i);
		v2.set(i,i+20);
	}
	
	v1.imprimir();
	v2.imprimir();
	
	IntVector v3;
	v3=v1;
	
	v3.imprimir();
	
	cout<<v3;
	
	
	*/
	IntVector v4(5);
	cin >>v4;
	cout<<v4;
	
	//cout<<v4[2];
	//cin >>v4[2];
	//cout<<v4;
	

	v4(1,3);    
	cout<<v1;
	
	//int ind[]={1,3,4,1};  
	//vx=v4(ind);
	
	//int ind[]={"1,3,4,1"};  
	//vx=v4(ind);	
	return 0;
} 
