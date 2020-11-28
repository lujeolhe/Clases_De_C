////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void fracciones(int n);
float division(int i);
float multiplicacion(int i, int n);
void fraccion(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int k;
  printf("Dime cuantos numeros quieres\n" );
  scanf("%d",&k );
  //fracciones(k);
  fraccion(k);
  return 0;
}

float division(int i){
  static float aux_opera2=3;
  float aux_div=1;
  aux_div=aux_div/(1/aux_opera2);
  printf("%d/%d * ",1,i );
  aux_opera2=aux_opera2+2;
  return aux_div;
}

float multiplicacion(int i, int n){
  static float aux_opera=2;
  float aux_multi=1;
  if(i==n){
    aux_multi=aux_multi*(1/aux_opera);
    printf("%d/%d = ",1,i );
  }
  else{
    aux_multi=aux_multi*(1/aux_opera);
    printf("%d/%d / ",1,i );
    aux_opera=aux_opera+2;
  }
  return aux_multi;
}

void fraccion(int n){
  float operacion=1;
  for(int i=1;i<=n;i++){
    if(i==1)
      printf("%d * ",1 );
    else if(i%2==0)
      operacion*=multiplicacion(i,n);
    else
      operacion*=division(i);
  }
  printf("%.3f\n",operacion );
}
/*void fracciones(int n){
  float aux=1,m=1;
  for(int i=1;i<=n;i++,m++){
    if(i==1){
      aux/=1;
      printf("%d * ",1 );
    }
    else if(i%2==0){
      if(i==n){
        printf("%d/%d = ",1,i );
          aux=aux*(1/m);
      }
      else{
        aux=aux*(1/m);
        printf("%d/%d / ",1,i );
      }
    }
    else{
      aux=aux/(1/m);
      printf("%d/%d * ",1,i );
    }
  }
  printf("%.3f\n",aux );
}*/
