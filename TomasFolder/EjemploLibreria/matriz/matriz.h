#include <iostream>
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
	cout <<endl;
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			cout<< "\t "<<matriz[i][j];
		}
		cout<<endl;
	}
	cout << endl;
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
int Multiplicacion(double **matrizA, double **matrizB , double **matrizD, int filas , int columnas){
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			matrizD[i][j]=matrizA[i][j]*matrizB[i][j];
		}
	}
	return 0;
}

int Transpuesta(double **matrizA, double **matrizF, int filas , int columnas){
	for(int i = 0; i < filas; i++) {
		for(int j = 0; j < columnas; j++) {
			matrizF[j][i]=matrizA[i][j];
		}
	}
	return 0;
}