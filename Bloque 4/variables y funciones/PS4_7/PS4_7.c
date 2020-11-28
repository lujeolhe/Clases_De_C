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

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
int primo(int n);
void es_primo(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  printf("Dame un numero y te digo si es un numero primo\n" );
  scanf("%d",&n );
  es_primo(n);
  return 0;
}

int primo(int n){
  int cont=0;
  for(int j=1;j<=n;j++){
    if(n%j==0)
      cont++;
  }
  if(cont==2)
    return 1;
  else
    return 0;
}

void es_primo(int n){
  if(primo(n))
    printf("El numero %d es primo\n",n );
    else
    printf("El numero %d no es primo\n",n );
}
