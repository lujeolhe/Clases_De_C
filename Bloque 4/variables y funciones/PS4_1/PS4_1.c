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
int pares(int n);
int impares(int n);
void numeros_aleatorios(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int n;
  printf("Dime cuantos numeros quieres\n" );
  scanf("%d",&n );
  numeros_aleatorios(n);
  return 0;
}

void numeros_aleatorios(int n){
  int numeros=0,par=0,impar=0;
  for(int i=0;i<n;i++){
    numeros=rand()%500;
    printf("%d ",numeros );
    par=pares(numeros);
    impar=impares(numeros);
  }
  printf("\nSon: %d numeros par\n",par );
  printf("Son: %d numeros impar\n",impar );
}

int pares(int n){
  static int contador_pares=0;
    if(n%2==0)
      contador_pares++;
    return contador_pares;
  }

  int impares(int n){
    static int contador_impares=0;
      if(n%2!=0)
        contador_impares++;
      return contador_impares;
    }
