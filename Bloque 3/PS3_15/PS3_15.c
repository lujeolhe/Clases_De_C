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
  int aux_num=0,aux2_num=1;
  printf("Dame dos numeros para decirte cual es su MCD\n" );
  printf("Primer numero:" );
  scanf("%d",&n );
  printf("Segundo numero:" );
  scanf("%d",&m );
  for(int i=2;i<=n&&i<=m;i++){
    if(n%i==0&&m%i==0){
      aux_num=i;
    }
    if(aux_num>aux2_num){
      aux2_num=aux_num;
    }
  }
  printf("El MCD de %d y %d es: %d\n",n,m,aux2_num );
}
