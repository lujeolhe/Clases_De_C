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

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  float n,m,j;
  printf("Dame tres numeros de la forma a,b,c\n" );
  scanf("%f,%f,%f",&n,&m,&j );
  if(n<=m){
    if(m<=j){
      printf("El numero mas grande es: %.1f\n",j );
    }
    else{
      printf("El numero mas grande es: %.1f\n",m );
    }
  }
  else if(n<=j){
    printf("El numero mas grande es: %.1f\n",j );
  }
    else{
      printf("El numero mas grande es: %.1f\n",n );
    }
}
