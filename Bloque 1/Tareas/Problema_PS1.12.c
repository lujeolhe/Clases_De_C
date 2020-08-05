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
  float radio;
  printf("Dame el Radio de la Esfera\n" );
  scanf("%f",&radio );
  float Area,Vol;
  Area=4*3.1416*radio*radio;
  Vol=(3.1416*radio*radio*radio)/3;
  printf("El Area es: %.2f u^2\n",Area );
  printf("El volumen es: %.2f u^3\n",Vol );
}
