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

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int a[10]={0,1,2,3,4,5,6,7,8,9};
  int *p=NULL;
  printf("el elemento 12 de a--> %d\n",a[12] );
  p=a;
  printf("Cuando p=a--> %p\n",p );//6422260
  p=p+5;
  printf("Cuando p=p+5--> %p\n",p );//6422280
  printf("%d\n",*p );

  char b[10]={'a','b','c','d','e','f','g','h','i','j'};
  char *pu=NULL;
  pu=b;
  printf("Cuando pu=b--> %p\n",pu );//6422246
  pu=pu+5;
  printf("Cuando pu=pu+5--> %p\n",pu );//6422251
  printf("%c\n",*pu );

}
