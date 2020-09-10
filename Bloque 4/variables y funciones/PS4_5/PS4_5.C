////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
float suma(int i,int n);
float resta(int i, int n);
int pow(int n,int m);
void operaciones(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int k;
  printf("Dime cuantos numeros quieres\n" );
  scanf("%d",&k );
  //fracciones(k);
  operaciones(k);
  return 0;
}

float suma(int i,int n){
  static float aux_opera2=3;
  float aux_suma=0;
  if(i==n){
    aux_suma+=pow(aux_opera2,aux_opera2);
    printf("%.0f^%.0f = ",aux_opera2,aux_opera2 );
  }
  else{
    aux_suma+=pow(aux_opera2,aux_opera2);
    printf("%.0f^%.0f - ",aux_opera2,aux_opera2 );
    aux_opera2=aux_opera2+2;
  }
  return aux_suma;
}

float resta(int i, int n){
  static float aux_opera=2;
  float aux_resta=0;
  if(i==n){
    aux_resta-=pow(aux_opera,aux_opera);
    printf("%.0f^%.0f = ",aux_opera,aux_opera );
  }
  else{
    aux_resta-=pow(aux_opera,aux_opera);
    printf("%.0f^%.0f + ",aux_opera,aux_opera );
    aux_opera=aux_opera+2;
  }
  return aux_resta;
}
int pow(int n,int m){
  int potencia=1;
  for(int i=1;i<=m;i++){
    potencia*=n;
  }
  return potencia;
}

void operaciones(int n){
  float operacion=1;
  for(int i=1;i<=n;i++){
    if(i==1)
      printf("%d^1 - ",1 );
    else if(i%2==0)
      operacion+=resta(i,n);
    else
      operacion+=suma(i,n);
  }
  printf("%.0f\n",operacion );
}
