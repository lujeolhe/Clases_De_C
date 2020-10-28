////////////////////////
//Librerias
/////////////////////////
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string.h>
using namespace std;
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 100
/////////////////////////
//Clases
/////////////////////////
class Transformador{
public:
    char tipo[tam_max][tam_max];
    float pies[tam_max];
    float libras[tam_max];
/////////////////////////
//Constructor
/////////////////////////
public:
Transformador(){
  char c[tam_max][tam_max]={"Seco","Poste","Pedestal","Pozo","Potencia"};
  float p[tam_max]={1.5,2.9,3.3,7.5,9.5};
  float l[tam_max]={60,260,935,1325,100000};
  for(int j=0;j<5;j++){
    for(int i=0;i<10;i++){
     tipo[j][i]=c[j][i];
   }
 }
 for(int i=0;i<5;i++){
  pies[i]=p[i];
  libras[i]=l[i];
  }
}
/////////////////////////
//Declaracion de  Metodos
/////////////////////////
float convertir_libras(Transformador a,int l);
float convertir_pies(Transformador a,int p);
void tipo_transformador(Transformador a,int i);
void transformador(Transformador a);
void cambiar_tipo(char *c,int i);
void cambiar_pies(float c,int i);
void cambiar_ibras(float c,int i);
float *ret_pies();
float *ret_libras();
char *ret_tipo();
};
/////////////////////////
//Metodos-Fuera
/////////////////////////
float Transformador:: convertir_libras(Transformador a,int i){
  float *p=a.ret_libras();
  return *(p+i)*0.45;
}
float Transformador::convertir_pies(Transformador a,int i){
  float *p=a.ret_pies();
  return *(p+i)*0.3047;
}
void Transformador::tipo_transformador(Transformador a,int i){
  char *c=a.ret_tipo()+30*1;
  string s=c;
  cout<<"Transformador "<<s<<": ";
}
void Transformador::transformador(Transformador a){
  for(int i=0;i<5;i++){
    a.tipo_transformador(a,i);
    cout<<"Peso: "<<a.convertir_libras(a,i)<<"kg, ";
    cout<<"Dimensiones: un cubo de "<<a.convertir_pies(a,i)<<"m"<<"\n";
  }
}
void Transformador::cambiar_tipo(char *c,int i){
  strcpy(tipo[i],c);
}
void Transformador::cambiar_pies(float c,int i){
  pies[i]=c;
}
void Transformador::cambiar_ibras(float c,int i){
  libras[i]=c;
}
float *Transformador::ret_pies(){
  return pies;
}
float *Transformador::ret_libras(){
return  libras;
}
char *Transformador::ret_tipo(){
  return *(tipo);
}
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  Transformador a;
  a.transformador(a);
  for(int i=0;i<5;i++){
  char *c=a.ret_tipo()+10*i;

  cout<<"Transformador "<<a.ret_tipo()+10*i<<": "<<endl;
}
  while(1){
    char b;
    cout<<endl<<"Si desea salir presione n"<<endl;
    cout<<"Si quiere continuar presione cualquier tecla"<<endl;
    cin>>b;
    if(b=='n')
      break;
   }
}
