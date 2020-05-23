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
#define __renglones 10
#define __columnas 10
/////////////////////////
//Funciones
/////////////////////////
void inicializar_matriz_3D(int a[][__renglones][__columnas]);
void imprimir_matriz(int a[][__renglones][__columnas]);
void dibujar_celdas(char a[__renglones][__columnas],int b[][__renglones][__columnas]);
void imprimir_celdas(char a[__renglones][__columnas]);
void inicializar_juego(int a[][__renglones][__columnas]);
void vecinos_vivos(int a[][__renglones][__columnas],int vecinos[__renglones][__columnas]);
void imprimir_matriz_2D(int a[__renglones][__columnas]);
void siguiente_futuro(int a[][__renglones][__columnas],int vecinos[__renglones][__columnas]);
void actualizar_estado(int a[][__renglones][__columnas]);
/////////////////////////
//Main
/////////////////////////
int main(){
  srand (time(NULL)); //semilla
	int mapa[__tiempo][__renglones][__columnas];
  char celdas[__renglones][__columnas];
  int vecindad[__renglones][__columnas];
  inicializar_matriz_3D(mapa);
  inicializar_juego(mapa);
  for(int i=1;i<=10;i++){
    vecinos_vivos(mapa,vecindad);
    siguiente_futuro(mapa,vecindad);
    dibujar_celdas(celdas,mapa);
    imprimir_celdas(celdas);
    actualizar_estado(mapa);
  }
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

void vecinos_vivos(int a[][__renglones][__columnas],int vecinos[__renglones][__columnas]){
  for(int renglon=0;renglon<__renglones;renglon++){
    for(int columna=0;columna<__columnas;columna++){
      if(renglon==0&&columna==0){
        vecinos[renglon][columna]=a[0][0][1]+a[0][1][0]+a[0][1][1];
      }
      else if(renglon==0&&columna==__columnas-1){
        vecinos[renglon][columna]=a[0][0][columna-1]+a[0][1][columna]+a[0][1][columna-1];
      }
      else if(renglon==__renglones-1&&columna==0){
        vecinos[renglon][columna]=a[0][renglon][1]+a[0][renglon-1][0]+a[0][renglon-1][1];
      }
      else if(renglon==__renglones-1&&columna==__columnas-1){
        vecinos[renglon][columna]=a[0][renglon][columna-1]+a[0][renglon-1][columna-1]+a[0][renglon-1][columna];
      }
      else if(renglon==0&&(columna>=1&&columna<__columnas-1)){
        vecinos[renglon][columna]=a[0][renglon+1][columna-1]+a[0][renglon+1][columna]+a[0][renglon+1][columna+1]+a[0][renglon][columna-1]+a[0][renglon][columna+1];
      }
      else if(renglon==__renglones-1&&(columna>=1&&columna<__columnas-1)){
        vecinos[renglon][columna]=a[0][renglon-1][columna-1]+a[0][renglon-1][columna]+a[0][renglon-1][columna+1]+a[0][renglon][columna-1]+a[0][renglon][columna+1];
      }
      else if((renglon<__renglones-1&&renglon>=1)&&columna==0){
        vecinos[renglon][columna]=a[0][renglon-1][columna]+a[0][renglon+1][columna]+a[0][renglon-1][columna+1]+a[0][renglon][columna+1]+a[0][renglon+1][columna+1];
      }
      else if((renglon<__renglones-1&&renglon>=1)&&columna==__columnas-1){
        vecinos[renglon][columna]=a[0][renglon-1][columna]+a[0][renglon+1][columna]+a[0][renglon-1][columna-1]+a[0][renglon][columna-1]+a[0][renglon+1][columna-1];
      }
      else{
        vecinos[renglon][columna]=a[0][renglon-1][columna]+a[0][renglon-1][columna-1]+a[0][renglon-1][columna+1]+a[0][renglon][columna+1]+a[0][renglon][columna-1]
        +a[0][renglon+1][columna+1]+a[0][renglon+1][columna]+a[0][renglon+1][columna-1];
        }
      }
    }
  }

  void imprimir_matriz_2D(int a[__renglones][__columnas]){
      for(int renglon=0;renglon<__renglones;renglon++){
        for(int columna=0;columna<__columnas;columna++){
          printf("%d ",a[renglon][columna]);
        }
        printf("\n");
      }
      printf("\n");
  }

void siguiente_futuro(int a[][__renglones][__columnas],int vecinos[__renglones][__columnas]){
  for(int renglon=0;renglon<__renglones;renglon++){
    for(int columna=0;columna<__columnas;columna++){
      if(a[0][renglon][columna]==1&&(vecinos[renglon][columna]==2||vecinos[renglon][columna]==3)){
        a[1][renglon][columna]=1;
      }
      else if(a[0][renglon][columna]==1&&(vecinos[renglon][columna]<2&&vecinos[renglon][columna]>3)){
        a[1][renglon][columna]=0;
      }
      else if(a[0][renglon][columna]==0&&vecinos[renglon][columna]==3){
        a[1][renglon][columna]=1;
      }
      else{
        a[1][renglon][columna]=0;
      }
    }
  }
}

void actualizar_estado(int a[][__renglones][__columnas]){
  for(int renglon=0;renglon<__renglones;renglon++){
    for(int columna=0;columna<__columnas;columna++){
      a[0][renglon][columna]=a[1][renglon][columna];
    }
  }
}
