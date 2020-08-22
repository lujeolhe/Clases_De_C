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
  int n,m;
  int cont=0,cont_primo=0,aux_primo=0;
  printf("Dame un rango de numeros\n" );
  printf("De:" );
  scanf("%d",&n );
  printf("Hasta: " );
  scanf("%d",&m );
  int aux=n;
  printf("\nRango de (%d) hasta (%d)\n",n,m );
  for(int i=0;i<n;i++){
    if(aux!=m){
      aux--;
      cont=0;
      for(int j=1;j<=aux;j++){
        if(aux%j==0){
          cont++;
        }
      }
      if(cont==2){
        cont_primo++;
        if(cont_primo==1){
          aux_primo=aux;
        }
        else{
          printf("(%d,%d)",aux_primo,aux );
          cont_primo=0;
        }
      }
    }
  }
}
