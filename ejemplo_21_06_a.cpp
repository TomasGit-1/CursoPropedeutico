#include <iostream>
#include <stdlib.h>
using namespace std;

int matriz(double **matriz, int filas,int columnas)
//instancia una matriz usando apuntador doble 
{
	
	for (int i = 0; i < filas; i++) 
		matriz[i] = (double *)malloc (columnas * sizeof(double));
	return 0;
}

int muestraMatriz(double **matriz, int filas, int columnas)
{
	cout << endl;
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			cout<< "\t "<<matriz[i][j];
		}
		cout << endl;
	}
	return 0;
}

int creaMatrizN(double **matriz, int filas,int columnas, double n) 
//crea matriz compuesta solo por valores n
{
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			matriz[i][j]=n;
		}
	}
	return 0;
}

int creaMatrizRand(double **matriz, int filas,int columnas, double n) 
//crea matriz compuesta por valores aleatorios entre 0 y n
{	
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			matriz[i][j]=double(rand()%int(n));
		}
	}
	return 0;
}

int creaMatrizConsecutivos(double **matriz, int filas,int columnas, double n) 
//crea matriz compuesta por valores consecutivos a partir de n
{
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			matriz[i][j]=n++;
		}
	}
	return 0;
}

int sumaMatrices(double **matrizA,double **matrizB,double **matrizC, int filas,int columnas) //matrizC=matrizA+matrizB
{
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			matrizC[i][j]=matrizA[i][j]+matrizB[i][j];
		}
	}
	return 0;
}

//int sumaMatrices(int **matriz, int f,int c) //matrizC=matrizA+matrizB

int main21()
{
	
	double **matrizA;
	unsigned int filas, columnas; 
	cout<<"introduca la cantidad de filas de la matriz: ";
	cin >> filas;
	cout<<"introduca la cantidad de columnas de la matriz: ";
	cin >> columnas;
	
	matrizA = (double **)malloc (filas * sizeof(double *));
	for (int i = 0; i < filas; i++) 
		matrizA[i] = (double *)malloc (columnas * sizeof(double));
	
	// llenamos matrizA con consecutivos a partir de n 
	creaMatrizN(matrizA,filas,columnas,5);
	cout << "contenido de matrizA";
	muestraMatriz(matrizA,filas,columnas);

	double **matrizB;
	matrizB = (double **)malloc (filas * sizeof(double *));
	matriz(matrizB,filas,columnas);
	
	//llenamos matrizB con valores aleatorios entre 0 y n
	creaMatrizRand(matrizB,filas,columnas,20);
	muestraMatriz(matrizB,filas,columnas);

	
	double **matrizC;
	matrizC = (double **)malloc (filas * sizeof(double *));
	matriz(matrizC,filas,columnas);
	
	sumaMatrices(matrizA,matrizB,matrizC, filas,columnas);
	muestraMatriz(matrizC,filas,columnas);
	
	return 0;
}
