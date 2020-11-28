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
int factorial(int n);
void imprimir();
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  imprimir();
}

int factorial(int n){
    if(n>=0){
      if(n==0){
        return 1;
      }
      else{
        return n*factorial(n-1);
      }
    }
  }
void imprimir(){
  int n;
  printf("Dame un numero para darte el factorial\n" );
  scanf("%d",&n );
  printf("%d\n",factorial(n) );
}
