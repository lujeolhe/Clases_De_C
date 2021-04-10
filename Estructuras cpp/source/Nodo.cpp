#include <iostream>
#include  "../headers/PilaDinamica.hpp"

using namespace std;
namespace ESTRUCTURAS{

  Nodo::Nodo(){
    siguiente=NULL;
    valor=0;
  }
  Nodo::Nodo(int x){
    siguiente=NULL;
    valor=x;
  }
}
