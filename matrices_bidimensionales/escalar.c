///////////////////////////////////////
#include <stdio.h>
///////////////////////////////////////
#define valor_max 10
///////////////////////////////////////
void escalar(int n, int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
///////////////////////////////////////
int main(){
  int  matriz2[4][valor_max],matriztotal[4][valor_max],aux=1,n=3;
  for(int i=0;i<4;i++){
    for(int j=0;j<4;j++){
      matriz2[i][j]=aux;
      aux++;
    }
  }

  escalar(n,matriz2,matriztotal,4,4);

  printf("Numero escalar por una matriz\n  %d\n  x\n",n );
  imprimir_matriz(matriz2,4,4);
  printf("\n" );
  imprimir_matriz(matriztotal,4,4);
  return 1;
}
///////////////////////////////////////
void imprimir_matriz(int matriz[][valor_max], int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n" );
  }
}

void escalar(int n,int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
        matriztotal[i][j]=n*matriz[i][j];
    }

  }
}
