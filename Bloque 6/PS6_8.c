////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <dos.h>
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 10
/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void inicializar_matriz(int numeros[][tam_max],int n,int m);
void mover_abajo(int numeros[][tam_max],int n,int j,int m);
void mover_arriba(int numeros[][tam_max],int n,int j,int m);
void mover_dere(int numeros[][tam_max],int m,int n);
void imprimir(int numeros[][tam_max],int n,int m);
void delay(int number_of_seconds);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int numeros[tam_max][tam_max];
  int n=5,m=5;
  inicializar_matriz(numeros,n,m);
  mover_dere(numeros,m,n);
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
void mover_abajo(int numeros[][tam_max],int n,int j,int m){
  int aux=0;
  numeros[0][j]=1;
  imprimir(numeros,n,m);
  for(int i=0;i<n-1;i++){
    numeros[i+1][j]=numeros[i][j];
    numeros[i][j]=aux;
    imprimir(numeros,n,m);
  }
  numeros[n-1][j]=0;
}
void mover_arriba(int numeros[][tam_max],int n, int j,int m){
  int aux=0;
  int i=n;
  numeros[i][j]=1;
  for(;i>0;i--){
    numeros[i-1][j]=numeros[i][j];
    numeros[i][j]=aux;
    imprimir(numeros,n,m);
  }
  numeros[0][j]=0;
}
void mover_dere(int numeros[][tam_max],int m,int n){
  for(int j=0;j<m;j++){
    if(j%2==0)
      mover_abajo(numeros,n,j,m);
    if(j%2!=0)
      mover_arriba(numeros,n,j,m);
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
    delay(500);
    system("cls");
}
void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds =  number_of_seconds;

    // Storing start time
    clock_t start_time = clock();

    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds)
        ;
}
