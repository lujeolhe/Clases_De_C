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
void inicializar_matriz(int numeros[][tam_max],int n,int m);
void imprimir(int numeros[][tam_max],int n,int m);
void multiplicacion(int numeros1[][tam_max],int numeros2[][tam_max],int n,int m);
void inicializar_matriz2(int numeros[][tam_max],int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int numeros1[tam_max][tam_max],numeros2[tam_max][tam_max];
  int n=5,m=5;
  printf("Matriz 1\n\n" );
  inicializar_matriz(numeros1,n,m);
  printf("Matriz 2\n\n" );
  inicializar_matriz(numeros2,n,m);
  printf("Matriz Resultante\n\n" );
  multiplicacion(numeros1,numeros2,n,m);
  return 0;
}
/////////////////////////
//Funciones
/////////////////////////
void inicializar_matriz2(int numeros[][tam_max],int n,int m){
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      numeros[i][j]=0;
    }
  }
}

void inicializar_matriz(int numeros[][tam_max],int n,int m){
  for(int j=0;j<n;j++){
    for(int i=0;i<m;i++){
      numeros[j][i]=rand()%10;
    }
  }
  imprimir(numeros,n,m);
}

void imprimir(int numeros[][tam_max],int n,int m){
  for(int j=0;j<n;j++){
    for(int i=0;i<m;i++){
      printf("%d ",numeros[j][i]);
    }
    printf("\n" );
  }
  printf("\n" );
}
void multiplicacion(int numeros1[][tam_max],int numeros2[][tam_max],int n,int m){
  int numeros3[tam_max][tam_max];
  inicializar_matriz2(numeros3,n,m);
  for(int j=0;j<n;j++){
    for(int i=0;i<m;i++){
      numeros3[j][i]=numeros1[j][i]*numeros2[j][i];
    }
  }
  imprimir(numeros3,n,m);
}
