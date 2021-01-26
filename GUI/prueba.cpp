#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "AmbitoBoton.hpp"
using namespace std;
namespace WIN32API{
int aleatorio(int aux[]);
int main(){
  srand(time(NULL));
  static int aux[11];
  for(int i=0;i<10;i++){
    int alea=rand()%10;
    aux[i]=alea;
  }
  printf("Antes\n");
  for(int i=0;i<10;i++){
    printf("Valores de aux: %d\n",aux[i]);
  }
  printf("\n\n");
  aleatorio(aux);
}
int aleatorio(int aux[]){
  int aux_fun[11];
  printf("Despues\n");
  for(int i=0;i<10;i++){
    printf("Valores de aux: %d\n",aux[i]);
  }
  printf("\n\n");
  for(int i=0;i<10;i++){
    aux_fun[i]=i;
  }
  for(int i=0;i<10;i++){
    if(aux_fun[i]==aux[i]){
      printf("Este valor es igual aux_fun: %d y aux: %d\n",aux_fun[i],aux[i]);
    }
    else{
      printf("Este valor no es igual aux_fun: %d y aux: %d\n",aux_fun[i],aux[i]);
    }
  }
}
}
