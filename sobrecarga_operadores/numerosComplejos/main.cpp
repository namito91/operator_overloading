#include "Complejo.h"


int main()
{
    
    Complejo x;
    Complejo y( 4.3, 8.2 );
    Complejo z( 3.3, 1.1 );
    cin >> x;
    cout << x;
    Complejo p;
    p = (y*z);
    cout << p;

    cout << (y != z) << endl;

    return 0;
} // fin de main
