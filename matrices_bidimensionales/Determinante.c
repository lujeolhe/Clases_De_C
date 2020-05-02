///////////////////////////////////////
#include <stdio.h>
///////////////////////////////////////
#define valor_max 10
///////////////////////////////////////
void determinante(int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
///////////////////////////////////////
int main(){
  int matriz[2][valor_max],matriztotal[2][valor_max],aux=1;
  for(int i=0;i<2;i++){
    for(int j=0;j<2;j++){
      matriz[i][j]=aux;
      aux++;
    }
  }
  determinante(matriz,matriztotal,2,2);

  imprimir_matriz(matriz,2,2);
  printf("\n" );
  imprimir_matriz(matriztotal,2,2);

}
//////////////////////////////////////////////////////////
void imprimir_matriz(int matriz[][valor_max], int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n" );
  }
}

void determinante(int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
      for(int aux=0,aux2=0;aux2<tam_columna;aux2++){
        //aux=(matriz[i][aux2]*matriz[aux2][j])-(matriz[i][aux2]*matriz[aux2][j]);
        aux=(matriz[0][0]*matriz[0][1])-(matriz[1][0]*matriz[1][1]);
        matriztotal[i][j]=aux;
      }
    }
  }
}
