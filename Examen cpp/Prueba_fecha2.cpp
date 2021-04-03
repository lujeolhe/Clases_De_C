#include <iostream>
#include "Naturales.hpp"
#include "Clase_fecha.hpp"
using namespace std;
using namespace NUMEROS;
int main(){
    try{
      Fecha a,b;
      cout<<a<<endl;
      a++;
      cout<<a<<endl;
      Fecha c=a+32;
      cout<<c<<endl;
      b--;
      cout<<b<<endl;
      Fecha d(20,3,2021);
      cout<<d<<endl;
  }
  catch(const char *s ){
    cout << "\n" << s <<endl;
  }
}
///Operador ++,--,<<,+
//contruc personalizado primer dia, defecto
//atributos de tipo Natural
