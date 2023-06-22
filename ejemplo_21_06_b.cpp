#include <iostream>
#include <stdlib.h>
using namespace std;

struct matriz{
	double **data;
	int filas;
	int columnas;
};


int creaMatriz(struct matriz *matrizA, int filas,int columnas)
//instancia una matriz usando apuntador a una estrucura matriz y la inicializa con ceros
{
	matrizA->filas=filas;
	matrizA->columnas=columnas;
	matrizA->data = (double **)malloc (filas * sizeof(double *));
	for (int i = 0; i < filas; i++) {
		matrizA->data[i] = (double *)malloc (columnas * sizeof(double));
		for(int j = 0; j < columnas; j++)
			matrizA->data[i][j]=0;
	}
	return 0;
}

int muestraMatriz(struct matriz *matrizA)
{
	cout << endl;
	for(int i = 0; i < matrizA->filas; i++) {
		for(int j = 0; j < matrizA->columnas; j++) {
			cout<< "\t "<<matrizA->data[i][j];
		}
		cout << endl;
	}
	return 0;
}

int llenaMatrizN(struct matriz *matrizA,double n) 
//crea matriz compuesta solo por valores n
{
	for(int i = 0; i < matrizA->filas; i++) {
		for(int j = 0; j < matrizA->columnas; j++) {
			matrizA->data[i][j]=n;
		}
	}
	return 0;
}

int llenaMatrizRand(struct matriz *matrizA,double n) 
//crea matriz compuesta por valores aleatorios entre 0 y n
{	
	for(int i = 0; i < matrizA->filas; i++) {
		for(int j = 0; j < matrizA->columnas; j++) {
			matrizA->data[i][j]=double(rand()%int(n));
		}
	}
	return 0;
}


int main()
{
	struct matriz *matrizA,*matrizB, *matrizC;
	
	matrizA = (struct matriz *)malloc (sizeof(struct matriz *));
	creaMatriz(matrizA,5,5);
	
	matrizB = (struct matriz *)malloc (sizeof(struct matriz *));
	creaMatriz(matrizB,5,5);
	
	matrizC = (struct matriz *)malloc (sizeof(struct matriz *));
	
	
	llenaMatrizN(matrizA,4);
	muestraMatriz(matrizA);

	llenaMatrizRand(matrizB,20);
	muestraMatriz(matrizB);

	return 0;
}
