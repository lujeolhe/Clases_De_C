////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
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
  int n;
  printf("Dame un numero de 4 digitos\n" );
  scanf("%d",&n );
  printf("\n" );
  printf("%d\n",n/1000 );
  printf("%d\n",(n%1000)/100 );
  printf("%d\n",(n%100)/10 );
  printf("%d\n",n%10 );
}