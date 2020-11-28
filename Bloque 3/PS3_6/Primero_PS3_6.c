////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
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

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand(time(NULL));
  int p[tam_max],al[tam_max],s[tam_max],edad[tam_max], n;
  printf("Dime cuantas personas se promediaran\n" );
  scanf("%d",&n );

  for(int i=0;i<n;i++){
    p[i]=0;
  }
  for(int i=0;i<n;i++){
    al[i]=0;
  }
  for(int i=0;i<n;i++){
    s[i]=0;
  }
  for(int i=0;i<n;i++){
    edad[i]=0;
  }
  for(int i=0;i<n;i++){
    p[i]=rand()%40+40;
  }
  for(int i=0;i<n;i++){
    al[i]=rand()%50+130;
  }
  for(int i=0;i<n;i++){
    s[i]=rand()%2;
  }
  for(int i=0;i<n;i++){
    edad[i]=rand()%65+5;
  }

  printf("\nPeso:  " );
  for(int i=0;i<n;i++){
    printf(" *%d * ",p[i] );
  }
  printf("\n" );
  printf("Altura:" );
  for(int i=0;i<n;i++){
    printf(" *%d* ",al[i] );
  }
  printf("\n" );
  printf("Sexo:  " );
  for(int i=0;i<n;i++){
    printf(" * %d * ",s[i] );
  }
  printf("\n" );
  printf("Edad:  " );
  for(int i=0;i<n;i++){
    printf(" *%d * ",edad[i] );
  }
  printf("\n" );
  int aux_peso=0,aux_altura=0,cont_feme=0,aux_peso2=0,aux_altura2=0,cont_masc=0;
    for(int i=0;i<n;i++){
      if(s[i]==0){
        if(edad[i]>=18){
          aux_peso=aux_peso+p[i];
          aux_altura=aux_altura+al[i];
          cont_feme++;
        }
      }
      else if(edad[i]>=18){
        aux_peso2=aux_peso2+p[i];
        aux_altura2=aux_altura2+al[i];
        cont_masc++;
      }
    }
    printf("\nNumero de Hombres mayores de 18: %d\n",cont_masc );
    printf("Peso promedio Hombres: %d kg\n",aux_peso2/cont_masc );
    printf("Altura promedio Hombres: %d cm\n",aux_altura2/cont_masc );
    printf("\n" );
    printf("Numero de Mujeres mayores de 18: %d\n",cont_feme );
    printf("Peso promedio Mujeres: %d kg\n",aux_peso/cont_feme );
    printf("Altura promedio Mujeres: %d cm\n",aux_altura/cont_feme );
}
