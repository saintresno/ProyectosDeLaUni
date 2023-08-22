#include <iostream>
#include <string>
using namespace std;

// Definición de la estructura del vehículo
struct vehiculo {
    string pl;
    string nombre_prop;
    char tipo_vehiculo;
    char color;
    vehiculo *sig;
};

// Prototipos de las funciones
void agregarVehiculo(vehiculo *&cab);
void mostrarVehiculos(vehiculo *cab);
void borrarVehiculo(vehiculo *&cab);

int main() {
    vehiculo *cab = NULL; // Inicialización de la lista vacía de vehículos
    int opcion;

    // Menú de opciones
    do {
        cout << "1. Agregar un vehiculo" << endl;
        cout << "2. Mostrar lista de vehiculos" << endl;
        cout << "3. Borrar un vehiculo" << endl;
        cout << "4. Salir" << endl;
        cout << "Digite una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1: // Agregar un vehículo
                agregarVehiculo(cab);
                break;
            case 2: // Mostrar lista de vehículos
                mostrarVehiculos(cab);
                break;
            case 3: // Borrar un vehículo
                borrarVehiculo(cab);
                break;
            case 4: // Salir
                break;
            default: // Opción no válida
                cout << "Opcion no valida. Por favor, intente de nuevo." << endl;
        }
    } while (opcion != 4);

    // Liberar la memoria ocupada por la lista de vehículos
    while (cab != NULL) {
        vehiculo *temp = cab;
        cab = cab->sig;
        delete temp;
    }

    return 0;
}

// Función para agregar un vehículo a la lista
void agregarVehiculo(vehiculo *&cab) {
    vehiculo *localizar = new vehiculo();
    localizar->sig = cab;
    cab = localizar;
    cout << "DATOS DEL VEHICULO" << endl << endl;
    cout << "Digite la placa del vehiculo: ";
    cin >> localizar->pl;
    cout << "Digite el nombre del propietario: ";
    cin.ignore(); // Ignorar cualquier carácter residual del buffer
    getline(cin, localizar->nombre_prop);
    cout << "Digite el tipo de vehiculo (t=taxi, c=colectivo, b=buseta, p=particular): ";
    cin >> localizar->tipo_vehiculo;
    cout << "Digite el color del vehiculo (n=negro, b=blanco, a=amarillo, r=rojo, z=azul): ";
    cin >> localizar->color;
    cout << "El vehiculo ha sido agregado exitosamente." << endl;
}

// Función para mostrar la lista de vehículos
void mostrarVehiculos(vehiculo *cab) {
    if (cab == NULL) {
        cout << "No hay vehiculos registrados." << endl;
        return;
    }

    cout << "LISTA DE VEHICULOS" << endl << endl;
    cout << "Placa\tNombre Propietario\tTipo\tColor" << endl;
    while (cab != NULL) {
        cout << cab->pl << "\t" << cab->nombre_prop << "\t\t" << cab->tipo_vehiculo << "\t\t";
        switch (cab->color) {
        case 'n':
            cout << "Negro" << endl;
            break;
        case 'b':
            cout << "Blanco" << endl;
            break;
        case 'a':
            cout << "Amarillo" << endl;
            break;
        case 'r':
            cout << "Rojo" << endl;
            break;
        case 'z':
            cout << "Azul" << endl;
            break;
        default:
            cout << "Desconocido" << endl;
    }

    cab = cab->sig;
}

// Función para borrar un vehículo de la lista
void borrarVehiculo(vehiculo *&cab){
	string placa;
	cout << "Digite la placa del vehiculo a borrar: ";
	cin >> placa;
	if (cab == NULL) {
		cout << "No hay vehiculos registrados." << endl;
	return;
	}
	if (cab->pl == placa) { // Borrar el primer elemento de la lista
    	vehiculo *temp = cab;
    	cab = cab->sig;
    	delete temp;
    	cout << "El vehiculo ha sido borrado exitosamente." << endl;
    	return;
	}

	vehiculo *actual = cab;
	while (actual->sig != NULL && actual->sig->pl != placa) {
    	actual = actual->sig;
	}

	if (actual->sig == NULL) { // La placa no se encontró en la lista
    	cout << "No se encontró ningun vehiculo con la placa " << placa << "." << endl;
	} else { // Borrar el vehículo encontrado en la lista
    	vehiculo *temp = actual->sig;
    	actual->sig = temp->sig;
   		delete temp;
    	cout << "El vehiculo ha sido borrado exitosamente." << endl;
	}
}


