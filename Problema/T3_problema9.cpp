///////////////////////
//Librerias
/////////////////////////
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <string.h>
#include <iomanip>
using namespace std;
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 100
#define num_alum 2
/////////////////////////
//Clases
/////////////////////////
class Alumnos{
private:
    char nombre[10][30];
    float ordinario[10];
    float ordinario2[10];
    float ordinario3[10];
  /////////////////////////
  //Metodos
  /////////////////////////
public:
  static void leer_nombre(Alumnos *a){
    for(int i=0;i<num_alum;i++){
    cout<<"\nDame el nombre del alumno "<<i+1<<endl;
    //funciona como un arreglo de string
    cin>>a->nombre[i];
    //a->setdar_nombre(n,i);
    //printf("Valor de nombre: %s\n",a->getnombre() );
    printf("Ahora voy a pedir calificaiones\n" );
    a->calificaciones(i);
    }
  }
     void setdar_nombre(char *n,int i){
       //char *aux=*(nombre+(i*30));
      strcpy(nombre[i],n);
      printf("Ya cambie el nombre\n" );
    }
    void set_ordinario1(float o,int i){
      ordinario[i]=o;
    }
    void calificaciones(int i){
        cout<<"Dame la calificion del ordinario 1"<<endl;
        cin>>ordinario[i];
        cout<<"Dame la calificion del ordinario 2"<<endl;
        cin>>ordinario2[i];
        cout<<"Dame la calificion del ordinario 3"<<endl;
        cin>>ordinario3[i];
      }
    void comentarios(float c){
      if(c>6||c==6)
      cout<<"\t\t     Aprobado"<<endl;
      else
      cout<<"\t\t     No aprobado"<<endl;
    }
    void tablas(Alumnos a ){
      cout<<"Nombre\t\t"<<"Ordinario 1\t"<< std::setw(8)<<"Ordinario 2\t"<< std::setw(8)<<"Ordinario 3\t"<< std::setw(8);
      cout<<"Aprobado/No aprobado"<<endl;
      for(int i=0;i<num_alum;i++){
        float *p=a.getordinario();
        float *p2=a.getordinario2();
        float *p3=a.getordinario3();
        const char *s=a.getnombre()+30*i;
        //*s='p';
        string ss=s;
        //string *s=a.getnombre()+30*i;
        float c=0;

        c=(*(p+i)+*(p2+i)+*(p3+i))/3;
        //printf("Valor de p: %f\n", *p+i);
        //printf("Valor de ordinario1: %f\n",a.ordinario[i] );
        //cout<<"Valor de p"<<*p+i;
        cout<<""<<ss<<"\t\t     "<<*(p+i)<<"\t\t     "<<*(p2+i)<<"\t\t     "<<*(p3+i);
        comentarios(c);
      }
    }
    float *getordinario(){
      return ordinario;
    }
    float *getordinario2(){
      return ordinario2;
    }
    float *getordinario3(){
      return ordinario3;
    }
    //se coloca const para que no se pueda modificar
    const char *getnombre(){
      return *(nombre);
    }
};
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  Alumnos a;
  while(1){
    Alumnos::leer_nombre(&a);
    printf("Valor de nombre en main: %s\n",a.getnombre() );
    a.setdar_nombre("Pablo",1);
    a.tablas(a);
    char b;
    cout<<"Presione n para salir"<<endl;
    cout<<"Si quiere continuar presione cualquier tecla"<<endl;
    cin>>b;
    if(b=='n'){
      break;
    }
  }
}
