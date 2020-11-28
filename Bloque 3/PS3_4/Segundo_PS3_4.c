////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 100
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
  srand(time(NULL));
  int n,numeros=0;
  printf("Dime Cuantos numeros quieres \n" );
  scanf("%d",&n );
  int cont_posi=0,cont_nega=0,cont_nulo=0;
  for(int i=0;i<n;i++){
    numeros=rand()%50-25;
    printf("%d ",numeros );
    if(numeros>0){
      cont_posi++;
    }
    if(numeros<0){
      cont_nega++;
    }
    else if(numeros==0){
      cont_nulo++;
    }
  }
  printf("\n\nSon %d numeros positivos\n",cont_posi );
  printf("Son %d numeros negativos\n",cont_nega );
  printf("Son %d numeros nulos\n",cont_nulo );
}
