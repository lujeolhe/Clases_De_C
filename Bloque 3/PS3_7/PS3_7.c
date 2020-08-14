////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 100
/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  long  int n,aux=0,aux2=0,numeros[tam_max];
  printf("dime cuantos numeros quieres\n" );
  scanf("%ld",&n );

  for(int i=0;i<n;i++){
    numeros[i]=0;
  }
  for(int i=0;i<n;i++){
    numeros[i]=1+i;
  }
  printf("\n" );
  for(int i=0;i<n;i++){
    if(i%2==0){
      aux=aux+pow(numeros[i],numeros[i]);
      printf("+%ld^%ld ",numeros[i],numeros[i] );
    }
    else{
      aux2=aux2-pow(numeros[i],numeros[i]);
      printf("-%ld^%ld ",numeros[i],numeros[i] );
    }
  }
  printf("=%ld",aux+aux2 );
}
