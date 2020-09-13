////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
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
int voltea(int m);
int mide(int n);
int potencia(int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  printf("Dame un mumero de n digitos\n" );
  scanf("%d",&n );
  printf("%d\n",voltea(n));
  return 0;
}

int potencia(int n,int m){
  int potencia=1;
  for(int i=1;i<=m;i++){
    potencia*=n;
  }
  return potencia;
}

int mide(int n){
  int contador=0, aux_div=n;
  while(aux_div!=0){
    contador++;
    aux_div/=10;
  }
  return contador;
}

int voltea(int n){
  int aux_div=0,suma=0, j=0;
  for(int i=mide(n);i>0;i--){
    aux_div=n/potencia(10,i-1);
    suma+=(aux_div%10)*potencia(10,j);
    j++;
  }
  return suma;
}
