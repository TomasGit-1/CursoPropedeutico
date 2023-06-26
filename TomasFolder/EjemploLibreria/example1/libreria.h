#ifndef __LIBRERIA
#define __LIBRERIA

int matriz(double **matriz, int filas,int columnas);
int muestraMatriz(double **matriz, int filas, int columnas);
int creaMatrizN(double **matriz, int filas,int columnas, double n);
int creaMatrizRand(double **matriz, int filas,int columnas, double n) ;
int creaMatrizConsecutivos(double **matriz, int filas,int columnas, double n);
int sumaMatrices(double **matrizA,double **matrizB,double **matrizC, int filas,int columnas);

#endif
