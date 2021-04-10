#include <iostream>
#include  "../headers/Pila.hpp"


namespace ESTRUCTURAS{
  Pila::Pila(){
    pPila=new int[10];
    tamanio=10;
  }
  Pila::Pila(int x){
    pPila=new int[x];
    tamanio=x;
  }

  int Pila::getTamanio(){
    return tamanio;
  }
  Pila::~Pila(){
    std::cout << "Destructor ejecutado, se borro una pila con " <<tamanio<< " elementos \n";
    delete[] pPila;
  }

}
