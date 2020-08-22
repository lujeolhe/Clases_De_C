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
  int cont=0;
  printf("Dime a partir de que numero te digo los primos que hay \n" );
  scanf("%d",&n );
  int aux=n;
  printf("%d ",n );
  for(int i=0;i<n;i++){
    aux--;
    cont=0;
    for(int j=1;j<=aux;j++){
      if(aux%j==0){
        cont++;
      }
    }
    if(cont==2){
      printf("%d ",aux );
    }
  }
}
