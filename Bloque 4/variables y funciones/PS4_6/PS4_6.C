////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void coseno(int n);
void imprimir(int i,int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  printf("Dame un numero para sacar el valor de Seno\n" );
  scanf("%d",&n );
  coseno(n);
}

void coseno(int n){
  printf("Coseno(%d)= ",n );
  float aux_fac=1, suma=0, valor_anterior=0,valor_nuevo=2;
  for(int i=1;fabs(valor_nuevo-valor_anterior)>0.0000003;i++){
    if(i==1){
      aux_fac*=1;
      imprimir(i,n);
    }
    else{
      aux_fac*=((i-1)*2)*(((i-1)*2)-1);
      imprimir(i,n);
    }
    valor_anterior=valor_nuevo;
    suma+=(pow(-1,i+1)*pow(n,(i-1)*2))/aux_fac;
    valor_nuevo=suma;
  }
  printf("= %.5f",suma );
}

void imprimir(int i,int n){
   static int aux=2;
  if(i<=n){
    if(i==1)
      printf("%d ",i );
      else if(i%2==0){
        printf(" - %d^%d/%d!",n,aux,aux );
          aux=aux+2;
      }
      else{
        printf(" + %d^%d/%d!",n,aux,aux );
          aux=aux+2;
      }
  }
}
