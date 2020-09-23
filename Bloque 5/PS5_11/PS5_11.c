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
int numeros_perf(int n);
void almacenador(int numeros[]);
void imprime_matriz(int numeros[],int n);
void inicializar(int numeros[]);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int numeros[tam_max];
  printf("Estos son los primeros 30 numeros perfectos\n" );
  inicializar(numeros);
}
int numeros_perf(int n){
  //printf("Entre a numeros_perf\n" );
  int aux=0;
  for(int i=1;i<n;i++){
    if(n%i==0)
    aux+=i;
    //printf("hice la operacion\n" );
    //printf("valor de aux: %d\n",aux );
  }
  if(aux==n){
  //printf("salgo de numeros_perf positivo\n" );
  return 1;
}
  else{
  //printf("salgo de numeros_perf negativo\n" );
  return 0;
}
}

void almacenador(int numeros[]){
  //printf("Entre a almacenador\n" );
  int cont=0;
  for(int i=6;cont<=4;i++){
    //printf("valor de i: %d\n",i );
    if(numeros_perf(i)){
      cont++;
      numeros[cont]=i;
    }
  }
  imprime_matriz(numeros,30);
}

void imprime_matriz(int numeros[],int n){
  for(int i=1;  i<n ; i++){
    printf("%d ",numeros[i]);
  }
  printf("\n" );
}

void inicializar(int numeros[]){
  printf("Entre a inicializar\n" );
  for(int i=1;i<=30;i++){
    numeros[i]=0;
  }

  almacenador(numeros);
}
