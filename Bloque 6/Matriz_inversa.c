////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
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
void transpuesta(int mat[][tam_max],int fil, int col);
void imprime_matriz(int mat[][tam_max],int fil, int col);
void imprime_matriz_flotante(float mat[][tam_max],int fil, int col);
int inicializar_matriz(int mat[][tam_max],int fil, int col);
int determinante(int dimension,int matriz[][tam_max]);
void obtener_cofactores(int mat[][tam_max],int mat_cof[][tam_max],int fil,int col);
void matriz_inversa(float mat_inver[][tam_max],int mat[][tam_max],int fil,int col);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int mat[tam_max][tam_max];
  float mat_inver[tam_max][tam_max];
  printf("Dame los valores de tu matriz\n" );
  inicializar_matriz(mat,3,3);
  printf("Esta es la matriz ingresada\n" );
  imprime_matriz(mat,3,3);
  matriz_inversa(mat_inver,mat,3,3);
}
void transpuesta(int mat[][tam_max],int fil, int col){
  int i=0,d=0;
  for(; i<=fil-1 ; i++){
    for(; d<=col-1 ; d++){
      printf("%d ",mat[d][i] );
    }
    d=0;
    printf("\n");
  }
}
void imprime_matriz(int mat[][tam_max],int fil, int col){
  int i=0;
    int d=0;
  for( ; i<=fil-1 ; i++){
    for( ; d<=col-1 ; d++){
      printf("%d ",mat[i][d]);
  }
    d=0;
    printf("\n");
  }
}
void imprime_matriz_flotante(float mat[][tam_max],int fil, int col){
  int i=0;
    int d=0;
  for( ; i<=fil-1 ; i++){
    for( ; d<=col-1 ; d++){
      printf("%f ",mat[i][d]);
  }
    d=0;
    printf("\n");
  }
}

int inicializar_matriz(int mat[][tam_max],int fil, int col){
  int d;
  int i;
  for(i=0; i<=fil-1 ; i++){
    for(d=0; d<=col-1 ; d++){
      printf("Matriz[%d][%d]=",i,d );
      scanf("%d",&mat[i][d]);
    }
  }
  return mat[i][d];
}
int determinante(int dimension,int matriz[][tam_max]){
  if(dimension==1)
    return matriz[0][0];
  else{
    int aux=0;
    for(int i=1;i<=dimension;i++){
      int matrizAux[dimension-1][ tam_max];
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
void obtener_cofactores(int mat[][tam_max],int mat_cof[][tam_max],int fil,int col){
  int  mat_aux[fil-1][tam_max];
//  int i,j,k,l;
  for(int i=0;i<fil;i++){
    for(int j=0;j<col;j++){
      if(i==0||i==2){
        for(int k=0;k<fil-1;k++){
          for(int l=0;l<col-1;l++){
            if(j==0||j==2)
              mat_aux[k][l]=mat[(i+1+k)%3][(j+1+l)%3];
            else
              mat_aux[k][l]=mat[(i+1+k)%3][(j*2+l*2+1)%3];
          }
        }
      }
     else{
       for(int k=0;k<fil-1;k++){
         for(int l=0;l<col-1;l++){
            if(j==0||j==2)
              mat_aux[k][l]=mat[(i*2+k*2+1)%3][(j+1+l)%3];
            else
              mat_aux[k][l]=mat[(i*2+k*2+1)%3][(j*2+l*2+1)%3];
          }
        }
      }
      mat_cof[i][j]=pow(-1,i+j)*determinante(2,mat_aux);
    }
  }
  printf("Esta es la Matriz Adjunta\n" );
  imprime_matriz(mat_cof,fil,col);
}
void matriz_inversa(float mat_inver[][tam_max],int mat[][tam_max],int fil,int col){
  int matriz_adj[fil][tam_max];
  obtener_cofactores(mat,matriz_adj,3,3);
  printf("Esta es la matriz transpuesta\n" );
  transpuesta(matriz_adj,3,3);
  int det=determinante(3,mat);
  printf("Este es el valor del determinante: %d\n",det );
  for(int i=0;i<fil;i++){
    for(int j=0;j<col;j++){
    //printf("multiplicacion %f y division %f \n", (float)(1/det)*(float)(matriz_adj[i][j]),(1/(float)det));
      mat_inver[i][j]=(1/(float)det)*(matriz_adj[i][j]);
    }
  }
  printf("Esta es la matriz inversa\n" );
  imprime_matriz_flotante(mat_inver,3,3);
}
