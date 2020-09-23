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
void inicializar(int alumnos[],int n);
void promediar(int alumnos[],int n);
void porcentuar(int alumnos[],int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int numeros[tam_max];
  int n;
  printf("Dime cuantos alumnos fueron\n" );
  scanf("%d",&n );
  inicializar(numeros,n);
}
void inicializar(int alumnos[],int n){
  for(int i=0;i<n;i++){
    alumnos[i]=0;
  }
  for(int i=0;i<n;i++){
    alumnos[i]=rand()%600+1000;
  }
  for(int i=0;i<n;i++){
    printf("%d ",alumnos[i] );
  }
  promediar(alumnos,n);
  porcentuar(alumnos,n);
}
void promediar(int alumnos[],int n){
  float promedio=0;
  for(int i=0;i<n;i++){
    promedio+=(float)alumnos[i];
  }
  promedio=promedio/n;
  printf("\n\nEl promedio del grupo es: %.3f\n",promedio );
}
void porcentuar(int alumnos[],int n){
  int cont=0;
  int porcentaje=0;
  for(int i=0;i<n;i++){
    if(alumnos[i]>1300)
      cont++;
  }
  porcentaje=(cont*100)/n;
  printf("\nEl porcentaje de alumnos con calificacion mayor de 1300 es: %d\n",porcentaje );
  cont=0;
  for(int i=0;i<n;i++){
    if(alumnos[i]>=1500)
      cont++;
  }
  printf("\nNumero de alumnos con calificacion mayor o igual a 1500: %d\n",cont );
}
