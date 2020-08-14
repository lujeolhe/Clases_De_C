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
  int n,m,j;
  printf("Dame 3 numeros de la forma a,b,c\n" );
  scanf("%d,%d,%d",&n,&m,&j );
  if(n<m){
    if(m<j){
      printf("Estan en orden creciente\n" );
    }
    else{
      printf("No esta en orden creciente\n" );
    }
  }
  else{
    printf("No esta en orden creciente\n" );
  }
}
