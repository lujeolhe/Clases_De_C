////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
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
  float L1,L2,L3,Area=0,s=0;
  printf("Dime cuales son los lados de tu triangulo\n" );
  printf("Lado 1:" );
  scanf("%f",&L1 );
  printf("Lado 2:" );
  scanf("%f",&L2 );
  printf("Lado 3:" );
  scanf("%f",&L3 );
  if(L1+L2>L3&&L1+L3>L2&&L2+L3>L1){
    if(L1==L2&&L2==L3){
      s=(L1+L2+L3)/2;
      Area=sqrt(s*(s-L1)*(s-L2)*(s-L3));
      printf("Es un triangulo Equilatero\n" );
      printf("Su area es: %.2f u^2\n",Area );
    }
    else if(L1==L2){
        if(L2!=L3){
          s=(L1+L2+L3)/2;
          Area=sqrt(s*(s-L1)*(s-L2)*(s-L3));
          printf("Es un triangulo Isoceles\n" );
          printf("Su area es: %.2f u^2\n",Area );
        }
    }
      else if(L2!=L3){
          if(L1!=L3){
            s=(L1+L2+L3)/2;
            Area=sqrt(s*(s-L1)*(s-L2)*(s-L3));
            printf("Es un triangulo Escaleno\n" );
            printf("Su area es: %.2f u^2\n",Area );
          }
          else{
            s=(L1+L2+L3)/2;
            Area=sqrt(s*(s-L1)*(s-L2)*(s-L3));
            printf("Es un triangulo Isoceles\n" );
            printf("Su area es: %.2f u^2\n",Area );
          }
      }
        else{
          s=(L1+L2+L3)/2;
          Area=sqrt(s*(s-L1)*(s-L2)*(s-L3));
          printf("Es un triangulo Isoceles\n" );
          printf("Su area es: %.2f u^2\n",Area );
        }
  }
  else{
    printf("Estos lados no son de un triangulo\n" );
  }
}
