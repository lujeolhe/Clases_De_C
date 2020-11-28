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
int factorial(int n,int m);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
int n,m;
printf("Dime el numero del cual quieres su factorial\n" );
scanf("%d",&n );
m=n;
printf("%d\n",factorial(n,m) );
}

int factorial(int n,int m){
  static int contador=0;
  contador++;
  if(n==0)
    return 1;

  else if(contador==m){
    printf("%d= ",contador );
    return n*factorial(n-1,m);
  }
    else{
      printf("%d* ",contador );
      return n*factorial(n-1,m);
    }
}
