////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 500
#define dias 30
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
  srand(time(NULL));
  int n;
  printf("De cuantas regiones quieres saber el promedio anual\n" );
  scanf("%d",&n );
  promedio_anual(n);
}

int promedio_anual(int n){
  int mes[tam_max],aux_nort[tam_max],aux_cen[tam_max],aux_sur[tam_max],aux_gol[tam_max],aux_pac[tam_max],aux_car[tam_max];
  int prom_anual=0,prom_anual1=0,prom_anual2=0,prom_anual3=0,prom_anual4=0,prom_anual5=0;
  int aux_orden=0;
  char meses[tam_max]={"Enero Febrero Marzo Abril Mayo Junio Julio Agosto Septiembre Octubre Noviembre Diciembre"};
  for(int i=0;i<dias;i++){
    aux_nort[i]=0;
  }
  for(int i=0;i<dias;i++){
    aux_cen[i]=0;
  }
  for(int i=0;i<dias;i++){
    aux_sur[i]=0;
  }
  for(int i=0;i<dias;i++){
    aux_gol[i]=0;
  }
  for(int i=0;i<dias;i++){
    aux_pac[i]=0;
  }
  for(int i=0;i<dias;i++){
    aux_car[i]=0;
  }

  for(int i=0;i<dias;i++){
    mes[i]=0;
  }
  for(int i=0;i<dias;i++){
    mes[i]=rand()%30+20;
  }

  for(int i=1;i<=n;i++){
    switch (i) {
      case 1:
      printf("\n*********************Region del Norte************************\n" );
        for(int j=1;j<=12;j++){
          switch (j) {
            case 1:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 2:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 3:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 4:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 5:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 6:
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 7:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 8:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 9:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 10:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 11:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];
              }
              aux_nort[j]=aux_nort[j]/30;
            break;
            case 12:
              for(int i=0;i<dias;i++){
                mes[i]=rand()%30+20;
              }
              for(int k=0;k<30;k++){
                aux_nort[j]=aux_nort[j]+mes[k];

              }
              aux_nort[j]=aux_nort[j]/30;
            break;
          }
        }
        /*for(int i=1;i<=12;i++){
          printf("%d ",aux_nort[i] );
        }
        printf("\n" );*/
        for(int j=1;j<=12;j++){
          for(int i=1;i<=12;i++){
            if(i+1<13&&aux_nort[i]>aux_nort[i+1]){
              aux_orden=aux_nort[i+1];
              aux_nort[i+1]=aux_nort[i];
              aux_nort[i]=aux_orden;
            }
            else{
              aux_nort[i]=aux_nort[i];
            }
          }
        }
        /*for(int i=1;i<=12;i++){
          printf("%d ",aux_nort[i] );
        }*/
        for(int i=0;i<dias;i++){
          prom_anual+=aux_nort[i];
        }
        printf("\nEl registro mas alto es: %d\n",aux_nort[12] );
        printf("El registro mas bajo es: %d\n",aux_nort[1] );
        printf("EL Pormedio Anual es: %d\n",prom_anual/12);
      break;
      case 2:
      printf("\n*********************Region del Centro************************\n" );
      for(int j=1;j<=12;j++){
        switch (j) {
          case 1:
          for(int i=0;i<dias;i++){
            mes[i]=rand()%30+20;
          }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 2:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 3:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 4:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 5:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 6:
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 7:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 8:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 9:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 10:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 11:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];
            }
            aux_cen[j]=aux_cen[j]/30;
          break;
          case 12:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_cen[j]=aux_cen[j]+mes[k];

            }
            aux_cen[j]=aux_cen[j]/30;
          break;
        }
      }
      for(int j=1;j<=12;j++){
        for(int i=1;i<=12;i++){
          if(i+1<13&&aux_cen[i]>aux_cen[i+1]){
            aux_orden=aux_cen[i+1];
            aux_cen[i+1]=aux_cen[i];
            aux_cen[i]=aux_orden;
          }
          else{
            aux_cen[i]=aux_cen[i];
          }
        }
      }
      for(int i=0;i<dias;i++){
        prom_anual1+=aux_cen[i];
      }
      printf("\nEl registro mas alto es: %d\n",aux_cen[12] );
      printf("El registro mas bajo es: %d\n",aux_cen[1] );
      printf("EL Pormedio Anual es: %d\n",prom_anual1/12);
      break;
      case 3:
      printf("\n*********************Region del Sur************************\n" );
      for(int j=1;j<=12;j++){
        switch (j) {
          case 1:
          for(int i=0;i<dias;i++){
            mes[i]=rand()%30+20;
          }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 2:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 3:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 4:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 5:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 6:
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 7:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 8:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 9:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 10:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 11:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];
            }
            aux_sur[j]=aux_sur[j]/30;
          break;
          case 12:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_sur[j]=aux_sur[j]+mes[k];

            }
            aux_sur[j]=aux_sur[j]/30;
          break;
        }
      }
      for(int j=1;j<=12;j++){
        for(int i=1;i<=12;i++){
          if(i+1<13&&aux_sur[i]>aux_sur[i+1]){
            aux_orden=aux_sur[i+1];
            aux_sur[i+1]=aux_sur[i];
            aux_sur[i]=aux_orden;
          }
          else{
            aux_sur[i]=aux_sur[i];
          }
        }
      }
      for(int i=0;i<dias;i++){
        prom_anual2+=aux_sur[i];
      }
      printf("\nEl registro mas alto es: %d\n",aux_sur[12] );
      printf("El registro mas bajo es: %d\n",aux_sur[1] );
      printf("EL Pormedio Anual es: %d\n",prom_anual2/12);
      break;
      case 4:
      printf("\n*********************Region del Golfo************************\n" );
      for(int j=1;j<=12;j++){
        switch (j) {
          case 1:
          for(int i=0;i<dias;i++){
            mes[i]=rand()%30+20;
          }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 2:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 3:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 4:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 5:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 6:
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 7:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 8:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 9:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 10:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 11:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];
            }
            aux_gol[j]=aux_gol[j]/30;
          break;
          case 12:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_gol[j]=aux_gol[j]+mes[k];

            }
            aux_gol[j]=aux_gol[j]/30;
          break;
        }
      }
      for(int j=1;j<=12;j++){
        for(int i=1;i<=12;i++){
          if(i+1<13&&aux_gol[i]>aux_gol[i+1]){
            aux_orden=aux_gol[i+1];
            aux_gol[i+1]=aux_gol[i];
            aux_gol[i]=aux_orden;
          }
          else{
            aux_gol[i]=aux_gol[i];
          }
        }
      }
      for(int i=0;i<dias;i++){
        prom_anual3+=aux_gol[i];
      }
      printf("\nEl registro mas alto es: %d\n",aux_gol[12] );
      printf("El registro mas bajo es: %d\n",aux_gol[1] );
      printf("EL Pormedio Anual es: %d\n",prom_anual3/12);
      break;
      case 5:
      printf("\n*********************Region del Pacifico************************\n" );
      for(int j=1;j<=12;j++){
        switch (j) {
          case 1:
          for(int i=0;i<dias;i++){
            mes[i]=rand()%30+20;
          }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 2:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 3:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 4:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 5:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 6:
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 7:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 8:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 9:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 10:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 11:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];
            }
            aux_pac[j]=aux_pac[j]/30;
          break;
          case 12:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_pac[j]=aux_pac[j]+mes[k];

            }
            aux_pac[j]=aux_pac[j]/30;
          break;
        }
      }
      for(int j=1;j<=12;j++){
        for(int i=1;i<=12;i++){
          if(i+1<13&&aux_pac[i]>aux_pac[i+1]){
            aux_orden=aux_pac[i+1];
            aux_pac[i+1]=aux_pac[i];
            aux_pac[i]=aux_orden;
          }
          else{
            aux_pac[i]=aux_pac[i];
          }
        }
      }
      for(int i=0;i<dias;i++){
        prom_anual4+=aux_pac[i];
      }
      printf("\nEl registro mas alto es: %d\n",aux_pac[12] );
      printf("El registro mas bajo es: %d\n",aux_pac[1] );
      printf("EL Pormedio Anual es: %d\n",prom_anual4/12);
      break;
      case 6:
      printf("\n*********************Region del Caribe************************\n" );
      for(int j=1;j<=12;j++){
        switch (j) {
          case 1:
          for(int i=0;i<dias;i++){
            mes[i]=rand()%30+20;
          }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 2:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 3:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 4:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 5:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 6:
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 7:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 8:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 9:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 10:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 11:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];
            }
            aux_car[j]=aux_car[j]/30;
          break;
          case 12:
            for(int i=0;i<dias;i++){
              mes[i]=rand()%30+20;
            }
            for(int k=0;k<30;k++){
              aux_car[j]=aux_car[j]+mes[k];

            }
            aux_car[j]=aux_car[j]/30;
          break;
        }
      }
      for(int i=0;i<dias;i++){
        prom_anual5+=aux_car[i];
      }
      for(int j=1;j<=12;j++){
        for(int i=1;i<=12;i++){
          if(i+1<13&&aux_car[i]>aux_car[i+1]){
            aux_orden=aux_car[i+1];
            aux_car[i+1]=aux_car[i];
            aux_car[i]=aux_orden;
          }
          else{
            aux_car[i]=aux_car[i];
          }
        }
      }
      printf("\nEl registro mas alto es: %d\n",aux_car[12] );
      printf("El registro mas bajo es: %d\n",aux_car[1] );
      printf("EL Pormedio Anual es: %d\n",prom_anual5/12);
      break;
      default:
      break;
    }
  }
  printf("***************************************************\n" );
  printf("Cual es el registro mas alto entre el Sur, Pacifico y Caribe\n" );
  if(prom_anual2==prom_anual4&&prom_anual4==prom_anual5){
    printf("Todos los valores son iguales\n" );
  }
  else if(prom_anual2>prom_anual4){
      if(prom_anual2>prom_anual5){
        printf("El Valor del Sur es el mas grande: %d\n",prom_anual2/12 );
        }
      else{
          printf("El Valor del Caribe es el mas grande: %d\n",prom_anual5/12 );
        }
    }
    else if(prom_anual5>prom_anual4){
        printf("El Valor del Caribe es el mas grande: %d\n",prom_anual5/12 );
    }
    else{
        printf("El Valor del Pacifico es el mas grande: %d\n",prom_anual4/12 );
    }
}
