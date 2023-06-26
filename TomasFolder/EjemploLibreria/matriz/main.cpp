#include <iostream>
#include <stdlib.h>
#include "matriz.h"
using namespace std;

int main()
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
	
	cout<<endl;
	//Multiplicacion
	cout<<"multiplicacion"<<endl;
	//Creamos matriz d = para guardar las Multiplicaciona
	double **matrizD;
	matrizD = (double **)malloc (filas * sizeof(double *));
	matriz(matrizD,filas,columnas);
    Multiplicacion(matrizA,matrizB,matrizD, filas,columnas);
	muestraMatriz(matrizD,filas,columnas);
	
	//Transpuesta 
	double **matrizF;
	matrizF = (double **)malloc (filas * sizeof(double *));
	matriz(matrizF,filas,columnas);
    Transpuesta(matrizD,matrizF, filas,columnas);
	muestraMatriz(matrizF,filas,columnas);
	
	return 0;
}
