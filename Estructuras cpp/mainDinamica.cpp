#include <iostream>
#include "./headers/PilaDinamica.hpp"
using namespace ESTRUCTURAS;

void funcEjemplo();

int main(int argc, char const *argv[]) {
  funcEjemplo();
  return 0;
}

void funcEjemplo() {
  PilaDinamica p(20);
  std::cout << "El tamnio de la Pila es: " <<p.getIndex()<<'\n';
  p.push(1);
  cout<<"La pila p: "<<&p;
  p.push(2);
  cout<<"La pila p: "<<&p;
  p.push(3);
  cout<<"La pila p: "<<&p;
  p.pop();
  cout<<"La pila despues p: "<<&p;
  cout<<endl;
  /*PilaDinamica a;
  std::cout << "El tamnio de la Pila es: " <<a.getTamanio()<<'\n';
  a.push(4);
  a.push(5);
  a.push(6);
  cout<<"La pila a: "<<&a;
  a.pop();
  cout<<"La pila despuesa: "<<&a;
  cout<<endl;*/
}

//Nodo privado atributos
