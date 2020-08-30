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
  float aux_fac=1,cont=0,aux_posi=0,aux_nega=0,aux_fac2=1,resta=0;
  for(int i=1;;i++){
    if(resta<0.000017||resta==0.000017){
      if(i==aux_fac2){
        aux_fac*=i;
        cont++;
      }
      else{
        aux_fac*=i;
      }
      if(i%2!=0){
          if(cont==1){
            aux_posi=aux_posi+((pow(n,aux_fac2))/aux_fac);
              printf("+%d^%.0f/%.0f!",n,aux_fac2,aux_fac2 );
          }
          else{
              aux_nega=aux_nega-((pow(n,aux_fac2))/aux_fac);
              cont=0;
              printf("-%d^%.0f/%.0f!",n,aux_fac2,aux_fac2 );
          }
      aux_fac2=aux_fac2+2;
      }

    }
    resta=aux_posi-aux_nega;
  }

  printf("=%.8f",resta );
}
