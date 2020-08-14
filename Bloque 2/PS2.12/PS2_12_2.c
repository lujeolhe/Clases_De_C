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
  int n,m=0,c=0,d=0,u=0;
  printf("Dame un numero de 4 digitos\n" );
  scanf("%d",&n );
  printf("\n" );
  m=n/1000;
  c=(n%1000)/100;
  d=(n%100)/10;
  u=n%10;
  if(m%2==0&&c%2==0&&d%2==0&&u%2==0){
    printf("Todos los digitos son pares\n" );
  }
  else{
    printf("Uno o varios digitos no son pares\n" );
  }
}
