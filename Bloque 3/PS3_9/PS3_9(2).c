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
int promedio_anual(int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n;
  printf("Dame un numero\n" );
  scanf("%d",&n );
  promedio_anual(n);
}

int promedio_anual(int n){
  int mes[tam_max],aux_nort[tam_max];
  for(int i=0;i<n;i++){
    mes[i]=0;
  }
  for(int i=0;i<n;i++){
    mes[i]=rand()%30+20;
  }
  for(int i=0;i<n;i++){
    printf("%d ",mes[i] );
  }

  for(int i=1;i<=6;i++){
    switch (i) {
      case 1:
        for(int j=1;j<=12;j++){
          switch (j) {
            case 1:
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              printf("Promedio del mes de enero: %d\n",aux_nort[j]/30 );
            break;
            case 2:
            break;
            case 3:
            break;
            case 4:
            break;
            case 5:
            break;
            case 6:
            break;
            case 7:
            break;
            case 8:
            break;
            case 9:
            break;
            case 10:
            break;
            case 11:
            break;
            case 12:
            break;
          }
        }
      break;
      case 2:
      break;
      case 3:
      break;
      case 4:
      break;
      case 5:
      break;
      case 6:
      break;
      default:
      break;
    }
  }
}
