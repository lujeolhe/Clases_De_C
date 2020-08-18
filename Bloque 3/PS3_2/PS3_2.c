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
float suma(float n);
void resultado();
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  resultado();
}

float suma(float n){
  float aux=0;
  for(int i=0;i<n;i++){
      aux+=1/(n-i);
    }
  return aux;
}

void resultado(){
  float n;
  printf("Dame un numero\n" );
  scanf("%f",&n );
  printf("El resultado es: %.3f\n",suma(n) );
}
