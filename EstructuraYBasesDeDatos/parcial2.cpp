/*Métodos usados:
main
unirABB
crearNodo
insertar
preOrden
enOrden
postOrden
verArbol
elimina
alturaAB
contNodosP
contarNodos
contarHojas
menu
Compilador usado : c++ 6.3
Creador: Santiago Steven Reyes
Fecha de creación 29\04\2023
*/
#include <iostream>
#include <stdlib.h>

using namespace std;

/*---------  Estructura del arbol  -------*/
typedef struct nodo{
     int nro;
     struct nodo *izq, *der;
}*ABB;

int numNodos = 0; // nummero de nodos del arbol ABB
int numK = 0, k;     //  nodos menores que un numero k ingresado


/* ---------- Estructura de la cola ---------*/
struct nodoCola{
    ABB ptr;
    struct nodoCola *sgte;
};
ABB unirABB(ABB izq, ABB der)
{
    if(izq==NULL) return der;
    if(der==NULL) return izq;

    ABB centro = unirABB(izq->der, der->izq);
    izq->der = centro;
    der->izq = izq;
    return der;
}
/*Crear nodo (método)
Descripción: reserva memoria para la creación de un nodo y ingresa el valor de x
Parámetros: x - valor, nuevoNodo - apuntador
Variables locales:
Nombre: int x
Precondición:
Postcondición:*/
ABB crearNodo(int x)
{
     ABB nuevoNodo = new(struct nodo);
     nuevoNodo->nro = x;
     nuevoNodo->izq = NULL;
     nuevoNodo->der = NULL;

     return nuevoNodo;
}

/*insertar (método)
Descripción: Añade el nodo creado en CrearNodo() a arbol con su valor respectivo
Parámetros:arbol - struct apuntador
Variables locales: int x - 
Nombre: int x
Precondición:
Postcondición:*/
void insertar(ABB &arbol, int x)
{
     if(arbol==NULL)
     {
           arbol = crearNodo(x);
           cout<<"\n\t  Insertado..!"<<endl<<endl;
     }
     else if(x < arbol->nro)
          insertar(arbol->izq, x);
     else if(x > arbol->nro)
          insertar(arbol->der, x);
}

/*preOrden (método)
Descripción: recorre el arbol e creado anteriormente y retorna sus valores en preOrden
Parámetros:arbol - struct 
Variables locales:
Nombre:
Precondición: estructura de arbol creada para poder ser ordenada 
Postcondición:*/
void preOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          cout << arbol->nro <<" ";
          preOrden(arbol->izq);
          preOrden(arbol->der);
     }
}

/*enOrden (método)
Descripción: recorre el arbol e creado anteriormente y retorna sus valores en enOrden
Parámetros:arbol - struct 
Variables locales:
Nombre:
Precondición: estructura de arbol creada para poder ser ordenada 
Postcondición:*/
void enOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          cout << arbol->nro << " ";
          enOrden(arbol->der);
     }
}

/*postOrden (método)
Descripción: recorre el arbol e creado anteriormente y retorna sus valores en postOrden
Parámetros:arbol - struct 
Variables locales:
Nombre:
Precondición: estructura de arbol creada para poder ser ordenada 
Postcondición:*/
void postOrden(ABB arbol)
{
     if(arbol!=NULL)
     {
          enOrden(arbol->izq);
          enOrden(arbol->der);
          cout << arbol->nro << " ";
     }
}


/*verArbol (método)
Descripción: recorre el arbol y retorna su estructura imprimiéndo el árbol de izquierda a derecha de manera horizontal
Parámetros:arbol - struct 
Variables locales: int n
Nombre: n
Precondición: estructura de arbol creada para poder ser ordenada 
Postcondición:*/
void verArbol(ABB arbol, int n)
{
     if(arbol==NULL)
          return;
     verArbol(arbol->der, n+1);

     for(int i=0; i<n; i++)
         cout<<"   ";

     numNodos++;
     cout<< arbol->nro <<endl;

     verArbol(arbol->izq, n+1);
}

/*elimina (método)
Descripción: busca el valor obtenido dentro del arbol, si es encontrado lo elimina del arbol y reorganiza la estructura 
Parámetros:arbol - struct 
Variables locales: int x
Nombre: x
Precondición: estructura de arbol creada para poder buscar sus valores y comparar
Postcondición:*/
void elimina(ABB &arbol, int x)
{
     if(arbol==NULL) return;

     if(x<arbol->nro)
         elimina(arbol->izq, x);
     else if(x>arbol->nro)
         elimina(arbol->der, x);

     else
     {
         ABB p = arbol;
         arbol = unirABB(arbol->izq, arbol->der);
         delete p;
     }
}

/*alturaAB (método)
Descripción: recorre el arbol y analiza cuantos saltos hace para verificar la altura del arbol 
Parámetros:arbol - struct 
Variables locales:
Nombre: 
Precondición: estructura de arbol creada para poderrecorrer y contar su altura dependiendo de sus pisos
Postcondición:*/
int alturaAB(ABB arbol)
{
    int AltIzq, AltDer;

    if(arbol==NULL)
        return -1;
    else
    {
        AltIzq = alturaAB(arbol->izq);
        AltDer = alturaAB(arbol->der);

        if(AltIzq>AltDer)
            return AltIzq+1;
        else
            return AltDer+1;
    }
}


