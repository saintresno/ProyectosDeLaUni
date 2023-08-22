#include <iostream>
#include<math.h>
#define PI 3.14159265

using namespace std;


struct estructura
{
	double fibonacci;
	double factorial;
	double distHTiro;
	double fuerza;
};

int main(int argc, char** argv)
{
    int posicion,cantColum;
    double ang, velI, g, acel, masa;
    g = 9.81;
    cout << "digite la cantidad de columnas que desea para la matriz (debe ser mayor a 3 ) \n";
    cin >> cantColum;
    while (cantColum<=3 ){
	    cout << "error, el numero de columnas debe ser mayor a 3 \n";
	    cin >> cantColum;
    }
    
    estructura acumulador;
	estructura proyecto[cantColum];
	int columna[cantColum];
	
	acumulador.fibonacci = 0;
	acumulador.factorial = 0;
	acumulador.distHTiro = 0;
	acumulador.fuerza = 0;
	
	
    proyecto[0].fibonacci = 0;
    proyecto[1].fibonacci = 1;
    proyecto[0].factorial = 1;
    for(posicion=0;posicion<cantColum;posicion++){
    	if(posicion>1){
    		proyecto[posicion].fibonacci = proyecto[posicion-1].fibonacci + proyecto[posicion-2].fibonacci;
    		cout << "el valor del ciclo fibonacci en la posicion "<< posicion << "es igual a : " << proyecto[posicion].fibonacci << "\n";
    	}
    }
	for (posicion=0;posicion<cantColum;posicion++){
    	if(posicion>0){
    		proyecto[posicion].factorial = posicion * proyecto[posicion-1].factorial;
    		cout << "el valor del ciclo factorial en la posicion " << posicion << "es igual a : " << proyecto[posicion].factorial << "\n";
    	}
	}
	for (posicion=0;posicion<cantColum;posicion++){
		cout << "Digite el valor del angulo (en grados) en que se realizo el disparo \n" ;
		cin >> ang;
	    while (90<ang || ang<1){
		    cout << "El valor del angulo tiene que estar entre 1 y 90 grados \n";
		    cin >> ang;
	    }
		cout << "Digite el valor de la velocidad inicial \n" ;
		cin >> velI;
	    while (1>velI){
		    cout << "El valor de la velocidad inicial tiene que ser superior a 0. \n";
		    cin >> velI;
	    }
		proyecto[posicion].distHTiro = ((pow(velI, 2)*sin(ang/180*PI))/g);
		cout << "el valor de la distancia en el tiro # " << posicion << " es: " << proyecto[posicion].distHTiro << "\n";
	}
	for (posicion=0;posicion<cantColum;posicion++){
		cout << "Digite el valor de la masa en kilogramos \n" ;
		cin >> masa;
	    while (masa<1){
		    cout << "El valor de la masa debe ser mayor a 0 \n";
		    cin >> masa;
	    }
		cout << "Digite el valor de la aceleracion \n" ;
		cin >> acel;
	    while (acel<1){
		    cout << "El valor de la aceleracion debe ser mayor a 0 \n";
		    cin >> acel;
	    }
		proyecto[posicion].fuerza = masa * acel;
		cout << "el valor de la fuerza en newtons de la posicion # " << posicion << " es igual a : " << proyecto[posicion].fuerza << "\n";
	}
	for (posicion=0;posicion<cantColum;posicion++){
		acumulador.fibonacci = acumulador.fibonacci + proyecto[posicion].fibonacci;
		acumulador.factorial = acumulador.factorial + proyecto[posicion].factorial;
		acumulador.distHTiro = acumulador.distHTiro + proyecto[posicion].distHTiro;
		acumulador.fuerza = acumulador.fuerza + proyecto[posicion].fuerza;
	}
	
	for (posicion=0;posicion<cantColum;posicion++){
		cout << " [" << proyecto[posicion].fibonacci << "] ";
}
cout << "\n";
	for (posicion=0;posicion<cantColum;posicion++){
		cout << " [" << proyecto[posicion].factorial << "] ";
	}
cout << "\n";
	for (posicion=0;posicion<cantColum;posicion++){
		cout << " [" << proyecto[posicion].distHTiro << "] ";
	}
cout << "\n";
	for (posicion=0;posicion<cantColum;posicion++){
		cout << " [" << proyecto[posicion].fuerza << "] ";
	}
cout << "\n";
cout <<"La sumatoria de la fila fibonacci es igual a :" << acumulador.fibonacci <<  " \n";
cout <<"La sumatoria de la fila factorial es igual a : " << acumulador.factorial << " \n";
cout <<"La sumatoria de la fila distancia horizontal de tiro parabolico es igual a : " << acumulador.distHTiro << "\n";
cout <<"La sumatoria de la fila fuerza es igual a : " << acumulador.fuerza << "\n";
	
return 0;
}
