////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
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

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int s;
  char mensaje[100];
  printf("Dame el salario del Profesor\n" );
  printf("$");
  scanf("%d",&s );
  int aux=0;
  if(s<18000){
    aux=s*1.12;
    strcpy(mensaje,"es un empleado Nivel 1");
  }
  else if(18000<=s&&s<=30000){
    aux=s*1.08;
    strcpy(mensaje,"es un empleado Nivel 2");
  }
    else if(30000<s&&s<=50000){
      aux=s*1.07;
      strcpy(mensaje,"es un empleado Nivel 3");
    }
      else if(50000<s){
        aux=s*1.06;
        strcpy(mensaje,"es un empleado Nivel 4");
      }
  printf("El nuevo salario es de $%d, %s\n",aux,mensaje );
}
