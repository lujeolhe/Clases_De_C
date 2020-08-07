/*Problema  PR5.2
Escribe un programa en C que, al recibir como dato un arreglo
unidimensional desordenado de n enteros, obtenga como salida ese
mismo arreglo pero sin los elementos repetidos.*/

////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
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
  int n;
  printf("Cuantos numeros quieres poner \n" );
  scanf("%d",&n );

  int a[tam_max];
  for(int i=0;i<n;i++){
    a[i]=0;
  }

  printf("Dame los numeros de la forma a,b\n" );
  for(int i=0;i<n;i++){
    scanf("%d,",&a[i] );
  }

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
   for(int i=0;i<n;i++){
     printf("%d ",b[i] );
   }
   printf("\n" );
  }





/////////////////////////
//Funciones
/////////////////////////
