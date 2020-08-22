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
  printf("Dame un numero para hacer la piramide\n" );
  scanf("%d",&n );
  printf("\n" );
  for(int j=1;j<=n;j++){
    for(int i=1;i<=n;i++){
        if(j>=i)
          printf("%d ",i );
      }
      if(j<=n){
        for(int k=j-1;k>0;k--){
          printf("%d ", k);
        }
      }
      printf("\n" );
    }
}
