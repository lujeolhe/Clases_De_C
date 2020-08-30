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
    for(int l=n;l>0&&l>=j;l--){
      printf("  ");
    }
    for(int i=1;i<=n&&j>=i;i++){
        //if(j>=i)
          printf("%d ",(i+j-1)%10 );
      }
    //if(j<=n){ //if inecesario poque j siempre es menor o igual que n
        for(int k=j-1;k>0;k--){
          printf("%d ", (k+j-1)%10);
        }
      //}
      printf("\n" );
    }
}
