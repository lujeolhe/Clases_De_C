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
int divisores(int n);
void rango(int n,int m);
void ensena_rango(int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n,m;
  printf("Dame un rango de para los numeros perfectos\n" );
  printf("De: " );
  scanf("%d",&n );
  printf("Al: " );
  scanf("%d",&m );
  rango(n,m);
}
void rango(int n, int m){
  printf("\nLos numeros Perfectos son:\n" );
  for(int i=n-1;i>m;i--){
    if(divisores(i))
    printf("||%d",i );
  }
}

int divisores(int n){
  int aux=0;
  for(int i=1;i<n;i++){
    if(n%i==0)
    aux+=i;
  }
  if(aux==n)
  return 1;
  else
  return 0;
}
