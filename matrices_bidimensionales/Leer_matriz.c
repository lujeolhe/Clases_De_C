///////////////////////////////////////
#include <stdio.h>
#include "operaciones_en_matrices.h"
///////////////////////////////////////
//#define valor_maximo 10
///////////////////////////////////////

///////////////////////////////////////
int main(){
  int matriz[3][valor_max];

  printf("Introduce tu matriz\n" );
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      scanf("%d",&matriz[i][j] );
      if(j<2){
        scanf(" ");
      }
    }
    if(i<2){
      scanf("\n");    
    }
  }

  imprimir_matriz(matriz,3,3);
}
