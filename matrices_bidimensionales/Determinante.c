///////////////////////////////////////
#include <stdio.h>
#include <math.h>
///////////////////////////////////////
#define valor_max 10
///////////////////////////////////////
int determinante(int dimension,int matriz[][valor_max]);
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
///////////////////////////////////////
int main(){
  int matriz[3][valor_max],aux=1;
  for(int i=0;i<3;i++){
    for(int j=0;j<3;j++){
      matriz[i][j]=aux;
      aux++;
    }
  }
  int valor=determinante(3,matriz);

  imprimir_matriz(matriz,3,3);
  printf("\n" );
  printf("Este es el determinante de la matriz=%d\n",valor );

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
