#include <iostream>
#include "Naturales.hpp"
#include "Clase_hora.hpp"
using namespace std;
using namespace NUMEROS;
int main(){
    try{
      Hora a(1,1,1),b;
      cout<<"Hora a: "<<a<<endl;
      a++;
      cout<<"Hora a: "<<a<<endl;
      Hora c=a+32;
      cout<<c<<endl;
      b--;
      cout<<b<<endl;
      Hora d(19,59,21);

      cout<<"Hora d: "<<d<<endl;

      cout<<"Suma horas a y d: "<<d+a<<endl;
  }
  catch(const char *s ){
    cout << "\n" << s <<endl;
  }
}
