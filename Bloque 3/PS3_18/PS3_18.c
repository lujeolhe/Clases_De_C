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
  printf("Dame un numero para hacer las piramides\n" );
  scanf("%d",&n );
  printf("\n" );
  for(int j=n;j>0;j--){
    for(int i=1;i<=n;i++){
      if(j>=i)
      printf("%d ",i );
    }
    for(int l=n;l>0;l--){
      if(l>=j)
      printf("    ");
    }
    for(int k=j;k>0;k--){
      printf("%d ", k);
    }
    printf("\n" );
  }
}
