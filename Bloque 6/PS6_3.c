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
void imprimir(int numeros[][tam_max],int n,int m);
void inicializar_matriz(int numeros[][tam_max],int n,int m);
void inicializar_matriz2(int numeros[][tam_max],int n,int m);
void cambiador(int numeros[][tam_max],int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int numeros[tam_max][tam_max];
  int n=6,m=6;
  printf("Esta es la matriz al principio\n\n" );
  inicializar_matriz(numeros,n,m);
  printf("\nEsta es la matriz despues del cambio\n\n" );
  cambiador(numeros,n,m);
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
      numeros[j][i]=rand()%50;
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
}

void cambiador(int numeros[][tam_max],int n,int m){
  int aux[tam_max][tam_max];
  int aux2[tam_max][tam_max];
  int k=0;
  inicializar_matriz2(aux,n,m);
  inicializar_matriz2(aux2,n,m);
  for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      if(i==k&&k<(n/2))
        aux[i][j]=numeros[i][j];
      else
        aux2[i][j]=numeros[i][j];
    }
    k++;
  }
  k=0;
  for(int i=0,h=n-1;i<n;i++,h--){
    for(int j=0;j<m;j++){
      if(i==k&&k<(n/2))
        numeros[i][j]=aux2[h][j];
      else
        numeros[i][j]=aux[h][j];
    }
    k++;
  }
  imprimir(numeros,n,m);
}
