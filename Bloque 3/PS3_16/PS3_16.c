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
   printf("\n" );
 }
 for(int j=n-1;j>=0;j--){
   for(int i=1;i<n;i++){
     if(j>=i)
     printf("%d ",i );
   }
   printf("\n" );
 }
}
