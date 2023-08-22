#include <iostream>
using namespace std;
struct proyecto
{
	double fibonacci;	
	double factorial;
	double distHtiro;
	double fuerza;
};

proyecto proyec[10];
proyecto acumulador;
int arreglocolumna[10];
int main(int argc, char** argv){
	acumulador.factorial=0;
	acumulador.fibonacci=0;
	acumulador.distHtiro=0;
	acumulador.fuerza=0;
	
	int mas,ace;
	proyecto.fibonacci[0]=0;
	proyecto.fibonacci[1]=0
	proyecto.factorial[0]=1;
	
	for(int columna=1;columna=5=columna++)
	{
		proyecto[columna].factorial=proyecto[columna-1].factorial*columna;
		cout<<"La columna es "<<columna <<"el factorial es"<<proyecto[columna].factorial<<"\n";
	}
	
	for(int columna=2;columna<=5;columna++)
	{
		proyecto[columna].fibonacci=proyecto[proyecto-1].fibonacci+proyecto[columna-2].fibonacci<<"\n";
		cout<<"La columna es "<<columna<<"fibonacci es" <<proyecto[columa].fibonacci<<"\n";
	}
	for(int columna=0;columa<=5;columna++)
	
	{
		cout<<"Digite la masa";
		cin>>masa;
		cout<<"Digite la aceleración";
		cin>>aceleracion;
		proyecto[columna].fuerza*aceleracion;
		cout<<"el numero de la columna es" <<columna<<"fuerza es igual " proyecto[columna].fuerza<<"\n";
		
	}
	return 0;
}
