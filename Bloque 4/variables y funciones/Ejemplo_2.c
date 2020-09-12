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
int prueba(int n);
int factorial(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  //int contador=0;
  srand(time(NULL));
  int n=rand()%10;
  /*for(int i=0;i<n;i++){
    contador=prueba(i);
  }
  printf("La funcion se mando a llamar %d veces\n",contador );*/
  printf("El valor de n: %d\n",n );
  printf("Factorial: %d\n",factorial(n) );

}
int prueba(int n){
  static int j=0;
  printf("*\n");
  j++;
  return j;
}
int factorial(int n){
  static int contador=0;
  contador++;
  if(n==0){
    printf("La funcion se mando a llamar %d veces\n",contador );
    return 1;
  }
  else{
    return n*factorial(n-1);
  }
}
