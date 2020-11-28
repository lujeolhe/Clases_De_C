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
  int numeros[tam_max];
  int n;
  printf("Dime cuantos numeros naturales quieres\n" );
  scanf("%d",&n );

  int cont_posi=0,cont_nega=0,cont_nulo=0;
  for(int i=0;i<n;i++){
    numeros[i]=0;
  }


  for(int i=0;i<n;i++){
    numeros[i]=rand()%50-25;
  }

  for(int i=0;i<n;i++){
    printf("%d ",numeros[i] );
  }

  printf("\n" );
  for(int i=0;i<n;i++){
    if(numeros[i]>0){
      cont_posi++;
    }
    else if(numeros[i]<0){
      cont_nega++;
    }
  }

  for(int i=0;i<n;i++){
    if(numeros[i]==0)
      cont_nulo++;
  }
printf("Son %d numeros positivos\n",cont_posi );
printf("Son %d numeros negativos\n",cont_nega );
printf("Son %d numeros nulos\n",cont_nulo );
}
