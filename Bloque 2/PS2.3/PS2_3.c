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
  int n,m;
  printf("Dame dos numeros de la forma\n");
  printf("Primer numero\n" );
  scanf("%d",&n );
  printf("Segundo numero\n" );
  scanf("%d",&m );

  if (n%m==0) {
    printf("El divisor de %d es %d\n",n,m);
  }
  else if(m%n==0){
    printf("El divisor de %d es %d\n",m,n );
  }
  else{
    printf("Ninguno es divisor del otro\n" );
  }
}
