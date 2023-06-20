#include <iostream>
#include <stdlib.h>
using namespace std;
double promedio(int *a , int n){
    int *ap;
    ap=a;
    double suma = 0;
    for(int i = 0 ; i < n ; i++)
        suma += *(ap+i);

    return suma;
}

int main(){

    int arregloU [10]={0, 1, 2, 3, 4, 5, 6, 7, 8, 9};

    double x = promedio(&arregloU[0] , 10);
    cout << "Resultado: " << x << "\n";

    int  *aparregloU = &arregloU[0];

    double y = promedio(aparregloU , 10 );
    cout << "Resultado: " << y << "\n";
}