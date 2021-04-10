#include <iostream>
#include  "../headers/PilaDinamica.hpp"

using namespace std;
namespace ESTRUCTURAS{

  PilaDinamica::PilaDinamica(){
    cabeza=NULL;
    index=0;
  }
  PilaDinamica::PilaDinamica(int x){
    cabeza=new Nodo(x);
    index=1;
  }
  Nodo* PilaDinamica::getpPilaDinamica(){
    return cabeza;
  }
  int PilaDinamica::getIndex(){
    return index;
  }
  void PilaDinamica::push(int x){
    if(cabeza==NULL){
      cabeza=new Nodo(x);
      index++;
    }
    else{
      Nodo *auxNodo;
      for(auxNodo=cabeza;auxNodo->siguiente!=NULL;auxNodo=auxNodo->siguiente);
      auxNodo->siguiente=new Nodo(x);
      index++;
    }
  }
  int PilaDinamica::pop(){
    if(cabeza->siguiente==NULL){
      int aux_valor=cabeza->valor;
      index--;
      delete cabeza;
      cabeza=NULL;
      return aux_valor;
    }
    else{
      Nodo *auxNodo;
      //for(auxNodo=cabeza;auxNodo->siguiente!=NULL;auxNodo=auxNodo->siguiente);
      for(auxNodo=cabeza;auxNodo->siguiente->siguiente!=NULL;auxNodo=auxNodo->siguiente);
      int aux_valor=auxNodo->siguiente->valor;
      delete auxNodo->siguiente;
      auxNodo->siguiente=NULL;
      index--;
      return aux_valor;
    }
  }
  ostream& operator<<(ostream& os,PilaDinamica *a){
    Nodo *auxNodo;
    for(auxNodo=a->getpPilaDinamica();auxNodo!=NULL;auxNodo=auxNodo->siguiente){
      os<<auxNodo->valor;
      os<<" ";
    }
    os<<"\n";
    return os;
  }

  PilaDinamica::~PilaDinamica(){
    std::cout << "Destructor ejecutado, se borro una PilaDinamica con " <<index<< " elementos \n";
    int aux=index;
    for(int i=0;i<index;i++){
      pop();
    }
  }
}
