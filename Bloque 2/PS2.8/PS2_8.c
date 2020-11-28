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
  int opc;
  float j,kil=0;
  float n,pul=0;
  float m,met=0;
  printf("Dime que quieres convertir\n" );
  printf("1.- Pulgadas a Milimetros\n" );
  printf("2.- Yardas a Metros\n" );
  printf("3.- Millas a Kilometros\n" );
  printf("4.- Salir\n" );
  scanf("%d",&opc );
  switch (opc) {
    case 1:
      printf("Dime cuantas pulgadas quieres convertir\n");
      scanf("%f",&n );
      pul=n*25.40;
      printf("Son: %.3f milimetros\n",pul );
      break;

    case 2:
      printf("Dime cuantas pulgadas quieres convertir\n");
      scanf("%f",&m );
      met=m*0.9144;
      printf("Son: %.3f metros\n",met );
      break;

    case 3:
      printf("Dime cuantas pulgadas quieres convertir\n");
      scanf("%f",&j );
      kil=j*1.6093;
      printf("Son: %.3f kilometros\n",kil );
      break;

    default:
      break;
  }
}
