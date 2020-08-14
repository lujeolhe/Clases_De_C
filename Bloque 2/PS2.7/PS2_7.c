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
  int x;
  printf("Dame el valor de 'X' para hallar 'Y'\n" );
  scanf("%d",&x );
  float y=0;
  switch (x%4) {
    case 0:
      y=pow(x,3);
      printf("El valor de 'Y' es: %.0f\n",y );
      break;
    case 1:
      y=(pow(x,2)-14)/pow(x,3);
      printf("El valor de 'Y' es: %.3f\n",y );
      break;
    case 2:
      y=pow(x,3)+5;
      printf("El valor de 'Y' es: %.1f\n",y );
      break;
    case 3:
      y=sqrt(x);
      printf("El valor de 'Y' es: %.3f\n",y );
      break;
    default:
      break;
  }

}
