///////////////////////
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
  int lado;
  printf("Dame el lado del Cubo\n");
  scanf("%d",&lado );
  int AreaB,AreaL,AreaT,Vol;
  AreaB=lado*lado;
  AreaL=4*lado*lado;
  AreaT=6*lado*lado;
  Vol=lado*lado*lado;
  printf("El Area de la Base es: %d u^2\n",AreaB);
  printf("El Area Lateral es: %d u^2\n",AreaL);
  printf("El Area Total es: %d u^2\n",AreaT);
  printf("EL Volumen es: %d u^3\n",Vol);
}
