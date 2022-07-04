#include <iostream>
#include <string>
using namespace std;


string operator+( string& a, string& b){

    string c = a.append(b);
    return c;
};


int main(int argc, char const *argv[])
{

    string a = "hola";
    string b = " mundo";
    string c = a + b;
    cout << c <<endl;


    return 0;
}

