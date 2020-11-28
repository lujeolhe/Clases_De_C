////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
char *generarTitulo();
char *esPar(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  printf("%s\n",generarTitulo() );
  printf("%s\n",esPar(5) );
}

/////////////////////////
//Funciones
/////////////////////////
char *generarTitulo(){
  char *pCadena=(char *)malloc(sizeof(char)*12);
  printf("Soy el puntero pCadena, mi direccion es: %p y apunto a la direccion: %p \n",&pCadena,pCadena );
  char cadena[12]="Hola Mundo";
  strcpy(pCadena,cadena);
  printf("Soy el puntero pCadena, mi direccion es: %p y apunto a la direccion: %p \n",&pCadena,pCadena );
  sprintf(pCadena,"Hola mundo %d",2);
  return pCadena;
}
char *esPar(int n){
  char *pCadena=(char *)malloc(20);
  if(n%2==0){
    sprintf(pCadena,"El numero %d es par",n);
  }
  else
    sprintf(pCadena,"El numero %d es impar",n);
  return pCadena;
}
