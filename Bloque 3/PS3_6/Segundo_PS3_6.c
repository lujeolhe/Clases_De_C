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
  int n;
  printf("Dime Cuantas personas son:\n" );
  scanf("%d",&n );
  int peso=0,altura=0,edad=0,sexo=0;
  int aux_peso=0,aux_altura=0,aux_peso2=0,aux_altura2=0,aux_edad=0,cont_men=0,cont_mu=0,aux_sexo=0;

  for(int i=1;i<=n;i++){
    printf("Persona numero %d\n",i );
    sexo=rand()%2;
    printf("Sexo:");
    printf("%d ",sexo );
    edad=rand()%75+5;
    printf("Edad:");
    printf("%d ",edad );
    peso=rand()%40+40;
    printf("Peso:");
    printf("%d ",peso );
    altura=rand()%30+150;
    printf("Altura:");
    printf("%d ",altura );
    printf("\n\n" );

    if(sexo==0){
      if(edad>=18){
        aux_peso=aux_peso+peso;
        aux_altura=aux_altura+altura;
        cont_mu++;
      }
    }
    else if(edad>=18){
      aux_peso2=aux_peso2+peso;
      aux_altura2=aux_altura2+altura;
      cont_men++;
    }
  }

  printf("El Promedio de peso en Hombres es: %d\n",aux_peso2/ cont_men);
  printf("El Promedio de peso en Hombres es: %d\n",aux_altura2/ cont_men);
  printf("El Promedio de peso en Mujeres es: %d\n",aux_peso/ cont_mu);
  printf("El Promedio de peso en Mujeres es: %d\n",aux_altura/ cont_mu);
}
