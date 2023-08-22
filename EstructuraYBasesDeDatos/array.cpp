/*
Santiago Steven Reyes Naranjo
Ingeniería electrónica 
Dev-C++ 6.3
Programa organización de números en una lista con métodos de añadir y borrar por valor y posición.
*/

#include <iostream>
#include <algorithm>
using namespace std;

int array[9];
int size;


ArrayOrdenado() {
    size = 0;
}

void insertar(int elemento) {
    // Si el arreglo está lleno, no se puede insertar más elementos
    if (size >= 9) {
        cout << "El arreglo esta lleno. No se puede insertar mas elementos." << std::endl;
        return;
    }

    array[size] = elemento;
    size++;

    sort(array, array + size, greater<int>());
};

void borrarPorValor(int valor) {
    for (int i = 0; i < size; i++) {
        if (array[i] == valor) {
            // Desplazar los elementos restantes una posición hacia atrás
            for (int j = i; j < size - 1; j++) {
                array[j] = array[j + 1];
            }
            size--;
            i--;
        }
    }
};

void borrarPorUbicacion(int indice) {
    if (indice >= 0 && indice < size) {
        // Desplazar los elementos restantes una posición hacia atrás
        for (int i = indice; i < size - 1; i++) {
            array[i] = array[i + 1];
        }
        size--;
    }
    else{
    	cout << "La lista aun no tiene esa cantidad de posiciones";
	}
};

void mostrar() {
    cout << "Elementos del arreglo: ";
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
};
                 
int main() {
    int opcion;

    while (true) {
    	system("cls");
        cout << "===== MENÚ =====" << std::endl;
        cout << "[1].................Insertar elemento" << std::endl;
        cout << "[2].................Borrar por valor" << std::endl;
        cout << "[3].................Borrar por ubicacion" << std::endl;
        cout << "[4].................Mostrar arreglo" << std::endl;
        cout << "[5].................Salir" << std::endl;
        cout << "Ingrese la opción deseada: ";
        cin >> opcion;

        switch (opcion) {
            case 1: {
                int elemento;
                cout << "Ingrese el elemento a insertar: ";
                cin >> elemento;
                insertar(elemento);
                cout << "Elemento insertado correctamente." << endl;
                break;
            }
            case 2: {
                int valor;
                cout << "Ingrese el valor a borrar: ";
                cin >> valor;
                borrarPorValor(valor);
                cout << "Elemento(s) borrado(s) correctamente." << endl;
                break;
            }
            case 3: {
                int ubicacion;
                cout << "Ingrese la ubicacion a borrar: ";
                cin >> ubicacion;
                borrarPorUbicacion(ubicacion);
                cout << "Elemento borrado correctamente." << endl;
                break;
            }
            case 4:
                mostrar();
                break;
            case 5:
                cout << "Saliendo del programa..." << endl;
                return 0;
            default:
                cout << "Opción invalida. Intente nuevamente." << endl;
                break;
        }
        system("pause");
        cout << endl;
    }
}
