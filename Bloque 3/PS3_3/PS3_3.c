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
  int n;
  printf("Dime cuantos numeros quieres\n" );
  scanf("%d",&n );
  float aux=1,m=1;
  for(int i=1;i<=n;i++,m++){
    if(i==1){
      aux/=1;
      printf("%d * ",1 );
    }
    else if(i%2==0){
      if(i==n){
        printf("%d/%d = ",1,i );
          aux=aux*(1/m);
      }
      else{
        aux=aux*(1/m);
        printf("%d/%d / ",1,i );
      }
    }
    else{
      aux=aux/(1/m);
      printf("%d/%d * ",1,i );
    }
  }
  printf("%.3f\n",aux );
}
