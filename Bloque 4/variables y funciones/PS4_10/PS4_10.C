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
int pal(int x ,int y);
/////////////////////////
//Funcion Principal
/////////////////////////
/* no me permite correrlo con el Void main(void), asi que lo cambie a int main(void)
para que me permitiera correrlo, porque sino no funcionaria*/
int a,b,c,d;
int main(void){
  a=2;
  c=3;
  d=5;
  a=pal(c,d);//4
  printf("\n%d %d %d %d",a,b,c,d );//4,basura,3,5
  b=4;
  b=pal(b,a);//5
  printf("\n%d %d %d %d",a,b,c,d );//4,5,3,5
}

int pal(int x,int y){
  int c;
  b=x*y;//15//16
  c=b+y;//20//20
  x++;//4//5
  y=y*(y+1);//30//20
  printf("\n%d %d %d %d",b,c,x,y );// Primera 15,20,4,30//Segundo 16,20,5,20
  return (x);//4//5
}
