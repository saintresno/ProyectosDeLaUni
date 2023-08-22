#include <iostream>
using namespace std;

// Definición de la estructura para la matriz
struct matriz {
  int fibonacci[4];
  int factorial[4];
  double maxdist[4];
  double fuerza[4];
  int fib_sum;
  int fact_sum;
  double maxdist_sum;
  double fuerza_sum;
};

int main() {
  // Creación de una instancia de la estructura
  matriz m;

  // Inicialización de la matriz con algunos valores
  m.fibonacci[0] = 0;
  m.fibonacci[1] = 1;
  m.fibonacci[2] = 1;
  m.fibonacci[3] = 2;

  m.factorial[0] = 1;
  m.factorial[1] = 1;
  m.factorial[2] = 2;
  m.factorial[3] = 6;

  m.maxdist[0] = 2.5;
  m.maxdist[1] = 3.0;
  m.maxdist[2] = 4.2;
  m.maxdist[3] = 5.1;

  m.fuerza[0] = 10.2;
  m.fuerza[1] = 15.7;
  m.fuerza[2] = 22.1;
  m.fuerza[3] = 30.0;

  // Cálculo de los acumuladores
  m.fib_sum = 0;
  m.fact_sum = 0;
  m.maxdist_sum = 0;
  m.fuerza_sum = 0;

  for (int i = 0; i < 4; i++) {
    m.fib_sum += m.fibonacci[i];
    m.fact_sum += m.factorial[i];
    m.maxdist_sum += m.maxdist[i];
    m.fuerza_sum += m.fuerza[i];
  }

  // Impresión de los acumuladores
  cout << "Suma de la fila fibonacci: " << m.fib_sum << endl;
  cout << "Suma de la fila factorial: " << m.fact_sum << endl;
  cout << "Suma de la fila maxdist: " << m.maxdist_sum << endl;
  cout << "Suma de la fila fuerza: " << m.fuerza_sum << endl;

  return 0;
}

