////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
int mifuncion_referencia(int *n);
int mifuncion_valor(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int n=30;
int main(){
  int s=mifuncion_referencia(&n);
  printf("valor de n: %d\n",n );
  s=mifuncion_referencia(&n);
  printf("El valor de s en refencia: %d\n",s );
  printf("valor de n: %d\n",n );
  s=mifuncion_valor(n);
  printf("El valor de s en valor: %d\n",s );
  printf("valor de n: %d\n",n );
}

int mifuncion_referencia(int *n){
 static int k=0;
 k++;
 *n+=30;
 return *n*k;
}
int mifuncion_valor(int j){
  static int k=0;
  k++;
  n+=30;
  return j*k;
}
