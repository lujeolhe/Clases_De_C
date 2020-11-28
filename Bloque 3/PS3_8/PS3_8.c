////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
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
  int n,aux=0;
  printf("Dame el valor de X para halla Y \n" );
  scanf("%d",&n );

    if(0<n&&n<=15){
      aux=pow(n,2)+15;
      printf("El valor de Y es: %d\n",aux );
    }
    else if(15<n&&n<=30){
      aux=pow(n,3)-pow(n,2)+12;
      printf("El valor de Y es: %d\n",aux );
    }
    else if(30<n&&n<=60){
      aux=(4*pow(n,3))/(pow(n,2)+8);
      printf("El valor de Y es: %d\n",aux );
    }
    else{
      printf("El valor de Y es: 0\n" );
    }
}
