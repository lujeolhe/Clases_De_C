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
void inicializar(int cosecha[],int n);
void promediar_anual(int cosecha[],int n);
void comparar(int cosecha[],int n,float promedio);
void ordenador(int numeros[],int n);
void meses(int k);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int cosecha[tam_max];
  int n=12;
  inicializar(cosecha,n);
}
void inicializar(int cosecha[],int n){
  for(int i=0;i<n;i++){
    cosecha[i]=0;
  }
  for(int i=0;i<n;i++){
    cosecha[i]=rand()%30;
  }
  printf("Cosechas por mes:\n" );
  for(int i=0;i<n;i++){
    printf("%d ",cosecha[i] );
  }
  promediar_anual(cosecha,n);
}

void promediar_anual(int cosecha[],int n){
  float promedio=0;
  for(int i=0;i<n;i++){
    promedio+=(float)cosecha[i];
  }
  promedio=promedio/n;
  printf("\n\nEl promedio anual es: %.2f\n",promedio );
  comparar(cosecha,n,promedio);
}

void comparar(int cosecha[],int n,float promedio){
  int cont=0;
  for(int i=0;i<n;i++){
    if(cosecha[i]<promedio)
      cont++;
  }
  printf("\nFueron %d los meses con cosechas superiores al promedio\n",cont );
  ordenador(cosecha,n);
}
void ordenador(int numeros[],int n){
  int k=0,i;
    for( i=1;i<n;i++){
      if(numeros[k]>numeros[i])
        k=k;
      else{
        k=i;
      }
    }
  printf("\nEl mes con mas toneladas fue ");
  meses(k);
  printf(" con %d toneladas\n",numeros[k] );
}

void meses(int k){
  switch (k+1) {
    case 1:
    printf("Enero");
    break;
    case 2:
    printf("Febrero");
    break;
    case 3:
    printf("Marzo");
    break;
    case 4:
    printf("Abril");
    break;
    case 5:
    printf("Mayo");
    break;
    case 6:
    printf("Junio");
    break;
    case 7:
    printf("Julio");
    break;
    case 8:
    printf("Agosto");
    break;
    case 9:
    printf("Septiembre");
    break;
    case 10:
    printf("Octubre");
    break;
    case 11:
    printf("Noviembre");
    break;
    case 12:
    printf("Diciembre");
    break;
    default:
    break;
  }
}
