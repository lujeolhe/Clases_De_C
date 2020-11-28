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
int inicializar(int numeros[],int n);
void agregar(int numeros[], int n,int aux);
void eliminar(int numeros[],int n,int aux);
void ordenador(int numeros[],int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int opc;
  int n;
  int numeros[tam_max];
  printf("Cuantos numeros quieres\n" );
  scanf("%d",&n );
  inicializar(numeros,n);
  printf("\n" );
  ordenador(numeros,n);
  printf("\n\nPara Agregar un numero escribe '1'\n\nPara eliminar un numero escreibe '0'\n" );
  scanf("%d",&opc );

  if(opc==1){
    int aux;
    printf("\nDime cual numero quieres agregar\n" );
    scanf("%d",&aux );
    agregar(numeros,n,aux);
  }
  else{
    int aux;
    printf("\nDime cual numero quieres eliminar\n" );
    scanf("%d",&aux );
    eliminar(numeros,n,aux);
  }
}
void agregar(int numeros[], int n,int aux){
  int i;
  for(i=0;i<n;i++){
    if(aux==numeros[i]){
      printf("No puedes agregar este numero, ya existe" );
      return;
    }
    else
      numeros[n]=aux;
    }
  for(int i=0;  i<=n ; i++){
    printf("%d ",numeros[i]);
  }
}
void eliminar(int numeros[],int n,int aux){
  int j;
  for(j=0;j<n;j++){
      if(aux==numeros[j]){
        while(j<n){
          numeros[j]=numeros[j+1];
          j++;
        }
      }
    }
    for(int i=0;  i<n-1 ; i++){
      printf("%d ",numeros[i]);
    }
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

void imprime_matriz(int numeros[],int n){
  for(int i=0;  i<n-1 ; i++){
    printf("%d ",numeros[i]);
  }
}
void ordenador(int numeros[],int n){
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
  for(int i=0;i<n;i++){
    printf("%d ",numeros[i] );
  }
}
