#include <iostream>
#include  "../headers/Pila.hpp"

using namespace std;
namespace ESTRUCTURAS{
  Pila::Pila(){
    pPila=new int[10];
    tamanio=10;
    index=0;
  }
  Pila::Pila(int x){
    pPila=new int[x];
    tamanio=x;
    index=0;
  }
  const int* Pila::getpPila(){
    return pPila;
  }
  int Pila::getTamanio(){
    return tamanio;
  }
  int Pila::getIndex(){
    return index;
  }
  void Pila::push(int x){
    pPila[index]=x;
    index++;
  }
  int Pila::pop(){
    int aux=pPila[index];
    pPila[index]=0;
    index--;
    return aux;
  }
  ostream& operator<<(ostream& os,Pila *a){
    for(int i=0;i<a->getIndex();i++){
      os<<a->getpPila()[i];
      os<<" ";
    }
    os<<"\n";
    return os;
  }

  Pila::~Pila(){
    std::cout << "Destructor ejecutado, se borro una pila con " <<tamanio<< " elementos \n";
    delete[] pPila;
  }

}
