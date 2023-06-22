#include <iostream>
#include <stdlib.h>
using namespace std;
struct vector{
	int *data;
	unsigned int size;
};

int creaVector(struct vector *v, int size){
	v->size=size;
	v->data=(int *)malloc (sizeof(int)*size);
	for (int i=0;i<size;i++)
		v->data[i]=0;
		//v->data+i=0;
	return 0;
}

int imprimirVector(struct vector *v){
	for(int i=0; i< v->size; i++){
   		cout <<" "<<v->data[i];
   }
   return 0;
}
int insertar(struct vector *v, int pos, int valor){
	if(pos<v->size)
		v->data[pos]=valor;
	else{
		struct vector *t;
		t = (struct vector *)malloc (sizeof(struct vector *));
		t->size=pos;
		t->data=(int *)malloc (sizeof(int)*pos);
		for(int i=0; i< v->size; i++)
			t->data[i]=v->data[i];
		t->data[pos]=valor;
		*v=*t;
		cout<<" v- "<<v<<" t- "<<t ;
	}
	return 0;
}
int main(){
	struct vector *v1;
	v1 = (struct vector *)malloc (sizeof(struct vector *));
	//cout<<" v1- "<<v1 ;
	creaVector(v1,5);
	imprimirVector(v1);
	
	insertar(v1,3,3);
	cout <<endl;
	imprimirVector(v1);
	
	insertar(v1,8,8);
	cout <<endl;
	imprimirVector(v1);
	return 0;
}
