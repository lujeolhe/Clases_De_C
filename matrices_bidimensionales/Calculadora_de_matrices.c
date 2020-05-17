///////////////////////////////////////
#include <stdio.h>
#include "operaciones_en_matrices.h"
///////////////////////////////////////

///////////////////////////////////////

///////////////////////////////////////
int main(){
  int abc=0;
  do{
      printf("Menu de la calculadora escoge alguna:\n" );
      printf("1.-Suma\n" );
      printf("2.-Resta\n" );
      printf("3.-multiplicacion\n" );
      printf("4.-Escalar\n");
      printf("5.-Determinante\n" );
      printf("6.-Salir\n" );
      scanf("%d",&abc );


      int matriz[3][valor_max];
      int matriz2[3][valor_max];
      int matriztotal[3][valor_max];
      int esc;
      int n=0;
      switch (abc) {

        case 1:


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
                printf("Introduce una segunda matriz\n" );
                for(int i=0;i<3;i++){
                  for(int j=0;j<3;j++){
                    scanf("%d",&matriz2[i][j] );
                    if(j<2){
                      scanf(" ");
                    }
                  }
                  if(i<2){
                    scanf("\n");
                  }
                }

                suma(matriz,matriz2,matriztotal,3,3);
                printf("\n" );
                imprimir_matriz(matriztotal,3,3);
                  printf("\n" );
                break;

  case 2:
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
                printf("Introduce tu matriz\n" );
                for(int i=0;i<3;i++){
                  for(int j=0;j<3;j++){
                    scanf("%d",&matriz2[i][j] );
                    if(j<2){
                      scanf(" ");
                    }
                  }
                  if(i<2){
                    scanf("\n");
                  }
                }
                resta(matriz,matriz2,matriztotal,3,3);
                printf("\n" );
                imprimir_matriz(matriztotal,3,3);
                  printf("\n" );
                break;
  case 3:
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
              printf("Introduce tu matriz\n" );
              for(int i=0;i<3;i++){
                for(int j=0;j<3;j++){
                  scanf("%d",&matriz2[i][j] );
                  if(j<2){
                    scanf(" ");
                  }
                }
                if(i<2){
                  scanf("\n");
                }
              }
              multiplicacion2(matriz,matriz2,matriztotal,3,3,3,3);
              printf("\n" );
              imprimir_matriz(matriztotal,3,3);
                printf("\n" );
              break;
  case 4:
              printf("Ingresa un numero\n" );
              scanf("%d",&esc );
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
              escalar(esc,matriz,matriztotal,3,3);
              printf("\n" );
              imprimir_matriz(matriztotal,3,3);
                printf("\n" );
              break;
  case 5:
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
            n=  determinante(3,matriz);
            printf("\n" );
              printf("%d\n",n );
                printf("\n" );
              break;
                default:
                printf("\n" );
                break;

      }
}while(abc!=6);
}
