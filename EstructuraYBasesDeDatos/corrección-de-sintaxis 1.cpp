
#include <iostream>

using namespace std;

int main()
{
    int posicion,fila;
    int matriz[3][3] = 
       {
           {200,150,100},
           {-50,300,2},
           {66,88,-9}
       };
    int vector1[3];
    for(posicion=0;posicion<3;posicion++)
        {
            vector1[posicion]=0;
            cout << "el valor del vector es = " << vector1[posicion];
        }
    for (fila=0;fila<3;fila++)
    {
        for(posicion=0;posicion<3;posicion++)
            {
                vector1[posicion] = vector1[posicion]+matriz[fila][posicion];
                cout << "el valor en posicion : " << posicion << " su contenido es : " << vector1[posicion] << "\n \t ";
            };
    }
    return 0;
}