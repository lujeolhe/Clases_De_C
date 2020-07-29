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
  char cadena1[50];
  printf("Escribe tu palabra\n" );

  for(int i=0;i<50;i++){
    cadena1[i]=0;
  }

  scanf("%s",cadena1 );
  printf("%s\n",cadena1 );

  char aux_cadena[50];
  for(int i=0;i<50;i++){
    aux_cadena[i]=0;
  }

  int i=0;
  while(cadena1[i]!=0&&i<50){
    i++;
  }

  for(int a=0;a<50;a++){
    if(cadena1[i-1]==aux_cadena[0]){
      printf("%s",aux_cadena );
      break;
     }
    else{
       aux_cadena[-a+i-1]=cadena1[a];
    }
  }
}
