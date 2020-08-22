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
  float Area=0,s=0,lado1,lado2,lado3;
  printf("Dime Cuales son los lados de tu triangulo\n" );
  printf("Lado 1:" );
  scanf("%f",&lado1 );
  printf("Lado 2:" );
  scanf("%f",&lado2 );
  printf("Lado 3:" );
  scanf("%f",&lado3);
  if(lado1+lado2>lado3&&lado1+lado3>lado2&&lado2+lado3>lado1){
    if(lado1==lado2&&lado2==lado3&&lado1==lado3){
      s=(lado1+lado2+lado3)/2;
      Area=sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
      printf("Es un triangulo Equilatero\n" );
      printf("Su area es: %.2f u^2\n",Area );
    }
    if(lado1!=lado2&&lado2!=lado3&&lado1!=lado3){
      s=(lado1+lado2+lado3)/2;
      Area=sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
      printf("Es un triangulo Escaleno\n" );
      printf("Su area es: %.2f u^2\n",Area );
    }
    if(lado1==lado2&&lado1!=lado3||lado1!=lado2&&lado2==lado3){
      s=(lado1+lado2+lado3)/2;
      Area=sqrt(s*(s-lado1)*(s-lado2)*(s-lado3));
      printf("Es un triangulo Isoceles\n" );
      printf("Su area es: %.2f u^2\n",Area );
    }
  }
  else{
    printf("No es un triangulo\n" );
  }

}
