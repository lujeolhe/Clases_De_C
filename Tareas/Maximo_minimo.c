////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand (time(NULL));

  int n;
  printf("Dime cuantos numeros quieres meter\n" );
  scanf("%d", &n);
  int cadena[50];
  for(int i=0;i<50;i++){
    cadena[i]=0;
  }
  
  for(int i=0;i<n;i++){
    cadena[i]=rand()%30+20;
  }
  for(int i=0;i<n;i++){
    printf("%d ",cadena[i] );
  }
  printf("\n" );

  int aux_maximo=0;
  int aux_minimo=cadena[0];
  int i=0;
  while(i<n){
    if(aux_maximo>cadena[i]){
      aux_maximo=aux_maximo;
    }
    else{
      aux_maximo=cadena[i];
    }
    if(aux_minimo>cadena[i]){
      aux_minimo=cadena[i];
    }
    else{
      aux_minimo=aux_minimo;
    }
    i++;
  }
  printf("Este es el maximo:%d\n", aux_maximo);
  printf("Este es el minimo:%d\n", aux_minimo);
}
