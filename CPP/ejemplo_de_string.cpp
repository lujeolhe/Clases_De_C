#include<stdio.h>
#include<iostream>
#include"String.h"
using namespace std;
using namespace myNameSpace;
int main(){
  String a;
  a.setString("Hola que tal");
  cout<<""<<a.getString()<<endl;
  cout<<"Longitud del arreglo: "<<a.ssize()<<endl;
  String b[10];
  char c[20][20]={"Hola " , "Juan Pecas " ,"pica papas " ,"con " ,"un ", "pico ", "Juan Pecas " ,"pica papas " ,"con un " ,"pico "};
  for(int i=0;i<10;i++){
    b[i].setString(c[i]);
  }
  for(int i=0;i<10;i++){
    cout<<""<<b[i].getString();
  }
  cout<<endl;

  for(int i=0;i<10;i++){
    cout<<"Longitud del arreglo: "<<b[i].ssize()<<endl;
  }
}
