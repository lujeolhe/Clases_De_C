/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/////////////////////////
//Definiciones
/////////////////////////
#define __tiempo 2
#define __renglones 20
#define __columnas 20
/////////////////////////
//Funciones
/////////////////////////

/////////////////////////
//      MAIN
/////////////////////////
int main(){
  system("cls");
  #ifdef __GNUC__
  printf("Estamos usando GNUC\n" );
  #endif

  #ifdef __MINGW32__
  printf("Estamos usando MINGW32\n" );
  #endif

  #ifdef __MINGW64__
  printf("Estamos usando MINGW64\n" );
  #endif

  //system("cls");
  printf("Bienvenido a las Torres de Hannoi\n" );
  printf("\x1B[38;2;40;192;20m\n");//verde
  printf("|]]]]]]\n" );

  printf("\x1B[38;2;124;50;8m\n");//cafe
  printf("|------\n" );

  printf("\x1B[38;2;150;5;%dm\n",15);//rojo
  printf("|-------\n" );

  //printf("\x1B[0m\n");

}
/////////////////////////
//Funciones
/////////////////////////
