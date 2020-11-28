////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  char mes[12][30]={"Enero", "Febrero", "Marzo", "Abril","Mayo","Junio","Julio","Agosto","Septiembre","Octubre","Noviembre","Diciembre"};
  int n[12][30];
  for(int i=0;i<12;i++){
    for(int j=0;j<30;j++){
      n[i][j]=0;
    }
  }
  for(int i=0;i<12;i++){
    for(int j=0;j<30;j++){
      n[i][j]=rand()%2;
    }
  }
  for(int i=0;i<12;i++){
    for(int j=0;j<30;j++){
      printf("%c\t",mes[i][j] );
      printf("%d\n",n[i][j] );
    }

    printf("\n" );
  }
/*  for(int i=0;i<10;i++){
    for(int j=0;j<30;j++){
      printf("%c",mes[i][j] );
    }
    printf("\n" );
  }*/
}
