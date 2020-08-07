/*Alumno:luis Pablo Gonzalez Galvez Grupo:1EV1
Fecha: 17/07/20
Descripcion: Examen Extraordinario.*/
/////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////
typedef struct as{
  float Atencion;
  float Calidad;
  float Justicia;
  float Ambiente;
  float Musica;
  float Iluminacion;
  float Decoracion;
}aspectos;
typedef struct res{
  char Localidad[30];
  int Numero_de_clientes;
  aspectos encuestas[20];
  aspectos promedio;
  float nota_global;
}restaurante;

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void inicializar_encuesta(aspectos *encuesta);
void inicializar_encuestados(restaurante *clientes);
void inicializar_restaurante(restaurante *empieza, char *localidad);
void promediar_aspectos(restaurante *media);
void obtener_promedio_global(restaurante *promedio);
void Histograma(aspectos *encuestas,int numero_de_encuestas);
void evaluacion_de_aspecto(aspectos *encuestas);
void ordenar_promedios(float vector[7][2]);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  aspectos a;
  inicializar_encuesta(&a);
  printf("%2.0f\n",a.Atencion );
  restaurante b;
  inicializar_restaurante(&b,"Mexico");
  printf("Localidad: %s  Clientes:%d  Nota Global: %5.2f\n",b.Localidad,b.Numero_de_clientes,b.nota_global );
  printf("Atencion Promedio:\t%2.3f,\n",b.promedio.Atencion );
  printf("Calidad Promedio:\t%2.3f,\n",b.promedio.Calidad );
  printf("Justicia Promedio:\t%2.3f,\n",b.promedio.Justicia );
  printf("Ambiente Promedio:\t%2.3f,\n",b.promedio.Ambiente );
  printf("Musica Promedio:\t%2.3f,\n",b.promedio.Musica);
  printf("Iluminacion Promedio:\t%2.3f,\n",b.promedio.Iluminacion );
  printf("Decoracion Promedio:\t%2.3f,\n",b.promedio.Decoracion );
  Histograma(b.encuestas,b.Numero_de_clientes);
  evaluacion_de_aspecto(&b.promedio);
}
/////////////////////////
//Funciones
/////////////////////////
void inicializar_encuesta(aspectos *encuesta){
  srand (time(NULL));
  encuesta->Atencion=rand()%10+1;
  encuesta->Calidad=rand()%10+1;
  encuesta->Justicia=rand()%10+1;
  encuesta->Ambiente=rand()%10+1;
  encuesta->Musica=rand()%10+1;
  encuesta->Iluminacion=rand()%10+1;
  encuesta->Decoracion=rand()%10+1;
}

void inicializar_encuestados(restaurante *clientes){
    srand (time(NULL));
    //Como en la funcion rand empieza en 0 le sumamos 10 para que comience en ese numero.
    clientes->Numero_de_clientes=rand()%11+10;
}

void inicializar_restaurante(restaurante *empieza, char *localidad){
    strcpy(empieza->Localidad,localidad);
    inicializar_encuestados(empieza);
    for(int i=0;i<empieza->Numero_de_clientes;i++){
      //cuando se accede a un arreglo especifico deja de comportarse como puntero.
      inicializar_encuesta(&empieza->encuestas[i]);
    }
    promediar_aspectos(empieza);
    obtener_promedio_global(empieza);
}

void promediar_aspectos(restaurante *media){
  float aux[7];
  for(int i=0;i<7;i++){
    aux[i]=0;
  }
  for(int j=0;j<7;j++){
    for(int i=0;i<media->Numero_de_clientes;i++){
      switch (j) {
        case 0:
          aux[j]+=media->encuestas[i].Atencion;
          break;
        case 1:
          aux[j]+=media->encuestas[i].Calidad;
          break;
        case 2:
          aux[j]+=media->encuestas[i].Justicia;
          break;
        case 3:
          aux[j]+=media->encuestas[i].Ambiente;
          break;
        case 4:
          aux[j]+=media->encuestas[i].Musica;
          break;
        case 5:
          aux[j]+=media->encuestas[i].Iluminacion;
          break;
        case 6:
          aux[j]+=media->encuestas[i].Decoracion;
          break;

        default:
          break;
      }
    }
  }
  media->promedio.Atencion=aux[0]/(media->Numero_de_clientes);
  media->promedio.Calidad=aux[1]/media->Numero_de_clientes;
  media->promedio.Justicia=aux[2]/media->Numero_de_clientes;
  media->promedio.Ambiente=aux[3]/media->Numero_de_clientes;
  media->promedio.Musica=aux[4]/media->Numero_de_clientes;
  media->promedio.Iluminacion=aux[5]/media->Numero_de_clientes;
  media->promedio.Decoracion=aux[6]/media->Numero_de_clientes;
}

