/*Alumno:luis Pablo Gonzalez Galvez Grupo:1EV1
Fecha: 17/07/20
Descripcion: Examen Extraordinario.*/
/////////////////////////
//Librerias
/////////////////////////
//stdio es para las funciones de entrada y salida.
#include <stdio.h>
//stdlib es para srand, rand y en ocaciones system
#include <stdlib.h>
//Funiones para manejar el tiempo.
#include <time.h>
//string maneja funciones de cadenas de caracteres.
#include <string.h>
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
//Contiene los detalles del restaurante
typedef struct res{
  char Localidad[30];
  int Numero_de_clientes;
  aspectos encuestas[20];
  aspectos promedio;
  float nota_global;
}restaurante;
//Se creo esta estructura para poder utilizar los nombres de los restaurantes.
typedef struct cc{
  char cadena[20];
}cadena;
/////////////////////////
//Declaracion de Funciones
/////////////////////////
void inicializar_encuesta(aspectos *encuesta);
void inicializar_encuestados(restaurante *clientes);
void inicializar_restaurante(restaurante *empieza, char *localidad);
void promediar_aspectos(restaurante *media);
void obtener_promedio_global(restaurante *promedio);
void Histograma(aspectos *encuestas,int numero_de_encuestas);
void evaluacion_de_aspectos(aspectos *encuestas);
void ordenar_promedios(float vector[][2],int numero_de_elementos);
void imprimir_info_restaurante(restaurante *sucursal);
void evaluar_restaurantes(restaurante *sucursales,int numero_de_restaurantes);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  srand (time(NULL));
  restaurante sucursales[5];
  cadena localidades[5]={"Mexico","Estados Unidos","Canada","Rusia","China"};
  for(int i=0;i<5;i++){
    inicializar_restaurante(&sucursales[i],localidades[i].cadena);
  }

  //variables creadas para poder controlar los switch y lo que escribiera el usuario.
  int opc=0;
  int opc2=0;
  char opc3;

  while(opc!=3){
    printf("Escoge una opcion:\n");
    printf("1. Informacion general de los restaurantes\n" );
    printf("2. Informacion detallada de cada restaurante\n" );
    printf("3. Salir\n" );
    scanf("%d",&opc );
    switch (opc) {
      case 1:
      // system permite ingresar comando de consola.
        system("cls");
        evaluar_restaurantes(sucursales,5);
        printf("\n" );
        printf("Presiona enter para continuar...\n" );
        fflush(stdin);
        scanf("%c",&opc3 );
        system("cls");
        break;

      case 2:
        system("cls");
        printf("Escoge el restaurante del que quieres la informacion:\n" );
        printf("1. Mexico\n" );
        printf("2. Estados Unidos\n" );
        printf("3. Canada\n" );
        printf("4. Rusia\n" );
        printf("5. China\n" );
        printf("6. Regresar al menu anterior\n" );
        scanf("%d",&opc2 );
        switch (opc2) {
          case 1:
            system("cls");
            imprimir_info_restaurante(&sucursales[0]);
            printf("\n" );
            printf("Presiona enter para continuar...\n" );
            fflush(stdin);
            scanf("%c",&opc3 );
            system("cls");
            break;

          case 2:
            system("cls");
            imprimir_info_restaurante(&sucursales[1]);
            printf("\n" );
            printf("Presiona enter para continuar...\n" );
            fflush(stdin);
            scanf("%c",&opc3 );
            system("cls");
            break;

          case 3:
            system("cls");
            imprimir_info_restaurante(&sucursales[2]);
            printf("\n" );
            printf("Presiona enter para continuar...\n" );
            fflush(stdin);
            scanf("%c",&opc3 );
            system("cls");
            break;

          case 4:
            system("cls");
            imprimir_info_restaurante(&sucursales[3]);
            printf("\n" );
            printf("Presiona enter para continuar...\n" );
            fflush(stdin);
            scanf("%c",&opc3 );
            system("cls");
            break;

          case 5:
            system("cls");
            imprimir_info_restaurante(&sucursales[4]);
            printf("\n" );
            printf("Presiona enter para continuar...\n" );
            fflush(stdin);
            scanf("%c",&opc3 );
            system("cls");
            break;
          case 6:
            system("cls");
            break;

          default:
            break;
        }
      case 3:
        break;

      default:
        break;
    }
  }

}
/////////////////////////
//Funciones
/////////////////////////

