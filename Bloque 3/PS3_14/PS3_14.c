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
  float aux_fac=1,cont=0,aux_posi=0,aux_nega=0,aux_fac2=1;
  float aux_valor_anterior=0;
  float resta=1;
  for(int i=1;resta>=0.001;i++){
      if(i==aux_fac2){
        aux_fac*=i;
        cont++;
      }
      else{
        aux_fac*=i;
      }
      if(i%2!=0){
        //if(aux_fac2<=n){
          if(cont==1){
            aux_posi=aux_posi+((pow(n,aux_fac2))/aux_fac);
              printf("+%d^%.0f/%.0f!",n,aux_fac2,aux_fac2 );
          }
          else{
              aux_nega=aux_nega-((pow(n,aux_fac2))/aux_fac);
              cont=0;
              printf("-%d^%.0f/%.0f!",n,aux_fac2,aux_fac2 );
          }
        //}
      aux_fac2=aux_fac2+2;
      }
      resta=fabs(aux_valor_anterior-aux_posi+aux_nega);
      aux_valor_anterior= aux_posi+aux_nega;
    }

  printf("=%.5f",aux_posi+aux_nega );
}
