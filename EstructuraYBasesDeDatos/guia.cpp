
#include <iostream>
#include <algorithm>
using namespace std;

// Definimos la estructura del nodo del árbol
struct Nodo {
    int valor;
    Nodo *izquierda, *derecha;
};

// Función que crea un nuevo nodo y lo inicializa
Nodo* crearNodo(int valor) {
    Nodo* nodo = new Nodo();
    nodo->valor = valor;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

// Función que inserta un nodo en el árbol
Nodo* insertarNodo(Nodo* raiz, int valor) {
    if (raiz == NULL) {
        return crearNodo(valor);
    } else if (valor < raiz->valor) {
        raiz->izquierda = insertarNodo(raiz->izquierda, valor);
    } else if (valor > raiz->valor) {
        raiz->derecha = insertarNodo(raiz->derecha, valor);
    }
    return raiz;
}

// Función que imprime el árbol en orden (inorden)
void imprimirInorden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirInorden(raiz->izquierda);
        cout << raiz->valor << " ";
        imprimirInorden(raiz->derecha);
    }
}

// Función que imprime el árbol en preorden
void imprimirPreorden(Nodo* raiz) {
    if (raiz != NULL) {
        cout << raiz->valor << " ";
        imprimirPreorden(raiz->izquierda);
        imprimirPreorden(raiz->derecha);
    }
}

// Función que imprime el árbol en postorden
void imprimirPostorden(Nodo* raiz) {
    if (raiz != NULL) {
        imprimirPostorden(raiz->izquierda);
        imprimirPostorden(raiz->derecha);
        cout << raiz->valor << " ";
    }
}

// Función que muestra el árbol completo
void mostrarArbol(Nodo* raiz, int profundidad) {
    if (raiz != NULL) {
        mostrarArbol(raiz->derecha, profundidad+1);
        for (int i = 0; i < profundidad; i++) {
            cout << "  ";
        }
        cout << raiz->valor << endl;
        mostrarArbol(raiz->izquierda, profundidad+1);
    }
}

// Función que calcula la altura del árbol
int alturaArbol(Nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return 1 + max(alturaArbol(raiz->izquierda), alturaArbol(raiz->derecha));
    }
}

// Función que cuenta los nodos padre en el árbol
int contarNodosPadre(Nodo* raiz) {
    if (raiz == NULL || (raiz->izquierda == NULL && raiz->derecha == NULL)) {
        return 0;
    } else {
        return 1 + contarNodosPadre(raiz->izquierda) + contarNodosPadre(raiz->derecha);
    }
}

// Función que cuenta los nodos hijo en el árbol
int contarNodosHijo(Nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    } else {
        return contarNodosHijo(raiz->izquierda) + contarNodosHijo(raiz->derecha) + (raiz->izquierda != NULL) + (raiz->derecha != NULL);
    }
}

// Función que cuenta los nodos hoja en el árbol
int contarNodosHoja(Nodo* raiz) {
    if (raiz == NULL) {
        return 0;
    } else if (raiz->izquierda == NULL && raiz->derecha == NULL) {
        return 1;
    } else {
        return contarNodosHoja(raiz->izquierda) + contarNodosHoja(raiz->derecha);
    }
}


// Función que muestra el menú de opciones
void mostrarMenu() {
    cout << "\n*************** MENU DE OPCIONES ***************\n";
    cout << "1. Agregar un elemento al arbol\n";
    cout << "2. Imprimir el arbol en orden (inorden)\n";
    cout << "3. Imprimir el arbol en preorden\n";
    cout << "4. Imprimir el arbol en postorden\n";
    cout << "5. Mostrar el arbol\n";
    cout << "6. Calcular la altura del arbol\n";
    cout << "7. Calcula la raiz del arbol\n";
    cout << "8. Contar los nodos padre del arbol\n";
    cout << "9. Contar los nodos hijo del arbol\n";
    cout << "10. Contar los nodos hoja del arbol\n";
    cout << "11. Salir\n";
    cout << "Ingrese una opcion: ";
}

// Función principal
int main() {
    Nodo* raiz = NULL; // Creamos un árbol vacío
    int opcion, valor;
    do {
        mostrarMenu();
        cin >> opcion;
        switch(opcion) {
            case 1:
                cout << "Ingrese el valor del elemento a agregar: ";
                cin >> valor;
                raiz = insertarNodo(raiz, valor);
                break;
            case 2:
                cout << "El árbol en orden (inorden) es: ";
                imprimirInorden(raiz);
                cout << endl;
                break;
            case 3:
                cout << "El árbol en preorden es: ";
                imprimirPreorden(raiz);
                cout << endl;
                break;
            case 4:
                cout << "El árbol en postorden es: ";
                imprimirPostorden(raiz);
                cout << endl;
                break;
            case 5:
                cout << "Árbol completo:\n";
                mostrarArbol(raiz, 0);
                break;
            case 6:
				cout << "La altura del arbol es: " << alturaArbol(raiz) << endl;
				break;
            case 7:
                if (raiz != NULL) {
                    cout << "El nodo raiz del arbol es: " << raiz->valor << endl;
                } else {
                    cout << "El arbol está vacío\n";
                }
                break;
            case 8:
                cout << "El numero de nodos padre en el arbol es: " << contarNodosPadre(raiz) << endl;
                break;               
            case 9:
                cout << "El numero de nodos hijo en el arbol es: " << contarNodosHijo(raiz) << endl;
                break;
            case 10:
                cout << "El numero de nodos hijo en el arbol es: " << contarNodosHijo(raiz) << endl;
                break;
            case 11:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción invalida\n";
        }
    } while(opcion != 11);

    return 0; 
}