////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////
// 7*t^4-6*p^3+12*r^5<5850
/////////////////////////
//Declaracion de Funciones
/////////////////////////
int resultado(int r,int t,int p);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int r=1,t=1,p=1;
  printf("Los valores que satisfacen la inecuacion son:\n" );
  for(r=1;resultado(r,t,p)>0&&resultado(r,t,p)<5850;r++){
    for(t=1;resultado(r,t,p)>0&&resultado(r,t,p)<5850;t++){
      for(p=1;resultado(r,t,p)>0&&resultado(r,t,p)<5850;p++){
        printf("t=%d p=%d r=%d = %d\n",t,p,r,resultado(r,t,p) );
      }
    }
  }
}
int resultado(int r,int t,int p){
    return 7*pow(t,4)-6*pow(p,3)+12*pow(r,5);
}
