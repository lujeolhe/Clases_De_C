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
//n+POTENCIA(-1,i+1)*POTENCIA(n,2*i-1)/FACT(2*i-1)
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  printf("Dame un numero para sacar el valor de Seno\n" );
  scanf("%d",&n );
  printf("Seno(%d)= ",n );
  float aux_fac=1, suma=0, valor_anterior=0,valor_nuevo=1;
  for(int i=1;fabs(valor_nuevo-valor_anterior)>0.00001;i++){
    if(i<3){
      aux_fac*=(2*i-1)*i;
    }
    else{
      aux_fac*=(2*i-1)*(2*i-2);
    }
    valor_anterior=valor_nuevo;
    suma+=(pow(-1,i+1)*pow(n,2*i-1))/aux_fac;
    valor_nuevo=suma;
  }
  printf("= %f",suma );
}
