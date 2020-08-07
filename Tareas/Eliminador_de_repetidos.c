/*Problema  PR5.2
Escribe un programa en C que, al recibir como dato un arreglo
unidimensional desordenado de n enteros, obtenga como salida ese
mismo arreglo pero sin los elementos repetidos.*/

////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
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

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand (time(NULL));
  int n;
  printf("Cuantos numeros quieres poner \n" );
  scanf("%d",&n );

  int a[tam_max];
  for(int i=0;i<n;i++){
    a[i]=0;
  }

  for(int i=0;i<n;i++){
    a[i]=rand()%30;
  }

  printf("Esta es la cadena con numeros repetidos\n" );
  for(int i=0;i<n;i++){
      printf("%d ",a[i] );
    }
    printf("\n" );

  int b[tam_max];
  for(int i=0;i<n;i++){
    b[i]=0;
  }

  int contador=0;
   for(int j=0;j<n;j++){
     for(int i=j;i<n;i++){
       if(a[j]==a[i+1]&&j<n-1){
         break;
       }
       else{
          if(i==n-1){
            b[contador]=a[j];
            contador++;
          }

        }
     }


   }
   printf("Esta es la cadena sin numeros repetidos\n" );
   for(int i=0;i<n;i++){
     printf("%d ",b[i] );
   }
   printf("\n" );
  }





/////////////////////////
//Funciones
/////////////////////////
