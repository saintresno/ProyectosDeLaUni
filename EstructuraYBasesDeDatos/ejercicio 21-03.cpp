#include <iostream>
#include <stdio.h>
#include <conio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#define localizar (struct nodo * ) malloc (sizeof (struct nodo))

using namespace std;

struct nodo {
	char pl[6];
	char nombre_prop[31];
	int di;
	char tipo_vehiculo;
	char color;
	struct nodo *sig;
};

struct nodo *cab, *q;
int temp=1;
typedef nodo *Lista;
typedef nodo *pNodo, *sig;

void crear_vehiculos(struct nodo *q);
void listar_vehiculos(struct nodo *q);

int listavacia(Lista lista){
	return (lista == NULL);
}

/*
METODO CREAR VEHICULOS: crea un nuevo veh�culo.
Obtiene los datos a almacenar en la lista de veh�culos teniendo en cuenta la estrcutura.
Nomnbre par�metro 		tipo 			tipo de dato 			breve descripci�n
q* 						Referencia		Estrcutura				Es donde se encuentran almacenados los datos de los veh�culos.
pl						Referencia		char					Es donde se encuentra almacenada el valor de la placa del vehiculo q.
nombre_prop				Referencia		char 					Es donde se encuentra almacenada el valor del nombre del due�o del vehiculo q.
di 						Referencia 		int 					Es donde se encuentra almacenado el valor del documento de identidad del due�o del vehiculo q.
tipo_vehiculo			Referencia 		char					Es donde se encuentra almacenado el valor para definir el tipo de vehiculo que es q.
color					Referencia 		char 					Es donde se encuentra almacenado el valor para definir el color del vehiculo q.
Precondici�n: Estructura lineal con o sin datos.
Postcondici�n: a�ade datos a la lista.
m�todos que lo invocan: main.
compilador utilizado: Dev c++ 5.5.3
versi�n del c�digo 1.0
creador: Santiago Steven Reyes Naranjo
fecha de creaci�n: 24/03/2023
*/

void crear_vehiculos(struct nodo *q)
{
	q=localizar;
	q->sig=cab;
	cab=q;
	cout << endl << endl;
	cout << "		DATOS DEL VEHICULO" << endl << endl;
	cout << endl << endl;
	cout << "1. Digite la placa del vehiculo: "<< endl;
	cin >> q->pl;
	cout << "2. Digite el nombre del propietario: " << endl;
	cin.getline(q->nombre_prop,31);
	cout << "3. Digite la cedula del propietario: " << endl;
	cin >> q->di;
	cout << "4. Digite el tipo de vehiculo t=taxi c=colectivo b=buseta p=particular: " << endl;
	cin >> q->tipo_vehiculo;
	cout << "5. Digite el color del vehiculo n=negro b=blanco a=amarillo r=rojo z=azul: " << endl;
	cin >> q->color;
}

/*
METODO LISTAR VEHICULOS: mostrar la lista de veh�culos.
Imprime la lista completa de todos los vehiculos almacenados.
Nomnbre par�metro 		tipo 			tipo de dato 			breve descripci�n
q* 						Referencia		Estrcutura				Es donde se encuentran almacenados los datos de los veh�culos.
pl						Referencia		char					Es donde se encuentra almacenada el valor de la placa del vehiculo q.
nombre_prop				Referencia		char 					Es donde se encuentra almacenada el valor del nombre del due�o del vehiculo q.
di 						Referencia 		int 					Es donde se encuentra almacenado el valor del documento de identidad del due�o del vehiculo q.
tipo_vehiculo			Referencia 		char					Es donde se encuentra almacenado el valor para definir el tipo de vehiculo que es q.
color					Referencia 		char 					Es donde se encuentra almacenado el valor para definir el color del vehiculo q.
Precondici�n: Estructura lineal con o sin datos.
Postcondici�n: Si encuentra dato, lo imprime.
m�todos que lo invocan: main 
compilador utilizado: Dev c++ 5.5.3
versi�n del c�digo 1.0
creador: Santiago Steven Reyes Naranjo
fecha de creaci�n: 24/03/2023
*/

void listar_vehiculos (struct nodo *q)
{
		cout << " IMPRESION DE DATOS VEHICULOS" << endl << endl;
		while (q!=NULL )
		{
				cout << "Placa del vehiculo		: " << q->pl<<endl;
				cout << "Nombre del propietario : " << q->nombre_prop<< endl;
				cout << "Documento del propietario		: " << q->di<< endl;
				cout << "Tipo de vehiculo		: " << q->tipo_vehiculo<< endl;
				cout << "Color del vehiculo		: " << q->color<< endl;
				q=q->sig;
		};
};


