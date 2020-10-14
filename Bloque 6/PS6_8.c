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
void mover_abajo(int numeros[][tam_max],int n,int m);
void mover_arriba(int numeros[][tam_max],int n,int m,int i,int cont);
void imprimir(int numeros[][tam_max],int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int numeros[tam_max][tam_max];
  int n=4,m=5;
  inicializar_matriz(numeros,n,m);
  numeros[0][0]=1;
  mover_abajo(numeros,n,m);
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
void mover_abajo(int numeros[][tam_max],int n,int m){
  int aux=0;
  int cont=3;
  imprimir(numeros,n,m);
    for(int i=0;i<m;i++){
      printf("Valor de i: %d\n",i );
      for(int j=0;j<n;j++){
        if(i%2==0){
          numeros[j+1][i]=numeros[j][i];
          numeros[j][i]=aux;
          printf("Valor de j: %d\n",j );
          if(j+1<n)
          imprimir(numeros,n,m);
        }
        else{
          mover_arriba(numeros,n,m,i,cont);
        }
      }
      printf("Esto es del mover abajo\n" );
    }
}
void mover_arriba(int numeros[][tam_max],int n,int m,int i,int cont){
  int aux=0;
  numeros[cont][i]=1;
  imprimir(numeros,n,m);
  for( ;i<2;i++){
    for(;cont>0;cont--){
      if(i%2!=0){
        numeros[cont-1][i]=numeros[cont][i];
        numeros[cont][i]=aux;
        imprimir(numeros,n,m);
      }
      else{
        printf("Valor de i en mover arriba %d\n",i );
        return;
      }
    }
  }
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
