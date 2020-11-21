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
#define tam_max 30
/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void transpuesta(int mat[][tam_max],int fil, int col);
int inicializar_matriz(int mat[][tam_max],int fil, int col);
void imprime_matriz(int mat[][tam_max],int fil, int col);
void suma_matriz(int mat[][tam_max],int mat2[][tam_max],int fil, int col);
void inicializar_matriz_cero(int mat[][tam_max],int fil, int col);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int fil;
  int col;
  int mat[tam_max][tam_max];
  int mat2[tam_max][tam_max];
  printf("Dime cuantas filas y columnas quieres para tus matrices\n" );
  printf("Filas: " );
  scanf("%d",&fil );
  printf("\n" );
  printf("Columnas: " );
  scanf("%d",&col );
  printf("Dame los valores para la Matriz A\n");
  inicializar_matriz(mat,fil,col);
  printf("Dame los valores para la Matriz B\n");
  inicializar_matriz(mat2,fil,col);
  printf("Matriz A\n");
  imprime_matriz(mat,fil,col);
  printf("Matriz B\n");
  imprime_matriz(mat2,fil,col);
  printf("Matriz B Transpuesta\n");
  transpuesta(mat2,fil,col);
  suma_matriz(mat,mat2,fil,col);
}
/////////////////////////
//Funciones
/////////////////////////
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
void inicializar_matriz_cero(int mat[][tam_max],int fil, int col){
  for(int i=0; i<=fil-1 ; i++){
    for(int d=0; d<=col-1 ; d++){
      mat[i][d]=0;
    }
  }
}
void suma_matriz(int mat[][tam_max],int mat2[][tam_max],int fil, int col){
  int mat_res[tam_max][tam_max];
  inicializar_matriz_cero(mat_res,fil,col);
  for(int i=0;i<fil;i++){
    for(int j=0;j<col;j++){
      mat_res[i][j]=mat[i][j]+mat2[j][i];
    }
  }
  printf("Suma de Matrices A y Bt\n" );
  imprime_matriz(mat_res,fil,col);
}