/*

METODO  VEHICULOS: mostrar la lista de veh�culos.
Imprime la lista completa de todos los vehiculos almacenados.
Nomnbre par�metro 		tipo 			tipo de dato 			breve descripci�n
di 						Referencia 		int 					Es donde se encuentra almacenado el valor del documento de identidad del due�o del v
Precondici�n: Estructura lineal con o sin datos.
Postcondici�n: Si encuentra dato, lo imprime.
m�todos que lo invocan: main 
compilador utilizado: Dev c++ 5.5.3
versi�n del c�digo 1.0
creador: Santiago Steven Reyes Naranjo
fecha de creaci�n: 27/03/2023
*/



void Borrar(Lista *lista, int v) {
	pNodo anterior,nodoa;
	
	nodoa= *lista;
	anterior = NULL;
	
	if(listavacia(*lista) ){
		cout<<" la lista se encuentra sin informacion ";}
	else
	{
	cout<<"Iniciando proceso --- Documento del propietario :"<< nodoa ->di<<endl;
	while(nodoa->di != v || nodoa ->sig !=NULL) {
		anterior = nodoa;
		nodoa = nodoa->sig;
		cout<<"entro 3";
		 cout<<"Documento del propietario :"<< nodoa->di<<endl;
	}
	if(!nodoa || nodoa->di != v)
	return;
	else {
		if(!anterior)
		{
			*lista = nodoa->sig;
			cout<<"entro 1";
			cout<<"Documento del propietario: "<< nodoa->di<<endl;
		}
		else 
		{
			
			anterior->sig = nodoa->sig;
			cout<<"entro 2";
			cout<<"Docuemnto del propietario :"<<q->di<<endl;
		}
		free(nodoa);
	}
	}
	}
	
/*
METODO MENU: opciones de funcionalidad
Imprime la lista de opciones para informarle al usuario las diferentes funcionalidades y con qu� opcion acceder a ellas.
Precondici�n: N/A.
Postcondici�n: N/A.
m�todos que lo invocan: main 
compilador utilizado: Dev c++ 5.5.3
versi�n del c�digo 1.0
creador: Santiago Steven Reyes Naranjo
fecha de creaci�n: 24/03/2023
*/

void menu()
{
	cout << "\n\t MENU VEHICULOS \n\n"; 
	cout << "1. CREAR VEHICULOS						"<<endl;
	cout << "2. LISTAR VEHICULOS 					"<<endl;
	cout << "3. BORRAR VEHICULO						"<<endl;
	cout << "4. SALIR								"<<endl;
	cout << "INGRESE OPCION: ";    
};

/*
METODO MAIN
Nomnbre par�metro 		tipo 			tipo de dato 			breve descripci�n
op						dato			int						Almacena el valor para acceder a las diferentes funcionalidades.
Precondici�n: Estructura lineal con o sin datos.
Postcondici�n: N/A.
m�todos que lo invocan: N/A.
m�todos que invoca: crear_vehiculo || listar_vehiculos || buscar || menu 
compilador utilizado: Dev c++ 5.5.3
versi�n del c�digo 1.0
creador: Santiago Steven Reyes Naranjo
fecha de creaci�n: 24/03/2023*/

int main()
{
	void crear_vehiculos(struct nodo *q);
	void listar_vehiculos(struct nodo *q);
	void buscar(struct nodo *q);
	void menu();
	
	int op;
	do
	{
		menu();
		cin >> op;
		switch(op)
		{
				case 1:
					system("cls");
					cout << "CREAR VEHICULOS: ";
					crear_vehiculos(cab);
					cout << "\n\n\t\t Vehiculo creado... \n\n";
					break;
				case 2:
					system("cls");
					cout << "\n LISTAR VEHICULOS";
					listar_vehiculos(cab);
					cout <<endl <<endl;
					break;
				case 3:
					system("cls");
					cout << "\n BORRAR VEHICULOS";
					Borrar(cab);
					cout <<endl <<endl;
					break;
				case 4:
					system("cls");
					cout << "\n SALIR";
					exit(0);
					cout << endl<<endl;
					break;
		}
		cout << endl<<endl;
		system("pause");
		} while(op!=4);
		return 0;
}
