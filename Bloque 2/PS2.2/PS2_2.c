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
  int s;
  printf("Dame el salario del Profesor\n" );
  printf("$");
  scanf("%d",&s );
  int aux=0;
  if(s<18000){
    aux=s*1.12;
    printf("El nuevo salario es: $%d\n",aux );
  }
  else if(18000<=s&&s<=30000){
    aux=s*1.8;
    printf("El nuevo salario es: $%d\n",aux );
  }
    else if(30000<s&&s<=50000){
      aux=s*1.7;
      printf("El nuevo salario es: $%d\n",aux );
    }
      else if(50000<s){
        aux=s*1.6;
        printf("El nuevo salario es: $%d\n",aux );
      }
}
