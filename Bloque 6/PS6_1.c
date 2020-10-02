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
void inicializar_matriz(int numeros[][tam_max],int n);
void llenar(int numeros[][tam_max],int n);
void imprimir(int numeros[][tam_max],int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n=4;
  int numeros[tam_max][tam_max];
  inicializar_matriz(numeros,n);
  return 0;
}
/////////////////////////
//Funciones
/////////////////////////
void inicializar_matriz(int numeros[][tam_max],int n){
  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      numeros[j][i]=0;
    }
  }
  llenar(numeros,n);
}
void llenar(int numeros[][tam_max],int n){
  int k=3;
  for(int i=0;i<n;i++){
    for(int j=0;j<n;j++){
      if(i==j){
        numeros[i][j]=1;
      }
      else if(j==k){
        numeros[i][j]=1;
        k--;
      }
    }
  }
  imprimir(numeros,n);
}
void imprimir(int numeros[][tam_max],int n){
  for(int j=0;j<n;j++){
    for(int i=0;  i<n ; i++){
      printf("%d ",numeros[i][j]);
    }
    printf("\n" );
  }
}
