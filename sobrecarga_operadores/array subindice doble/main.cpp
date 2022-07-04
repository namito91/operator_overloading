#include <iostream>
#include <algorithm>
#include <cstdlib>
#include <iomanip>
using namespace std;



class ArregloSubindiceDoble{

    friend ostream &operator<<( ostream &salida, const ArregloSubindiceDoble &s );
    friend istream &operator>>( istream &salida, const ArregloSubindiceDoble &s );

    private:
        int* array;
        int fila,columna;
    public:
        ArregloSubindiceDoble( int x=5 , int y = 5 ){
            this->fila = x;
            this->columna = y;
            array = new int[fila*columna];
            fill_n(array,fila*columna , 0);
            
        };    
        ~ArregloSubindiceDoble(){
            delete [] array;
        };


        int& operator()(int a,int b){    // left value modificable

            if ( a <= fila && b <= columna)
                return *(array + (a*columna)  + b);
                
            
            cout << "indices fuera de rango"<<endl;
            exit(1); 
        }; 
    

        const int& operator()(int a,int b) const{    // right value

            if ( a <= fila && b <= columna)
                return (*(array + ((a*columna)+1)  + b));
        

            cout << "indices fuera de rango" << endl;
            exit(1);      
        };

        
        // operadores :  ==, != , =, << , >>

        void operator==( ArregloSubindiceDoble &arr ){

            if ( arr.fila != this->fila || arr.columna != this->columna ) {
                cout << "los arreglos son distintos(indices)" << endl;
            }
            else if (!(arr.fila != this->fila)){
                if (!(arr.columna != this->columna)){

                    for (int i = 0; i < fila*columna; i++)
                    {
                        if ( this->array[i] != arr.array[i] ){
                            cout << "los arreglos son distintos(valores)"<< endl;        
                            return;
                        }

                    }

                    cout << "los arreglos son iguales" << endl;    
                }          
            }
        }



        void operator!=( ArregloSubindiceDoble &arr ){

            if ( arr.fila != this->fila || arr.columna != this->columna ) {
                cout << "los arreglos son distintos(indices)" << endl;
            }
            else if (!(arr.fila != this->fila)){
                if (!(arr.columna != this->columna)){

                    for (int i = 0; i < fila*columna; i++)
                    {
                        if ( this->array[i] != arr.array[i] ){
                            cout << "los arreglos son distintos(valores)"<< endl;        
                            return;
                        }

                    }

                    cout << "los arreglos no son distintos" << endl;    
                }          
            }
        }



        const ArregloSubindiceDoble& operator=( ArregloSubindiceDoble &arr ){

            if ( &arr != this ){
                
                if ( this->fila != arr.fila ) this->fila = arr.fila;
                if ( this->columna != arr.columna ) this->columna = arr.columna;

                for (int i = 0; i < fila*columna; i++)
                    array[i] = arr.array[i];

                cout << "objeto modificado"<< endl;    
            
            }else 
                cout << "no se permite la autoasignacion del objeto a si mismo" << endl;
            
            return *this;
        }     
};


ostream &operator<<( ostream &salida, const ArregloSubindiceDoble &s ){

    for(int i = 0; i < (s.fila * s.columna) ; i++  ){
        
        cout << setw(5) << s.array[i];

        if ( (i+1) % s.columna == 0  ) cout << endl;

    }

    return salida;
}



istream &operator>>( istream &entrada, const ArregloSubindiceDoble &s ){

    cout << "ingrese los valores para el array" <<endl;

    for(int i = 0; i < (s.fila * s.columna) ; i++  ){

        cout << "elemento : " << i << endl;    
        entrada >> s.array[i];    
    
        if ( (i+1) % s.columna == 0  ) cout << endl;

    }

    return entrada;
}




int main(int argc, char const *argv[])
{
    
    ArregloSubindiceDoble a;
    ArregloSubindiceDoble b;
    ArregloSubindiceDoble c(2,2);

    a(4,0) = 55;
    b(4,0) = 45; 
    cout << a(4,0) << endl;

    a == b;
    a != b;
    a = a;
    
    cout << "arreglo a " << endl << a << endl;
    cout << "ingresando valores" << endl;
    cin >> c;
    cout << c;
    return 0;
}
