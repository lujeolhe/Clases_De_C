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
void ordenador(int numeros[],int n);
void inicializar(int numeros[],int n);
void imprime_matriz(int numeros[],int n);
void inicializar_grande(int numeros[],int numeros1[],int n,int m );
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int n,m;
  int numeros[tam_max];
  int numeros1[tam_max];
  printf("Dime de cuantos numeros quieres tu arreglo 1\n" );
  scanf("%d",&n );
  printf("Dime de cuantos numeros quieres tu arreglo 2\n" );
  scanf("%d",&m );
  printf("Arreglo 1:\n" );
  inicializar(numeros,n);
  printf("Arreglo 2:\n" );
  inicializar(numeros1,m);
  ordenador(numeros,n);
  ordenador(numeros1,m);
  printf("Arreglo 3:\n" );
  inicializar_grande(numeros,numeros1,n,m);
}

void ordenador(int numeros[],int n){
  int aux=0;
  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      if(numeros[i]<numeros[i+1]&&i+1<n){
      aux=numeros[i+1];
      numeros[i+1]=numeros[i];
      numeros[i]=aux;
      }
    }
  }
}

void inicializar(int numeros[],int n){
  for(int i=0;i<n;i++){
    numeros[i]=0;
  }
  for(int i=0;i<n;i++){
    numeros[i]=rand()%30;
  }
  for(int i=0;i<n;i++){
    printf("%d ",numeros[i] );
  }
  printf("\n" );
}

void imprime_matriz(int numeros[],int n){
  for(int i=0;  i<n ; i++){
    printf("%d ",numeros[i]);
  }
  printf("\n" );
}
void inicializar_grande(int numeros[],int numeros1[],int n,int m ){
  int k=n+m;
  int aux=0;
  int numeros_ord[tam_max];
  for(int j=0;j<k;j++){
    if(j<k-10)
    numeros_ord[j]=numeros[j];
    else
    numeros_ord[j]=numeros1[j-10];
  }
  ordenador(numeros_ord,k);
  imprime_matriz(numeros_ord,k);
}
