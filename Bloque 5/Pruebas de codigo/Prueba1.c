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
const int max = 100;
/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void lectura(float *, int);
double suma(float *, int);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(void){
  float vec[max];
  double res;
  lectura(vec,max);
  res=suma(vec,max);
  printf("\n\nSuma del arreglo: %.21f",res );
}

void lectura(float a[], int t){
  int i;
  for(i=0;i<t;i++){
    printf("Ingresa el elemento %d: ",i+1 );
    scanf("%f",&a[i] );
  }
}
double suma(float a[], int t){
  int i;
  double aux=0.0;
  for(i=0;i<t;i++){
    aux+=pow(a[i],2);
  }
  return (aux);
}
