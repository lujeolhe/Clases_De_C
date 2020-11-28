#include<math.h>
#include<stdio.h>
#include <string.h>
#include <iostream>
using namespace std;

class publica{
public:
  int atributo_1;
  static int contador;
  publica(){
    atributo_1=0;
    //contador=0;
  }
  void set(int n){
    atributo_1=n;
  }
  int get(){
    return atributo_1;
  }
};
class privada{
  int atributo_1;
public:
  privada(){
    atributo_1=0;
  }
  void set(int n){
    atributo_1=n;
  }
  int get(){
    return atributo_1;
  }
};
class protegida{
protected:
  int atributo_1;
public:
  protegida(){
    atributo_1=0;
  }
  void set(int n){
    atributo_1=n;
  }
  int get(){
    return atributo_1;
  }
};
class privada_hija:public privada{
public:
  void incrementar_atributo(){
    int p=get();
    p++;
    set(p);
  }
};
class protegida_hija:public protegida{
public:
  void incrementar_atributo(){
    atributo_1++;
  }
};
int main(){
  publica a;
  privada b;
  protegida c;
  cout<<"atributo 1: "<<a.get()<<endl;
  //cout<<"contador: "<<a.contador<<endl;
  cout<<"atributo 1: "<<b.get()<<endl;
  cout<<"atributo 1: "<<c.get()<<endl;
  a.set(3);
  cout<<"atributo 1: "<<a.get()<<endl;
  publica f;
  cout<<"--atributo 1: "<<f.get()<<endl;
  //cout<<"--contador: "<<f.contador<<endl;
  privada_hija d;
  protegida_hija e;
  d.incrementar_atributo();
  e.incrementar_atributo();
  cout<<"atributo 1: "<<d.get()<<endl;
  cout<<"atributo 1: "<<e.get()<<endl;
  return 0;
}
