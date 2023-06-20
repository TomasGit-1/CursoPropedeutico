#include <iostream>
#include <stdlib.h>
using namespace std;


int main()
{
	int arregloU [10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
	
	int *aparregloU;
		
	aparregloU=&arregloU[0];
	
	for (int i=0; i < 10; i++)     
	{       
		cout<<"arregloU[" << i << "] almacena " <<arregloU[i]<<"\t"; 
		cout<<"aparregloU " << aparregloU+i <<" almacena "<<*(aparregloU+i)<<endl; 
	}
	
	int *ptr;
	ptr= (int *)malloc ( 10*sizeof(int) );
	for (int i=0; i < 10; i++)
		*(ptr+i)=i;
	cout<<"contenido del arreglo";
	for (int i=0; i < 10; i++)
		cout <<*(ptr+i) << ", ";
	
	return 0;
}
