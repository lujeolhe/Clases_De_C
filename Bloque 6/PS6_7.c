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
#define tam_max 30
/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void inicializar_matriz(int numeros[][tam_max],int n,int m);
void mover_derecha(int numeros[][tam_max],int n,int j,int m);
void mover_izquierda(int numeros[][tam_max],int n,int j,int m);
void mover_abajo(int numeros[][tam_max],int n,int j,int m);
void mover_arriba(int numeros[][tam_max],int m, int j,int i,int n);
void movimiento(int numeros[][tam_max],int m,int n);
void imprimir(int numeros[][tam_max],int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int numeros[tam_max][tam_max];
  int n=4,m=5;
  inicializar_matriz(numeros,n,m);
  movimiento(numeros,m,n);
}
/////////////////////////
//Funciones
/////////////////////////
void inicializar_matriz(int numeros[][tam_max],int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      numeros[i][j]=0;
    }
  }
}
void mover_derecha(int numeros[][tam_max],int n,int i,int m){
  int aux=0;
  numeros[i][0]=1;
  imprimir(numeros,n,m);
  for(int j=1;j<m;j++){
    printf("Valor de j=%d\n",j );
    numeros[i][j]=numeros[i][j-1];
    numeros[i][j-1]=aux;
    imprimir(numeros,n,m);
  }
  numeros[i][m-1]=0;
}
void mover_izquierda(int numeros[][tam_max],int n, int i,int m){
  int aux=0;
  int j=m-1;
  numeros[i][j]=1;
  for(;j>0;j--){
    numeros[i][j-1]=numeros[i][j];
    numeros[i][j]=aux;
    imprimir(numeros,n,m);
  }
  numeros[0][j]=0;
}
void movimiento(int numeros[][tam_max],int m,int n){
  for(int k=0;k<2;k++){
    int i=0;
    int j=m-1;
    mover_derecha(numeros,n,i,m);
    mover_abajo(numeros,n,j,m);
    i=n-1;
    j=0;
    mover_izquierda(numeros,n,i,m);
    if(k==1)
      mover_arriba(numeros,m,j,i,n);
  }
}
void mover_arriba(int numeros[][tam_max],int m, int j,int i,int n){
  int aux=0;
  numeros[i][j]=1;
  for(;i>1;i--){
    numeros[i-1][j]=numeros[i][j];
    numeros[i][j]=aux;
    imprimir(numeros,n,m);
  }
  numeros[n-2][j]=0;
}
void mover_abajo(int numeros[][tam_max],int n,int j,int m){
  int aux=0;
  numeros[0][j]=1;
  for(int i=0;i<n-1;i++){
    numeros[i+1][j]=numeros[i][j];
    numeros[i][j]=aux;
    imprimir(numeros,n,m);
  }
  printf("Fin de abajo\n" );
  numeros[n-1][j]=0;
}
void imprimir(int numeros[][tam_max],int n,int m){
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      printf("[%d] ",numeros[i][j] );
    }
    printf("\n" );
  }
    printf("\n\n" );
}
