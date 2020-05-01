///////////////////////////////////////
#include <stdio.h>
///////////////////////////////////////
#define valor_max 10
///////////////////////////////////////
void multiplicacion(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2);
void multiplicacion2(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2);
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
///////////////////////////////////////
int main(){
  int matriz2[3][valor_max],matriztotal[3][valor_max],matriztotal2[3][valor_max],aux=1;
  for(int i=0;i<2;i++){
    for(int j=0;j<3;j++){
      matriz2[i][j]=aux;
      aux++;
    }
  }

  int matriz[3][valor_max];
  aux=1;
  for(int i=0;i<3;i++){
    for(int j=0;j<2;j++){
      matriz[i][j]=aux;
      aux++;
    }
  }

  multiplicacion(matriz2,matriz,matriztotal,2,3,3,2);

  multiplicacion2(matriz2,matriz,matriztotal2,2,3,3,2);

  imprimir_matriz(matriz2,2,3);
  printf("\n" );
  imprimir_matriz(matriz,3,2);
  printf("\n" );
  imprimir_matriz(matriztotal,2,2);
  printf("\n" );
  imprimir_matriz(matriztotal2,2,2);
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
//////////////Para multiplicaciones que decidamos/////////////////////
void multiplicacion(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2){
  for(int i=0;i<tam_renglon&&i<tam_columna2;i++){
    for(int j=0;j<tam_columna&&j<tam_renglon2;j++){
      if(tam_columna==tam_renglon2){
        matriztotal[i][j]=(matriz[i][0]*matriz2[0][j])+(matriz[i][1]*matriz2[1][j])+(matriz[i][2]*matriz2[2][j]);

      }
      else{
        printf("Las matrices no son conformables\n" );
      }
    }
  }
}
//////////////////////////para multiplicaciones de n numeros////////////////////////7
void multiplicacion2(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2){
  for(int i=0;i<tam_renglon&&i<tam_columna2;i++){
    for(int j=0;j<tam_columna&&j<tam_renglon2;j++){
      for(int aux=0,aux2=0;aux2<tam_columna;aux2++){
        if(tam_columna==tam_renglon2){

        aux=aux+matriz[i][aux2]*matriz2[aux2][j];
        matriztotal[i][j]=aux;
        }
        else{
        printf("Las matrices no son conformables\n" );
        }
      }
    }
  }
}