void obtener_promedio_global(restaurante *promedio){
  float aux_promedio=0;

  /*aux_promedio=promedio->promedio.Atencion+promedio->promedio.Calidad+
  promedio->promedio.Justicia+promedio->promedio.Musica+promedio->promedio.Iluminacion+promedio->promedio.Decoracion;*/
  aux_promedio+=promedio->promedio.Atencion;
  aux_promedio+=promedio->promedio.Calidad;
  aux_promedio+=promedio->promedio.Justicia;
  aux_promedio+=promedio->promedio.Ambiente;
  aux_promedio+=promedio->promedio.Musica;
  aux_promedio+=promedio->promedio.Iluminacion;
  aux_promedio+=promedio->promedio.Decoracion;
    printf("Promedio antes de salir, duncion obtener promedio:%2.2f\n",aux_promedio );
  promedio->nota_global=aux_promedio/7;
}

void Histograma(aspectos *encuestas,int numero_de_encuestas){
  aspectos *aspecto_auxiliar=encuestas;
  int vector[10][7];
  for(int j=0;j<7;j++){
    for(int h=0;h<10;h++){
      vector[h][j]=0;
    }
  }

 for(int i=0;i<7;i++){
   switch (i) {
     case 0:
     printf("Histograma de Atencion\n" );
     encuestas=aspecto_auxiliar;
     for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Atencion)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     case 1:
      printf("Histograma de Calidad\n" );
     encuestas=aspecto_auxiliar;
      for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Calidad)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     case 2:
      printf("Histograma de Justicia\n" );
     encuestas=aspecto_auxiliar;
      for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Justicia)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     case 3:
      printf("Histograma de Ambiente\n" );
     encuestas=aspecto_auxiliar;
      for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Ambiente)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     case 4:
      printf("Histograma de Musica\n" );
     encuestas=aspecto_auxiliar;
      for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Musica)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     case 5:
      printf("Histograma de Iluminacion\n" );
     encuestas=aspecto_auxiliar;
      for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Iluminacion)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     case 6:
      printf("Histograma de Decoracion\n" );
     encuestas=aspecto_auxiliar;
     for(int j=0;j<numero_de_encuestas;j++){
       vector[(int)(encuestas->Decoracion)-1][i]++;
       encuestas++;
     }
     for(int j=0;j<10;j++){
       printf("%d\t",j+1 );
       int k=0;
       while(k<vector[j][i]){
         printf("*");
         k++;
       }
       printf("\n");
     }
     break;

     default:
     break;
   }
 }
}

void evaluacion_de_aspecto(aspectos *encuestas){
  float vector[7][2];

  vector[0][0]=encuestas->Atencion;
  vector[1][0]=encuestas->Calidad;
  vector[2][0]=encuestas->Justicia;
  vector[3][0]=encuestas->Ambiente;
  vector[4][0]=encuestas->Musica;
  vector[5][0]=encuestas->Iluminacion;
  vector[6][0]=encuestas->Decoracion;
  int i=0;
  do{
    vector[i][1]=i+1;
    i++;
  }while(i<7);
  /*for(int i=0;i<7;i++){
  printf("%2.0f %2.2f\n",vector[i][1],vector[i][0] );
}*/
  printf("\n" );
  ordenar_promedios(vector);
  /*for(int i=0;i<7;i++){
  printf("%2.0f %2.2f\n",vector[i][1],vector[i][0] );
}*/
  char aspect[20]="";
  switch ((int)(vector[6][1])) {
    case 1:
      strcpy(aspect,"Antencion");
      break;
    case 2:
      strcpy(aspect,"Calidad");
      break;
    case 3:
      strcpy(aspect,"Justicia");
      break;
    case 4:
      strcpy(aspect,"Ambiente");
      break;
    case 5:
      strcpy(aspect,"Musica");
      break;
    case 6:
      strcpy(aspect,"Iluminacion");
      break;
    case 7:
      strcpy(aspect,"Decoracion");
      break;
    default:
      strcpy(aspect,"");
      break;
  }
  printf("El aspecto mejor evaluado es: %s\n",aspect );
  char aspect2[20]="";
  switch ((int)(vector[0][1])) {
    case 1:
      strcpy(aspect2,"Antencion");
      break;
    case 2:
      strcpy(aspect2,"Calidad");
      break;
    case 3:
      strcpy(aspect2,"Justicia");
      break;
    case 4:
      strcpy(aspect2,"Ambiente");
      break;
    case 5:
      strcpy(aspect2,"Musica");
      break;
    case 6:
      strcpy(aspect2,"Iluminacion");
      break;
    case 7:
      strcpy(aspect2,"Decoracion");
      break;
    default:
      strcpy(aspect2,"");
      break;
  }
  printf("El aspecto peor evaluado es: %s\n",aspect2 );
}
void ordenar_promedios(float vector[7][2]){
    int iteracion = 0;
    char permutation = 1;
    int actual;

    while ( permutation) {
        permutation = 0;
        iteracion ++;
        for (actual=0;actual<7-iteracion;actual++) {
            if (vector[actual][0]>vector[actual+1][0]){
                permutation = 1;
                // Intercambiamos los dos elementos
                int temp2= vector[actual][1];
                int temp = vector[actual][0];
                vector[actual][0] = vector[actual+1][0];
                vector[actual+1][0] = temp;

                vector[actual][1] = vector[actual+1][1];
                vector[actual+1][1] = temp2;
            }
        }
    }
}
