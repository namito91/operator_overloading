#include "Complejo.h" // definición de la clase Complejo


// Constructor
Complejo::Complejo( double parteReal, double parteImaginaria )
: real( parteReal ),
imaginaria( parteImaginaria )
{
// cuerpo vacío
} // fin del constructor de Complejo


// operador de suma
Complejo Complejo::operator+( const Complejo &operando2 ) const
{
    return Complejo( real + operando2.real,
        imaginaria + operando2.imaginaria );
} // fin de la función operator+


// operador de resta
Complejo Complejo::operator-( const Complejo &operando2 ) const
{
    return Complejo( real - operando2.real,
        imaginaria - operando2.imaginaria );
} // fin de la función operator—


// muestra un objeto Complejo en la forma: (a, b)
void Complejo::imprimir() const
{
    cout << '(' << real << ", " << imaginaria << ')';
} // fin de la función imprimir


istream& operator>>( istream& input , Complejo& c ){

    cout << "ingresa la parte real del n complejo : " << endl;
    input >> c.real;
    cout << "ingresa la parte imaginaria del n complejo : " << endl;
    input >> c.imaginaria;

    return input;
} 


ostream& operator<<( ostream& output , Complejo& c ){

    cout << "numero complejo : " << endl;
    output << "parte real : " << c.real << " ,parte imaginaria : " << c.imaginaria << endl;

    return output;
}


Complejo operator*( Complejo& a , Complejo& b ){

    // (1+4i)(5+i) = (1)(5)+(1)(i)+(4i)(5)+(4i)(i)
    double primerT, segundoT, tercerT, cuartoT;
    primerT  = (a.real) * (b.real);
    segundoT = a.real * b.imaginaria;
    tercerT  = a.imaginaria * b.real;
    cuartoT  = a.imaginaria * b.imaginaria;

    tercerT = segundoT + tercerT;
    cuartoT = -cuartoT;
    primerT = primerT + cuartoT;

    Complejo res( primerT , tercerT );

    return res;
}


bool Complejo::operator==( Complejo c ){

    if ( this->real == c.real && this->imaginaria == c.imaginaria ) return true;

    return false;
}


bool Complejo::operator!=( Complejo c ){

    return !( *this == c );
}
