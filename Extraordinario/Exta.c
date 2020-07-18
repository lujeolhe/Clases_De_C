/*Alumno:luis Pablo Gonzalez Galvez Grupo:1EV1
Fecha: 17/07/20
Descripcion: Examen Extraordinario.*/
/////////////////////////
//Librerias
/////////////////////////
/*#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <stdint.h>*/
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////
//Contiene los aspectos a evaluar del restaurante
typedef struct as{
  float Atencion;
  float Calidad;
  float Justicia;
  float Ambiente;
  float Musica;
  float Iluminacion;
  float Decoracion;
}aspectos;
//Contiene los aspectos generales del restaurante
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
  //variable de control de los aspectos.
  aspectos a;
  inicializar_encuesta(&a);
  printf("%2.0f\n",a.Atencion );
  //variable de control de restaurante.
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
  evaluacion_de_aspecto(&b.promedio);
  Histograma(b.encuestas,b.Numero_de_clientes);

}
/////////////////////////
//Funciones
/////////////////////////

//Les da valores aleatorios a los aspectos.
void inicializar_encuesta(aspectos *encuesta){
  //les da un valor diferente cada vez que se corre el programa
  srand (time(NULL));
  encuesta->Atencion=rand()%10+1;
  encuesta->Calidad=rand()%10+1;
  encuesta->Justicia=rand()%10+1;
  encuesta->Ambiente=rand()%10+1;
  encuesta->Musica=rand()%10+1;
  encuesta->Iluminacion=rand()%10+1;
  encuesta->Decoracion=rand()%10+1;
}

//Esta funcion nos da un numero aleatorio de clientes entre el 10 y el 20.
void inicializar_encuestados(restaurante *clientes){
    srand (time(NULL));
    //Como en la funcion rand empieza en 0 le sumamos 10 para que comience en 10..
    clientes->Numero_de_clientes=rand()%11+10;
}

void inicializar_restaurante(restaurante *empieza, char *localidad){
  //strcpy copia la cadena del destino al origen
          //destino             origen
    strcpy(empieza->Localidad,localidad);
    //
    inicializar_encuestados(empieza);
    for(int i=0;i<empieza->Numero_de_clientes;i++){
      //cuando se accede a un arreglo especifico deja de comportarse como puntero.
      //se hacen tantas encuestas como el numero de clientes.
      inicializar_encuesta(&empieza->encuestas[i]);
    }
    //se hace el promedio de las encuestas.
    promediar_aspectos(empieza);
    //se hace el promedio global.
    obtener_promedio_global(empieza);
}

void promediar_aspectos(restaurante *media){
  //Se declara aux para llevar el valor de cada aspecto.
  float aux[7];
  //se inicializa aux para que tenga 0 en todos sus valores.
  for(int i=0;i<7;i++){
    aux[i]=0;
  }
  for(int j=0;j<7;j++){
    //j es la que controla el avance de aux en el switch.
    for(int i=0;i<media->Numero_de_clientes;i++){
      //i es la que controla el avance entre las encuestas de los clientes.
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
  // despues de haberse sumado los promedios se dividen entre le numero de clientes.
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

//Se suman todos los promedios de la funcion promediar_aspectos y se guardan en la variable aux_promedio.
  aux_promedio+=promedio->promedio.Atencion;
  aux_promedio+=promedio->promedio.Calidad;
  aux_promedio+=promedio->promedio.Justicia;
  aux_promedio+=promedio->promedio.Ambiente;
  aux_promedio+=promedio->promedio.Musica;
  aux_promedio+=promedio->promedio.Iluminacion;
  aux_promedio+=promedio->promedio.Decoracion;
    printf("Promedio antes de salir, duncion obtener promedio:%2.2f\n",aux_promedio );
    //Se divide la suma de los promedios entre el numero de aspectos que hay.
  promedio->nota_global=aux_promedio/7;
}

void Histograma(aspectos *encuestas,int numero_de_encuestas){
  //se crea un puntero aspecto_auxiliar para guardar el valor de encuestas.
  aspectos *aspecto_auxiliar=encuestas;
  //se crea un arreglo de entreos.
  int vector[10][7];
  //se inicializa en ceros la variable vector
  for(int j=0;j<7;j++){
    for(int h=0;h<10;h++){
      vector[h][j]=0;
    }
  }

 for(int i=0;i<7;i++){
   //se coloca i en la condicion del switch para que cambien el case, conforme aumente i.
   switch (i) {
     case 0:
     printf("Histograma de Atencion\n" );
     //Colocamos encuestas=aspecto_auxiliar cuando empieza cada case para que no se sobreescriba.
     encuestas=aspecto_auxiliar;

     for(int j=0;j<numero_de_encuestas;j++){
       //lo que esta en el primer "[]" controla el lugar del aspectos
       /*Tabla de referencia de aspectos
                1=Atencion
                2=Calidad
                3=Justicia
                4=Ambiente
                5=Musica
                6=Iluminacion
                7=Decoracion                */
      //i controla las encuestas de los clientes.
       vector[(int)(encuestas->Atencion)-1][i]++;
       encuestas++;
     }
     // Estas es la representacion de la grafica.
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
  // se declara un variable de tipo flotante bidimencional.
  float vector[7][2];
//Estas declaraciones tienen el valor de los aspectos.
  vector[0][0]=encuestas->Atencion;
  vector[1][0]=encuestas->Calidad;
  vector[2][0]=encuestas->Justicia;
  vector[3][0]=encuestas->Ambiente;
  vector[4][0]=encuestas->Musica;
  vector[5][0]=encuestas->Iluminacion;
  vector[6][0]=encuestas->Decoracion;
  int i=0;
  do{
    //estas controlan la numeracion de los aspectos.
    vector[i][1]=i+1;
    i++;
  }while(i<7);
  //este ciclos imprimen a la variable vector.
  for(int i=0;i<7;i++){
  printf("%2.0f %2.2f\n",vector[i][1],vector[i][0] );
}
  printf("\n" );
//esta funicion ordena los valores de menor a mayor.x
  ordenar_promedios(vector);
  //este ciclos imprimen a la variable vector.
  for(int i=0;i<7;i++){
  printf("%2.0f %2.2f\n",vector[i][1],vector[i][0] );
}

/*Despues de ordenarlos nos damos cuenta que el valor mas
grande esta al final del arreglo y el mas pequeño estas al principio*/
//Se declara un arreglo nulo.
  char aspect[20]="";
  //se hace un string en la condicion porque el valor de vector es flotante.
  //se coloca esa posicion porque es en donde esta el valor de mayor tamaño.
  // el switch lo que va a hacer es buscar la posicion que tiene el aspecto y es el que va a dar.
  switch ((int)(vector[6][1])) {
    case 1:
    //se usa la funcion strcpy para remplazar el arreglo nulo con el contenido entre comillas.
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
  //en este esta el de menor valor
  // el switch lo que va a hacer es buscar la posicion que tiene el aspecto y es el que va a dar.
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
  printf("El aspecto peor evaluado es: %s\n\n",aspect2 );
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
