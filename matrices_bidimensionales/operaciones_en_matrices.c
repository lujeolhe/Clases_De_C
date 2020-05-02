#include <stdio.h>
#include <math.h>
//#include "operaciones_en_matrices.h"
/////////////////////////////////
#define valor_max 10
void suma(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
        matriztotal[i][j]=matriz[i][j]+matriz2[i][j];
    }

  }
}

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

void escalar(int n,int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
        matriztotal[i][j]=n*matriz[i][j];
    }

  }
}

int determinante(int dimension,int matriz[][valor_max]){
  if(dimension==1)
    return matriz[0][0];
  else{
    int aux=0;

    for(int i=1;i<=dimension;i++){
      int matrizAux[dimension-1][ valor_max];
      for(int j=1;j<=dimension;j++){
        for(int k=1;k<=dimension;k++){
          if(i==1){
					 matrizAux[j-1][k-1]=matriz[j][k];
          }
			      else if(i==dimension){
					 matrizAux[j-1][k-1]=matriz[j][k-1];
            }
			      else{
				       int a=0;
					     if(k>=i){
				        a=1;
					      }
				      matrizAux[j-1][k-1]=matriz[j][k-1+a];
            }
          }
        }
        aux=aux+pow(-1,1+i)*matriz[0][i-1]*determinante(dimension-1, matrizAux);
      }
      return aux;
    }
}

void imprimir_matriz(int matriz[][valor_max], int tam_renglon,int tam_columna){
  for(int i=0;i<tam_renglon;i++){
    for(int j=0;j<tam_columna;j++){
      printf("%d ",matriz[i][j]);
    }
    printf("\n" );
  }
}
