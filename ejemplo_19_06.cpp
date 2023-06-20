#include <iostream>
using namespace std;

int main()
{
unsigned short shortVar = 5; 
unsigned long longVar = 65535; 
double dVar = 0.4567;
float fVar = 0.1234f;

cout << "Variable de tipo short sin signo:\t"; 
cout << shortVar << "\n";
cout << "Dirección de variable de tipo short:\t"; 
cout << &shortVar << "\n";
cout << "tamaño en bytes del tipo unisgned short: "<< sizeof(shortVar) << "\n\n";


cout << "Variable de tipo long sin signo:\t"; 
cout << longVar << "\n";
cout << "Dirección de variable de tipo long:\t" ; 
cout << &longVar << "\n";
cout << "tamaño en bytes del tipo unsigned longt: "<< sizeof(longVar) << "\n\n";

cout << "Variable de tipo double :\t"; 
cout << dVar << "\n";
cout << "Dirección de variable de tipo double:\t" ;
cout << &dVar << "\n";
cout << "tamaño en bytes del tipo double: "<< sizeof(dVar) << "\n\n";

cout << "Variable de tipo double :\t"; 
cout << fVar << "\n";
cout << "Dirección de variable de tipo float:\t" ;
cout << &fVar << "\n";
cout << "tamaño en bytes del tipo double: "<< sizeof(fVar) << "\n\n";

int *aptInt=NULL;
int n=25;
aptInt=&n;

cout << "Variable de tipo apuntador entero :\t"; 
cout << aptInt << "\n";
cout << "Dirección de variable de tipo apuntador entero:\t" ;
cout << &aptInt << "\n";
cout << "Contenido de la dirccion a la que apunta la variable de tipo apuntador entero :\t"; 
cout << *aptInt << "\n";
cout << "tamaño en bytes del tipo apuntador entero: "<< sizeof(aptInt) << "\n\n";

n=30;
cout << "Contenido de la dirccion a la que apunta la variable de tipo apuntador entero :\t"; 
cout << *aptInt << "\n";

int laVariable = 5;
int *apApuntador = 0;
cout << *apApuntador << "\n";
*apApuntador=10;

cout << "xxxxx"<<*apApuntador << "\n";


return 0;
}
