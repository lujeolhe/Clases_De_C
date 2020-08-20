////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
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
  printf("dame el valor de x para el seno(x)\n" );
  scanf("%d",&n);
  printf("Seno(%d)= ",n );
  int aux_fac=1,cont=0,aux_posi=0,aux_nega=0,aux_fac2=1;
  for(int i=1;i<=n;i++){
      if(i==aux_fac2){
        aux_fac*=i;
        cont++;
      }
      else{
        aux_fac*=i;
      }
      if(i%2!=0){
        if(aux_fac2<=n){
          if(cont==1){
            aux_posi=aux_posi+((pow(aux_fac2,aux_fac2))/aux_fac);
              printf("+%d^%d/%d!",aux_fac2,aux_fac2,aux_fac2 );
          }
          else{
              aux_nega=aux_nega-((pow(aux_fac2,aux_fac2))/aux_fac);
              cont=0;
              printf("-%d^%d/%d!",aux_fac2,aux_fac2,aux_fac2 );
          }
        }
      aux_fac2=aux_fac2+2;
      }
    }
  printf("=%d",aux_posi+aux_nega );
}