//Les da valores aleatorios a los aspectos.
void inicializar_encuesta(aspectos *encuesta){
  //les da un valor diferente cada vez que se corre el programa
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
    //Como en la funcion rand empieza en 0 le sumamos 10 para que comience en 10.
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
    //se hace el promedio global del restaurante.
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
       printf("%d\t|",j+1 );
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
       printf("%d\t|",j+1 );
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
       printf("%d\t|",j+1 );
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
       printf("%d\t|",j+1 );
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
       printf("%d\t|",j+1 );
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
       printf("%d\t|",j+1 );
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
       printf("%d\t|",j+1 );
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

void evaluacion_de_aspectos(aspectos *encuestas){
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
  /*Tabla de referencia de aspectos
           1=Atencion
           2=Calidad
           3=Justicia
           4=Ambiente
           5=Musica
           6=Iluminacion
           7=Decoracion                */

  //este ciclos imprimen a la variable vector desordenada.
  /*for(int i=0;i<7;i++){
  printf("%2.0f %2.2f\n",vector[i][1],vector[i][0] );
}*/
  printf("\n" );
//esta funicion ordena los valores de menor a mayor.x
  ordenar_promedios(vector,7);
  //este ciclos imprimen a la variable vector ordenada..
  /*for(int i=0;i<7;i++){
  printf("%2.0f %2.2f\n",vector[i][1],vector[i][0] );
}*/

/*Despues de ordenarlos nos damos cuenta que el valor mas
grande esta al final del arreglo y el mas pequeño estas al principio*/
//Se declara un arreglo nulo.
  char aspect[20]="";
  //se hace un string en la condicion porque el valor de vector es flotante.
  //se coloca esa posicion porque es en donde esta el valor de mayor tamaño.
  // el switch lo que va a hacer es buscar la posicion que tiene el aspecto y es el que va a dar.
int j=0;
  // se coloco este while porque si salen aspectos con la misma calificacion, aparescan en pantalla
  while(vector[6-j][0]==vector[6][0]){
    switch ((int)(vector[6-j][1])) {
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
    j++;
}






  char aspect2[20]="";
  int k=0;
    // se coloco este while porque si salen aspectos con la misma calificacion, aparescan en pantalla
    while(vector[0+k][0]==vector[0][0]){
      //este switch nos dara el numero de menor calificacion
      switch ((int)(vector[0+k][1])) {

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
          //en esta variable esta el de menor valor
          printf("El aspecto peor evaluado es: %s\n",aspect2 );
          k++;
  }
}

void ordenar_promedios(float vector[][2],int numero_de_elementos){
  //iteracion numero de vueltas
    int iteracion = 0;
  //es una bandera para saber si el numero cambio de lugar o no.
    char permutation = 1;
  //es el contador de nuestras iteraciones
    int actual;

    while ( permutation) {
        permutation = 0;
        iteracion ++;
        for (actual=0;actual<numero_de_elementos-iteracion;actual++) {
            if (vector[actual][0]>vector[actual+1][0]){
                permutation = 1;
                // Intercambiamos los dos elementos
                // temp es una variable auxiliar.
                float temp2= vector[actual][1];
                float temp = vector[actual][0];
                //aqui se hace el intercambio de lugar
                vector[actual][0] = vector[actual+1][0];
                vector[actual+1][0] = temp;

                vector[actual][1] = vector[actual+1][1];
                vector[actual+1][1] = temp2;
            }
        }
    }
}
//en esta funcion se coloca varios printf para poder visualizar todo los aspectos relacionados de un restaurante
void imprimir_info_restaurante(restaurante *sucursal){
  restaurante b=*sucursal;
  printf("***************************************************************************************\n" );
  printf("Localidad: %s || Clientes:%d || Nota Global: %5.3f\n",b.Localidad,b.Numero_de_clientes,b.nota_global );
  printf("\n" );
  printf("Atencion Promedio:\t%2.3f\n",b.promedio.Atencion );
  printf("Calidad Promedio:\t%2.3f\n",b.promedio.Calidad );
  printf("Justicia Promedio:\t%2.3f\n",b.promedio.Justicia );
  printf("Ambiente Promedio:\t%2.3f\n",b.promedio.Ambiente );
  printf("Musica Promedio:\t%2.3f\n",b.promedio.Musica);
  printf("Iluminacion Promedio:\t%2.3f\n",b.promedio.Iluminacion );
  printf("Decoracion Promedio:\t%2.3f\n",b.promedio.Decoracion );
  evaluacion_de_aspectos(&b.promedio);
  printf("\n" );
  Histograma(b.encuestas,b.Numero_de_clientes);
}

void evaluar_restaurantes(restaurante *sucursales, int numero_de_restaurantes){
  //se crea la variable de tipo flotante
  float vector[numero_de_restaurantes][2];
  //el ciclo es para llenar a los restaurantes con su nota global.
  for(int i=0;i<numero_de_restaurantes;i++){
    vector[i][0]=(sucursales+i)->nota_global;
    vector[i][1]=i+1;
  }

  ordenar_promedios(vector,numero_de_restaurantes);

  char aspect[20]="";
  int j=0;
  // se hace lo mismo que en la funcion evaluacion_de_aspectos.
    while(vector[numero_de_restaurantes-1-j][0]==vector[numero_de_restaurantes-1][0]&&j<numero_de_restaurantes){
      switch ((int)(vector[numero_de_restaurantes-1-j][1])) {

            case 1:
                strcpy(aspect,"Mexico");
                break;
            case 2:
              strcpy(aspect,"Estados Unidos");
              break;
            case 3:
              strcpy(aspect,"Canada");
              break;
            case 4:
              strcpy(aspect,"Rusia");
              break;
            case 5:
              strcpy(aspect,"China");
              break;
            default:
              strcpy(aspect,"");
              break;
          }
          printf("El restaurante mejor evaluado es:%s\n",aspect );
          j++;
  }

  char aspect2[20]="";
  int k=0;
    while(vector[0+k][0]==vector[0][0]&&k<numero_de_restaurantes){
      switch ((int)(vector[0+k][1])) {

            case 1:
              strcpy(aspect2,"Mexico");
              break;
            case 2:
              strcpy(aspect2,"Estados Unidos");
              break;
            case 3:
              strcpy(aspect2,"Canada");
              break;
            case 4:
              strcpy(aspect2,"Rusia");
              break;
            case 5:
              strcpy(aspect2,"China");
              break;
            default:
              strcpy(aspect2,"");
              break;
          }
          printf("El restaurante peor evaluado es:%s\n",aspect2 );
          k++;
  }
  //se coloca este printf para que separe las calificaciones de los mejores restaurantes.
  printf("*********************************************\n" );
  int h=0;
  //este ciclo es para poder imprimir las localidades y las notas globales de todos los restaurantes
  while(h<numero_de_restaurantes){
    printf("Localidad:%s || Calificacion:%2.2f\n",sucursales->Localidad,sucursales->nota_global );
    sucursales++;
    //h es la variable de control, de impresiones.
    h++;
  }
}
