#include <iostream>
#include <random>

using namespace std;
class DoubleMatriz{
    private:
        double **data;
        unsigned int filas;
        unsigned int columnas;

    public:
        DoubleMatriz();
        //Contructir copia
        DoubleMatriz(DoubleMatriz const &); 
        // Crea una matriz de nxm con puros ceros
        DoubleMatriz(unsigned int n , unsigned int m){
            cout<<"Matriz con ceros"<<endl;
            this->filas = n;
            this->columnas = m;
            this->data = (double **)malloc (this->filas * sizeof(double *));
            for (int i = 0; i < this->filas; i++) 
                this->data[i] = (double *)malloc (columnas * sizeof(double));
        }
        /*
            Crea una matriz de nxm
            op==0 , llena de cero,
            op==1 , valores aleatorios en [0,1]
            op==2 , consecutivos crecientes  
        */
        DoubleMatriz(unsigned int n , unsigned int m , int op){
            cout<<"Matriz con condiciones"<<endl;
            this->filas = n;
            this->columnas = m;
            this->data = (double **)malloc (this->filas * sizeof(double *));
            for (int i = 0; i < this->filas; i++) 
                this->data[i] = (double *)malloc (columnas * sizeof(double));
            if(op== 0){
                for(int i = 0; i < this->filas; i++) {
                    for(int j = 0; j < this->columnas; j++) {
                        this->data[i][j] = 0 ;
                    }
                }
            }else if (op == 1){
                for(int i = 0; i < this->filas; i++) {
                    for(int j = 0; j < this->columnas; j++) {
                        this->data[i][j] = ((double) rand() / (RAND_MAX));
                        //this->data[i][j] = double(rand()%int(1));
                    }
                }
            }else if (op == 2){
                int conta = 0;
                for(int i = 0; i < this->filas; i++) {
                    for(int j = 0; j < this->columnas; j++) {
                        this->data[i][j] = conta++;
                    }
                }

            }else{
                cout<<"ERROR: Invalid";
            }
            
        }
        
        //Crea una matriz de nxn con x en la diagonal
        /*
        DoubleMatriz(unsigned int n , double x ){
            cout<<"Matriz con diagonal"<<endl;
            this->filas = n;
            this->columnas = n;
            this->data = (double **)malloc (this->filas * sizeof(double *));
            for (int i = 0; i < this->filas; i++) 
                this->data[i] = (double *)malloc (columnas * sizeof(double));
                
            for(int i = 0; i < this->filas; i++) {
                    for(int j = 0; j < this->columnas; j++) {
                        if (i == j)
                            this->data[i][j] = x;
                        else
                            this->data[i][j] = 0 ;
                    }
                }
        }
        */
        //~DoubleMatriz();
        void set(unsigned int f , unsigned int c , double valor);
        double get(unsigned int f , unsigned int c);
        
        //Regresa la subMatriz
        DoubleMatriz subMatriz(unsigned int r1 , unsigned int r2 , unsigned int c1 , unsigned int c2){
            double **data_temp; 
            data_temp =  (double **)malloc (c2 * sizeof(double *));
            this->filas = r2;
            this->columnas = c2; 
            for (int i = 0; i <c2; i++) 
                data_temp[i] = (double *)malloc (columnas * sizeof(double));

            for (int  i = r1; i < r2; i++){
                for (int j = c1; j < c2; j ++){
                    data_temp[i][j] = this->data[i][j];
                    cout<< this->data[i][j]<<endl;
                }
            }
            this->data = data_temp;
        }

        //Imprime la matriz
        void imprime(){
            cout << endl;
            for(int i = 0; i < this->filas; i++) {
                for(int j = 0; j < this->columnas; j++) {
                    cout<< "\t "<<this->data[i][j];
                }
                cout << endl;
            }
        }
};

int main(){
    DoubleMatriz A = DoubleMatriz(6 , 6 , 1);
    A.imprime();

    // DoubleMatriz B = DoubleMatriz(5 , 8 , 1);
    // B.imprime();

    // double value = 2.3;
    // DoubleMatriz C = DoubleMatriz(10, value);
    // C.imprime();

    DoubleMatriz subM = DoubleMatriz(A.subMatriz(1 , 3 , 1 , 4));
    subM.imprime();

    return 0;

}