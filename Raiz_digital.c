/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include <math.h>
/////////////////////////
//Funciones
/////////////////////////
int sumaraices(int n);
int mide(int n);
int voltear(int n);
void ensena_sumaraices(int n);
void muestra(int n);
void rangos(int inferior, int superior);
void funcion_principal();
/////////////////////////
//Main
/////////////////////////
int main(){
  funcion_principal();
  return 1;
}
/////////////////////////
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
    if(n>0){
      aux+=(n%10)*powl(10,aux_mide);
      //printf("valorr de aux=%d\n",aux );
      aux_mide--;
      n/=10;
      //printf("valor de n=%d\n",n );
    }
    else{
      //printf("valor de voltear=%d\n",aux );
      return aux;

    }
  }while(1);
}

void ensena_sumaraices(int n){

  for(int aux=voltear(n);;){
    switch (aux>=10) {
      case 1:
        printf("%d + ",aux%10 );
        aux/=10;
        break;

      default:
        printf("%d = %d\n",aux, sumaraices(n) );
        return;
    }
  }
}

void muestra(int n){
  do{
    switch (n>0) {
      case 1:
        ensena_sumaraices(n);
        n=sumaraices(n);
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
  for(;;inferior++){
    switch (inferior<=superior) {
      case 1:
      printf("~~~~~~~~~~~Raiz digital(%d)~~~~~~~~~~~\n",inferior );
      muestra(inferior);
      break;

      default:
      return;
        break;
    }
  }
}
void funcion_principal(){
  int a,b;
  while(1){
    printf("Dame un limite inferior\n");
    scanf("%d",&a );
    printf("Dame un limite superior\n" );
    scanf("%d",&b );
    (a>0&&a<b)?(a=a):(printf("Dame un numero mayor que 0 y menor que limite superior\n" ));

    printf("-------------------------------------------------------------------\n" );
    rangos(a,b);
    printf("-------------------------------------------------------------------\n" );
  }
}
