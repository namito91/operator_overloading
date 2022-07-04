#ifndef COMPLEJO_H
#define COMPLEJO_H
#include <iostream>
using namespace std;


class Complejo
{
    friend istream& operator>>( istream& , Complejo& );
    friend ostream& operator<<( ostream& , Complejo& );
    friend Complejo operator*( Complejo& , Complejo& );
    
    public:
        Complejo( double = 0.0, double = 0.0 ); // constructor
        Complejo operator+( const Complejo & ) const; // suma
        Complejo operator-( const Complejo & ) const; // resta    
        void imprimir() const; // salida
        bool operator==( Complejo );
        bool operator!=( Complejo );    

    private:
        double real; // parte real
        double imaginaria; // parte imaginaria
}; // fin de la clase Complejo

#endif
