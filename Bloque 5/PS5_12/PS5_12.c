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
void palindrome(int numeros[],int n);
void imprime_matriz(int numeros[],int n);
void inicializar(int numeros[],int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  int numeros[tam_max];
  printf("De cuantos numeros quieres tu arreglo\n" );
  scanf("%d",&n );
  if(n%2!=0){
  printf("Dame una serie de numeros y te dire si es un palindrome\n" );
  inicializar(numeros,n);
  palindrome(numeros,n);
  imprime_matriz(numeros,n);
  }
  else
  printf("El arreglo no es palindrome\n" );
}

void palindrome(int numeros[],int n){
  for(int i=0,j=n-1;i<n-3;i++,j--){
    if(numeros[i]==numeros[j]){
      if(i==1)
      printf("\nEl arreglo es palindrome\n" );
    }
    else if(i==0)
    printf("\nEl arreglo no es palindrome\n" );
  }

}

void imprime_matriz(int numeros[],int n){
  for(int i=0;  i<n ; i++){
    printf("%d ",numeros[i]);
  }
  printf("\n" );
}

void inicializar(int numeros[],int n){
  for(int i=0;i<n;i++){
    printf("Elemento [%d]: ",i );
    scanf("%d",&numeros[i] );
  }
}
