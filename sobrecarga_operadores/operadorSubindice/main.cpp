#include <iostream>
#include <vector>
#include <algorithm>
#define SIZE 5
using namespace std;


class colection{

    private:
        vector<int> vct;

    public:
        
        colection(){};
        ~colection(){};
        
        void agregar_elem (int elem){
            vct.push_back(elem);
        } 

        colection& operator[]( colection& cl ){

            if ( cl.vct.size() != 0 ){

                int max_ele = *max_element( cl.vct.begin() , cl.vct.end());
                cout << "mayor elemento en la coleccion : " << max_ele << endl;
                
                vector<int>:: iterator it = find ( cl.vct.begin() , cl.vct.end() , max_ele  );; 
                cl.vct.erase(it);

            }

            return *this;
        };

};


int main(int argc, char const *argv[])
{
    
    colection cl;
    cl.agregar_elem(5);
    cl.agregar_elem(2);
    cl.agregar_elem(1);
    cl.agregar_elem(15);

    cl[cl];
    cl[cl];
    cl[cl];
    cl[cl];
    cl[cl];


    return 0;
}




