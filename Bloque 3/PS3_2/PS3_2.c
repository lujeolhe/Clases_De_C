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
  return 0;
}

float suma(float n){
  float aux=0,m=1;
  for(int i=0;i<n;i++){
      aux+=1/(n-i);
      if(m==1){
        printf("%.0f +",m );
      }
      else if(m<n){
        printf(" %d/%.0f +",1,m );

      }
      else{
        printf(" %d/%.0f\n",1,m );
      }
      m++;
    }
  return aux;
}

void resultado(){
  float n;
  printf("Dame un numero\n" );
  scanf("%f",&n );
  printf("El resultado es: %.3f\n",suma(n) );
}
