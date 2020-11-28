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
  float n,j,l,m;
  printf("Dame los minutos, segundo y centecimas de la forma a,b\n" );
  scanf("%f,%f,%f",&n,&j,&l );
  printf("Dame los metros recorridos\n" );
  scanf("%f",&m );
  float ts=(n*60)+j+(l/100);
  float vms=m/ts;
  float vkh=(vms*3600)/1000;
  printf("La velocidad en k/h es:%.2f\n",vkh );
}
