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
void ordenador_acen(int numeros[],int n);
void ordenador_desen(int numeros[],int n);
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
  inicializar(numeros,n);
  inicializar(numeros1,m);
  printf("Arreglo 1:\n" );
  ordenador_acen(numeros,n);
  printf("Arreglo 2:\n" );
  ordenador_desen(numeros1,m);
  printf("Arreglo 3:\n" );
  inicializar_grande(numeros,numeros1,n,m);
}

void ordenador_desen(int numeros[],int n){
  int aux=0;
  for(int j=0;j<n;j++){
    for(int i=0;i<n;i++){
      if(numeros[i]>numeros[i+1]&&i+1<n){
      aux=numeros[i+1];
      numeros[i+1]=numeros[i];
      numeros[i]=aux;
      }
    }
  }
  imprime_matriz(numeros,n);
}
void ordenador_acen(int numeros[],int n){
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
  imprime_matriz(numeros,n);
}

void inicializar(int numeros[],int n){
  for(int i=0;i<n;i++){
    numeros[i]=0;
  }
  for(int i=0;i<n;i++){
    numeros[i]=rand()%30;
  }
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
  ordenador_acen(numeros_ord,k);

}
