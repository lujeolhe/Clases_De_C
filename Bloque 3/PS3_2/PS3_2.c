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
int suma(float n);
void resultado();
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  resultado();
}

int suma(float n){
  float aux=0;
  for(int i=0;i<n;i++){
      aux+=1/(n-i);
    }
  printf("El resultado es: %.3f\n",aux );
}

void resultado(){
  float n;
  printf("Dame un numero\n" );
  scanf("%f",&n );
  suma(n);
}
