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
int inicializar(int numero[],int n);
void repetidos(int numeros[], int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int n,numeros[tam_max];
  printf("Dime cuantos numeros quieres\n" );
  scanf("%d",&n );
  printf("\nArreglo con Numeros repetidos \n" );
  inicializar(numeros,n);
  printf("\n\n" );
  printf("Arreglo sin Numeros repetidos \n" );
  repetidos(numeros,n);
}
int inicializar(int numeros[] ,int n){
  int i;
  for(i=0;i<n;i++){
    numeros[i]=0;
  }
  for(i=0;i<n;i++){
    numeros[i]=rand()%100;
    printf("%d ",numeros[i] );
  }
  return numeros[i];
}

void repetidos(int numeros[], int n){
  for(int j=0;j<n;j++){
    for(int i=1;i<=n;i++){
      if(numeros[j]==numeros[j+i]){
        while(j+i<n){
          numeros[j+i]=numeros[j+i+1];
          i++;
        }
        n--;
        j=0;
      }
      else
      numeros[j]=numeros[j];
    }
  }

  for(int i=0;i<n;i++){
    printf("%d ",numeros[i] );
  }
}
