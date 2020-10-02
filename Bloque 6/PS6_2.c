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
void inicializar_matriz(int montos[][tam_max],int n,int m);
void mes(int mes);
int mayor_monto(int montos[][tam_max],int n);
void menores_montos(int montos[][tam_max],int m);
void montos_anuales(int montos[][tam_max],int n,int m,int k);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int n=5,m=12;
  int montos[tam_max][tam_max];
  inicializar_matriz(montos,n,m);
  mayor_monto(montos,n);
  menores_montos(montos,m);
  return 0;
}
/////////////////////////
//Funciones
/////////////////////////
void inicializar_matriz(int montos[][tam_max],int n,int m){
  for(int j=0;j<n;j++){
    for(int i=0;i<m;i++){
      montos[j][i]=rand()%50;
    }
  }
  for(int j=0;j<n;j++){
    printf("Departamento %d\n",j+1 );
    printf("Motos por mes:\n" );
    for(int i=0;i<m;i++){
      printf("%d ",montos[j][i] );
    }
    montos_anuales(montos,n,m,j);
    printf("\n" );
  }
}

void montos_anuales(int montos[][tam_max],int n,int m,int k){
  int aux[tam_max];
  for(int i=0;i<5;i++){
    aux[i]=0;
  }
  for(int j=0;j<n;j++){
    for(int i=0;i<m;i++){
      aux[j]+= montos[j][i];
    }
  }
  printf("\nEl monto anual es: %d\n",aux[k]/12);
}

int mayor_monto(int montos[][tam_max],int n){
  static int cont=0;
  int aux_mes=0;
  if(cont==0){
  int aux=0,j=6;
  aux=montos[0][j];
  for(int i=1;i<n;i++){
    if(aux>montos[i][j]){
      aux_mes=i-1;
    }
    else{
      aux=montos[i][j];
      aux_mes=i-1;
    }
  }
    printf("El Departamento con mayor venta en Julio es: %d y su moto es: %d\n",aux_mes,aux );
    cont++;
  }

  aux_mes=0;
  int aux=0,i=2;
  aux=montos[i][0];
  for(int j=1;j<n;j++){
    if(aux>montos[i][j]){}

    else{
      aux=montos[i][j];
      aux_mes=j;
    }
  }
  return aux_mes;
}

void menores_montos(int montos[][tam_max],int m){
  int i=2;
  int aux_may=0,aux_men=0,aux_mes=0;
  aux_may=mayor_monto(montos,m);
  for(int j=0;j<m;j++){
    if(montos[i][j]<montos[i][j+1]&&j+1<m){
      aux_men=montos[i][j];
      aux_mes=j;
    }
    else{
      aux_men=montos[i][j+1];
      aux_mes=j+1;
    }

  }
  printf("\nEn el Departamento 3\n" );
  printf("El mes con mayores ventas es: " );
  mes(aux_may);
  printf("\nEl mes con menores ventas es: " );
  mes(aux_mes-1);
  printf("\n" );
}

void mes(int k){
  switch (k) {
    case 0:
    printf("Enero");
    break;
    case 1:
    printf("Febrero");
    break;
    case 2:
    printf("Marzo");
    break;
    case 3:
    printf("Abril");
    break;
    case 4:
    printf("Mayo");
    break;
    case 5:
    printf("Junio");
    break;
    case 6:
    printf("Julio");
    break;
    case 7:
    printf("Agosto");
    break;
    case 8:
    printf("Septiembre");
    break;
    case 9:
    printf("Octubre");
    break;
    case 10:
    printf("Noviembre");
    break;
    case 11:
    printf("Diciembre");
    break;
    default:
    break;
  }
}
