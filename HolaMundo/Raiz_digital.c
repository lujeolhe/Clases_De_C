/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include <math.h>
#include<time.h>
#include<stdlib.h>
/////////////////////////
//Funciones
/////////////////////////
int potencia(int base, int exponente);
int sumaraices(int n);
int mide(int n);
int voltear(int n);
void ensena_sumaraices(int n);
void muestra(int n);
void rangos(int inferior, int superior);
void funcion_principal();
void fecha_hora(char *a, int tam_);
/////////////////////////
//Main
/////////////////////////
FILE *archivodetexto;
int main(){
  archivodetexto=fopen("logs.log", "a+");
  char output[30];
  fecha_hora(output,30);
  fprintf(archivodetexto,"***********************************************\n" );
  fprintf(archivodetexto, "Se inicializo el programa %s\n",output);
  funcion_principal();
  return 1;
}
/////////////////////////
int potencia(int base, int exponente){
  int aux=1;
  for(int aux_mult=1;aux_mult<=exponente;aux_mult++){
    aux=aux*base;
  }
  return aux;
}
int mide( int n){

  for(int cuenta=0;;){
    //printf("entre al ciclo for\n");
    switch (n>0){
      case 0:
        return cuenta;

      case 1:
        cuenta++;
        n/=10;
    }
  }
}
int sumaraices(int n){
  int ciclos=1, total=0;
  while(ciclos){
    //printf("entre al ciclo while\n");
    total+=n%10;
    //printf("%d\n",total );
    n/=10;
  //  printf("%d\n",n );
    (n==0)? (ciclos=0): (ciclos=1);
  }
  return total ;

}

int voltear(int n){
  int aux=0, aux_mide=mide(n)-1;
  do{
    fprintf(archivodetexto, "En la funcion voltear el valor de aux es:%d\n",aux );
    fprintf(archivodetexto, "En la funcion voltear el valor de aux_mide es:%d\n",aux_mide);
    if(n>0){
      aux+=(n%10)*potencia(10,aux_mide);
      fprintf(archivodetexto, "En la funcion voltear el valor de aux es:%d,el pow da: %d, la multiplicacion da: %d\n",aux,(float)1*powl(10,2),(n%10)*potencia(10,2) );
      printf("valor de aux=%d\n",aux );
      aux_mide--;
      n/=10;
      //printf("valor de n=%d\n",n );
    }
    else{
      printf("valor de voltear=%d\n",aux );
      fprintf(archivodetexto, "El nuevo valor de aux es:%d\n",aux );
      return aux;

    }
  }while(1);
}

void ensena_sumaraices(int n){

  for(int aux=voltear(n);;){
    fprintf(archivodetexto, "En la funcion ensena_sumaraices el valor de aux es:%d\n",aux );
    switch (aux>=10) {
      case 1:
        printf("%d + ",aux%10 );
        aux/=10;
        break;

      default:
        printf("%d = %d\n",aux, sumaraices(n) );
        fprintf(archivodetexto, "El nuevo valor de aux es:%d\n",aux );
        return;
    }
  }
}

void muestra(int n){
  do{
    fprintf(archivodetexto, "En la funcion muestra el valor de n es:%d\n",n );
    switch (n>0) {
      case 1:
        ensena_sumaraices(n);
        n=sumaraices(n);
        fprintf(archivodetexto, "El nuevo valor de n es:%d\n",n );
        switch (n<10) {
          case 1:
            return;
            break;
        }
      default:
        break;
    }
  }while(1);
}

void rangos(int inferior, int superior){
  while(inferior<=superior){
    switch (1) {
      case 1:
        printf("Raiz digital(%d)\n",inferior );
        muestra(inferior);
        break;
    }
    inferior++;
  }
}
void fecha_hora(char *a, int tam_){
  time_t tiempo = time(0);
  struct tm *tlocal = localtime(&tiempo);
  strftime(a,tam_,"%d/%m/%y %H:%M:%S",tlocal);

}
void funcion_principal(){
  int n;
  printf("dame un numero\n");
  scanf("%d",&n );
  fprintf(archivodetexto, "Se ingreso el numero: %d\n",n );
  muestra(n);
  char output[30];
  fecha_hora(output,30);
  printf("%s\n",output );
  printf("-------------------------------------------------------------------\n" );
}
