#include <stdio.h>
#include "operaciones_en_matrices.h"

int main(){
  int matriz[3][valor_max];
  int aux;
  for(int i=0;i<3;i++){
    for (int j = 0; j < 3; j++) {
      scanf("%d",&aux );
      if(j<2){
        scanf(",");
      }
      matriz[i][j]=aux;
    }
    scanf(";");
  }
  imprimir_matriz(matriz,3,3);
}
