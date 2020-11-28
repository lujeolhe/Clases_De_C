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
//n+POTENCIA(-1,i+1)*POTENCIA(n,(i-1)*2)/FACT((i-1)*2)
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  printf("Dame un numero para sacar el valor de Seno\n" );
  scanf("%d",&n );
  printf("Coseno(%d)= ",n );
  float aux_fac=1, suma=0, valor_anterior=0,valor_nuevo=2;
  for(int i=1;fabs(valor_nuevo-valor_anterior)>0.0000003;i++){
    if(i==1){
      aux_fac*=1;
    }
    else{
      aux_fac*=((i-1)*2)*(((i-1)*2)-1);
    }
    valor_anterior=valor_nuevo;
    suma+=(pow(-1,i+1)*pow(n,(i-1)*2))/aux_fac;
    valor_nuevo=suma;
  }
  printf("= %.5f",suma );
}
