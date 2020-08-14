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
  int opc,h,s,aux;
  printf("De que categoria eres\n" );
  scanf("%d",&opc );
  switch (opc) {
    case 1:
      printf("Cuantas horas extras hiciste\n" );
      scanf("%d",&h );
      if(h>30){
        printf("Solo se te pagaran las primeras 30 hrs extra\n\n" );
      }
      printf("Cual es tu salario\n" );
      scanf("%d",&s );
      if(h<=30){
        aux=h*40+s;
        printf("Se te debe pagar: %d\n", aux);
      }
      else{
        h=30;
        aux=h*40+s;
        printf("Se te debe pagar: %d\n", aux);
      }
    break;
    case 2:
    printf("Cuantas horas extras hiciste\n" );
    scanf("%d",&h );
    if(h>30){
      printf("Solo se te pagaran las primeras 30 hrs extra\n\n" );
    }
    printf("Cual es tu salario\n" );
    scanf("%d",&s );
    if(h<=30){
      aux=h*50+s;
      printf("Se te debe pagar: %d\n", aux);
    }
    else{
      h=30;
      aux=h*50+s;
      printf("Se te debe pagar: %d\n", aux);
    }
    break;
    case 3:
    printf("Cuantas horas extras hiciste:\n" );
    scanf("%d",&h );
    if(h>30){
      printf("Solo se te pagaran las primeras 30 hrs extra\n\n" );
    }
    printf("Cual es tu salario:\n" );
    scanf("%d",&s );
    if(h<=30){
      aux=h*85+s;
      printf("Se te debe pagar: %d\n", aux);
    }
    else{
      h=30;
      aux=h*85+s;
      printf("Se te debe pagar: %d\n", aux);
    }
    break;
    default:
    printf("Si eres de categoria 4 o mayor no se te pagaran las horas extra,\nesto es solo para los de categoria 3 o menor\n" );
    break;
  }
}