/*contNodosP (método)
Descripción: recorre el arbol y verifica que nodos tienen hijos para 
determinar quien es padre y aumenta el contador para llevar el conteo de cuantos padres hay
Parámetros:arbol - struct 
Variables locales:
Nombre: 
Precondición: estructura de arbol creada para poder recorrer y contar los nodos padre
Postcondición:*/
int contNodosP(ABB arbol) {
    if (arbol == NULL || (arbol->izq == NULL && arbol->der == NULL)) {
        return 0;
    } else {
        return 1 + contNodosP(arbol->izq) + contNodosP(arbol->der);
    }
}


/*contarNodos (método)
Descripción: recorre el arbol y cuenta la cantidad de nodos que contiene 
Parámetros:arbol - struct 
Variables locales:
Nombre: 
Precondición: estructura de arbol creada para poder recorrer y contar la totalidad de nodos
Postcondición:*/
int contarNodos(ABB arbol)
{
	if (arbol==NULL){
		return 0;
	}
	else{
		return 1 + contarNodos(arbol->izq) + contarNodos(arbol->der);
	}
}


/*contarHojas (método)
Descripción: recorre el arbol y cuenta la cantidad de nodos que se encuentran en los extremos del arbol para determinar
si son hojas 
Parámetros:arbol - struct 
Variables locales:
Nombre: 
Precondición: estructura de arbol creada para poder recorrer y contar la totalidad de nodos tipo hoja
Postcondición:*/
int contarHojas(ABB arbol)
{
        if (arbol==NULL)
        {
                return 0;
        }
        if ((arbol->der ==NULL)&&(arbol->izq ==NULL))
        {
                return 1;
        }
        else
        {
                return contarHojas(arbol->izq) + contarHojas(arbol->der);
        }
}


/*menu (método)
Descripción: imprime las diferentes opciones que tiene el programa para guiar al usuario
Parámetros:
Variables locales:
Nombre: 
Precondición:
Postcondición:*/
void menu()
{
     //system("cls");
     cout << "\n\t\t  ..[ ARBOL BINARIO DE BUSQUEDA ]..  \n\n";
     cout << "\t [1]  Insertar elemento                  \n";
     cout << "\t [2]  Mostrar arbol                      \n";
     cout << "\t [3]  Recorrido en InOrden               \n";
     cout << "\t [4]  Recorrido en PreOrden              \n";
     cout << "\t [5]  Recorrido en PostOrden             \n";
     cout << "\t [6]  Altura del arbol                   \n";
     cout << "\t [7]  Eliminar elemento                  \n";
     cout << "\t [8]  Contar nodos                       \n";
     cout << "\t [9]  Contar hojas                       \n";
     cout << "\t [10] Contar nodos padre                 \n";
     cout << "\t [11] SALIR                              \n";

     cout << "\n\t Ingrese opcion : ";
}

int main()
{
    ABB arbol = NULL;
    int x;
    int op;


    //system("color f9");   // poner color a la consola
    do
    {
          menu();  cin>> op;
          cout << endl;

          switch(op)
          {
               case 1:
                    cout << " Ingrese valor : ";  cin>> x;
                    insertar( arbol, x);
                    break;

               case 2:
                    verArbol(arbol, 0);
                    break;

               case 3:
                    if(arbol!=NULL)
                    {
                        enOrden(arbol); break;
                    }
                    else
                        cout << "\n\t Arbol vacio..!";
                    break;

               case 4:
            		if(arbol!=NULL)
                    {
						preOrden(arbol); break;
					}
                    else
                        cout << "\n\t Arbol vacio..!";
                    break;              	

               case 5:
                    if(arbol!=NULL)
                    {
                     postOrden(arbol); break;                   	
					}
                    else
                        cout << "\n\t Arbol vacio..!";
                    break;
               case 6:
                    int h;
                    h = alturaAB(arbol);
                    cout << " La altura es : "<< h << endl;
                    break;

               case 7:
			   		cout<<" Valor a eliminar: "; cin>> x;
                    elimina(arbol, x);
                    cout << "\n\tEliminado..!";
                    break;

               case 8:
               		if(arbol!=NULL){
               			int n;
               			n = contarNodos(arbol);
               			cout << "La cantidad de nodos en el arbol es igual a " << n << endl;
					   }
					else{
                        cout << "\n\t Arbol vacio..!";
					}
                    break;

               case 9:
                    if(arbol!=NULL)
                    {
                    	int h;
                    	h = contarHojas(arbol);	
                    	cout << "La cantidad de hojas en el arbol es: " << h << endl;
                    }
					else{
                        cout << "\n\t Arbol vacio..!";
					}
                    break;
                case 10:
                	if (arbol!=NULL){
                		int n = contNodosP(arbol);
                		cout << "La cantidad de nodos padre en el arbol es de: " << n << endl;
					}
					else{
                        cout << "\n\t Arbol vacio..!";
					}
                    break;
               case 11:
                    exit(0);
          }

          cout<<"\n\n\n";
          //system("pause");  // hacer pausa y presionar una tecla para continuar
    }while(op!=11);

}