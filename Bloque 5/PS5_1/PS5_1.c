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
int positivo(int  numeros[],int i);
int negativo(int numeros[],int i);
int nulo(int numeros[],int i);
void signos(int numeros[],int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int numeros[tam_max];
  int n;
  printf("Dime cuantos numeros naturales quieres\n" );
  scanf("%d",&n );
  signos(numeros,n);

}
void signos(int numeros[] ,int n){
  int i,posi=0,nega=0,nul=0;
  for(i=0;i<n;i++){
    numeros[i]=0;
  }
  for(i=0;i<n;i++){
    numeros[i]=rand()%100-50;
    printf("%d ",numeros[i] );
    posi+=positivo(numeros,i);
    nega+=negativo(numeros,i);
    nul+=nulo(numeros,i);
  }
  printf("\nSon %d numeros positivos  \n",posi );
  printf("Son %d numeros negativos  \n",nega );
  printf("Son %d numeros nulos  \n",nul );
}
int positivo(int numeros[],int i){
  if(numeros[i]>0)
  return 1;
  else
  return 0;
}
int negativo(int numeros[],int i){
  if(numeros[i]<0)
  return 1;
  else
  return 0;
}
int nulo(int numeros[],int i){
  if(numeros[i]==0)
  return 1;
  else
  return 0;
}
