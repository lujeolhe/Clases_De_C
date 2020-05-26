/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/////////////////////////
//Definiciones
/////////////////////////
#define __tiempo 2
#define __renglones 20
#define __columnas 20
/////////////////////////
//Funciones
/////////////////////////
void inicializar_matriz_3D(int a[][__renglones][__columnas]);
void imprimir_matriz(int a[][__renglones][__columnas]);
void dibujar_celdas(char a[__renglones][__columnas],int b[][__renglones][__columnas]);
void imprimir_celdas(char a[__renglones][__columnas]);
void inicializar_juego(int a[][__renglones][__columnas]);
void contar_vecinos(int a[][__columnas],int vecinos[][__columnas]);
/////////////////////////
//Main
/////////////////////////
int main(){
  srand (time(NULL)); //semilla
	int mapa[__tiempo][__renglones][__columnas];
  int matriz_de_vecinos[__renglones][__columnas];
  char celdas[__renglones][__columnas];
  inicializar_matriz_3D(mapa);
  inicializar_juego(mapa);
  imprimir_matriz(mapa);

  dibujar_celdas(celdas,mapa);
  imprimir_celdas(celdas);


}
void inicializar_matriz_3D(int a[][__renglones][__columnas]){

  for(int tiempo=0;tiempo<__tiempo;tiempo++){
    for(int renglon=0;renglon<__renglones;renglon++){
      for(int columna=0;columna<__columnas;columna++){
        a[tiempo][renglon][columna]=0;
      }
    }
  }
}
void imprimir_matriz(int a[][__renglones][__columnas]){
  for(int tiempo=0;tiempo<__tiempo;tiempo++){
    for(int renglon=0;renglon<__renglones;renglon++){
      for(int columna=0;columna<__columnas;columna++){
        printf("%d ",a[tiempo][renglon][columna]);
      }
      printf("\n");
    }
    printf("\n");
  }
}

void dibujar_celdas(char a[__renglones][__columnas],int b[][__renglones][__columnas]){
  for(int renglon=0;renglon<__renglones;renglon++){
    for(int columna=0;columna<__columnas;columna++){
      if(b[0][renglon][columna]==0)
        a[renglon][columna]='*';
      else
        a[renglon][columna]='O';
    }
  }
}
void imprimir_celdas(char a[__renglones][__columnas]){
  for(int renglon=0;renglon<__renglones;renglon++){
    for(int columna=0;columna<__columnas;columna++){
      printf("%c ",a[renglon][columna]);
    }
    printf("\n");
  }
  printf("\n");
}

void inicializar_juego(int a[][__renglones][__columnas]){
  for(int renglon=0;renglon<__renglones;renglon++){
    for(int columna=0;columna<__columnas;columna++){
      a[0][renglon][columna]=rand()%2;
    }
  }
}
void contar_vecinos(int a[][__columnas],int vecinos[][__columnas]){
  for(int i=0;i<__renglones;i++){
    for(int j=0;j<__columnas;j++){
      if(i==j&&i==0){
        vecinos[i][j]=a[i][j+1]+a[i+1][j+1]+a[i+1][j];
      }
      else if(i==j&&i==__columnas){
        vecinos[i][j]=a[i][j-1]+a[i-1][j-1]+a[i-1][j];
      }
      else{
        vecinos[i][j]=a[i-1][j-1]+a[i-1][j]+a[i-1][j+1]+
                      a[i][j-1]+a[i][j+1]+
                      a[i+1][j-1]+a[i+1][j]+a[i+1][j+1];
      }
    }
  }
}
