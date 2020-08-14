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
int productoria(int n);
void principal();
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  principal();
}

int productoria(int n){
  int aux=1;
  for(int i=1;i<=n;i++){
    if(i==n){
      aux=aux*i;
      printf("%d= %d",i,aux );
    }
    else{
      aux=aux*i;
      printf("%d* ",i );
    }
  }
  printf("\n" );
  printf("La productoria es: %d\n",aux );
}

void principal(){
  int n;
  printf("Dime cual quieres que sea la productoria\n" );
  scanf("%d",&n );
  productoria(n);
}
