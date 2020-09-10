////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void tasa_mensual(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  float n;
  printf("Cuento dinero desea guardar en nuestro banco\n" );
  scanf("%f",&n );
  tasa_mensual(n);
}

void tasa_mensual(int n){
  float acumulado=0, interes=0.06;
  printf("Esto seria el dinero que obtendria con un interes del 6 % \n" );
  for(int mes=1;mes<=12;mes++){
    acumulado=((interes/12)*mes)*n;
    printf("Mes %d =$ %.4f\n",mes,acumulado );
  }
}
