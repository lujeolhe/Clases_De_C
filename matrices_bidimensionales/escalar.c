///////////////////////////////////////
#include <stdio.h>
///////////////////////////////////////
#define valor_max 10
///////////////////////////////////////
void escalar(int n, int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
///////////////////////////////////////
int main(){
  int  matriz2[3][valor_max],matriztotal[3][valor_max],aux=1,n=3;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      matriz2[i][j]=aux;
      aux++;
    }
  }

  escalar(n,matriz2,matriztotal,3,3);

  printf("Numero escalar por una matriz\n  %d\n  x\n",n );
  imprimir_matriz(matriz2,3,3);
  printf("\n" );
  imprimir_matriz(matriztotal,3,3);
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
