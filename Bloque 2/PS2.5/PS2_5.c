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
  int c;
  printf("Monto de la compra del cliente\n" );
  printf("$");
  scanf("%d",&c );
  int aux=0;
  if(c<800){
    aux=c;
    printf("Monto a pagar: $%d\n",aux );
  }
  else if(800<=c&&c<=1500){
    aux=c*.9;
    printf("Monto a pagar: $%d\n",aux );
  }
    else if(3000<c&&c<=5000){
      aux=c*.85;
      printf("Monto a pagar: $%d\n",aux );
    }
      else if(5000<c){
        aux=c*.80;
        printf("Monto a pagar: $%d\n",aux );
      }
}
