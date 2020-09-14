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
//Comentario
/////////////////////////
/*Mis comentarios estan en el codigo es lo que creo que va a salir*/
/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int suma(int x,int y){
  return (x+y);
}
int resta(int x,int y){
  return (x-y);
}
int control (int(*apf)(int,int),int x, int y){
  int res;
  res=(*apf)(x,y);
  return (res);
}

int main(void){
  int r1,r2;
  r1=control(suma,15,5);
  r2=control(resta,10,4);
  printf("\nResultado 1: %d",r1 );
  printf("\nResultado 2: %d",r2 );
}
