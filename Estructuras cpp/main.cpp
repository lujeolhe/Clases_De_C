#include <iostream>
#include "./headers/Pila.hpp"
using namespace ESTRUCTURAS;

void funcEjemplo();

int main(int argc, char const *argv[]) {
  funcEjemplo();
  return 0;
}

void funcEjemplo() {
  Pila p(20);
  std::cout << "El tamnio de la Pila es: " <<p.getTamanio()<<'\n';
}
