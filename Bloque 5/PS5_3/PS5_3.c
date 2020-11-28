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
#define tam_max 100
/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void fibonachi(long long unsigned int numeros[]);
long long int inicializar(long long unsigned int numero[]);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  long long unsigned int numeros[tam_max];
  inicializar(numeros);
  fibonachi(numeros);
}
void fibonachi(long long unsigned int numeros[]){
  int i=0;
  numeros[i+1]=1;
  for(i=2;i<=tam_max;i++){
    numeros[i]=numeros[i-1]+numeros[i-2];
  }
  for(int i=0;i<tam_max;i++){
    printf("%lld ",numeros[i] );
  }
}
long long int inicializar( long long unsigned int numeros[]){
  int i;
  for(i=0;i<tam_max;i++){
    numeros[i]=0;
  }
  return numeros[i];
}
