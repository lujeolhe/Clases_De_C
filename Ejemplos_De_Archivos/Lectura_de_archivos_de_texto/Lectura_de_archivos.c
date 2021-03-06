/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Definicion de Funciones
/////////////////////////
int contar_caracteres(FILE *archivoDeTexto);
int contar_letras(FILE *archivoDeTexto);
int contar_palabras(FILE *archivoDeTexto);
int contar_lineas(FILE *archivoDeTexto);
int contar_palabra(FILE *archivoDeTexto,char *palabra_a_buscar);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  FILE *archivoDeTexto;
  archivoDeTexto=fopen("Archivo_de_lectura.txt", "r");
  if(!archivoDeTexto){
    printf("No se pude abrir o crear el archivo\n" );
    exit(1);
  }

  char buffer[50];

  fscanf(archivoDeTexto,"%s",buffer );//Solo guarda una palabra del archivo.
  printf("%s\n",buffer );

  rewind(archivoDeTexto);//Nos coloca en el principio del archivo.

  fgets(buffer,50,archivoDeTexto);//Lee una linea del archivo.
  printf("%s",buffer );

  fgets(buffer,50,archivoDeTexto);
  printf("%s",buffer );

  fgets(buffer,50,archivoDeTexto);
  printf("%s\n",buffer );

  printf("El numero de caracteres es: %d\n",contar_caracteres(archivoDeTexto) );
  printf("El numero de letras es: %d\n",contar_letras(archivoDeTexto) );
  printf("El numero de palabras es: %d\n",contar_palabras(archivoDeTexto) );
  printf("El numero de lineas es: %d\n",contar_lineas(archivoDeTexto) );
  // Se pone la palabra archivos con comillas dobles por que es un arreglo.
  printf("El numero de palabra 'hola' es: %d\n",contar_palabra(archivoDeTexto,"hola") );
}
/////////////////////////////////////////////////////////////

int contar_caracteres(FILE *archivoDeTexto){
  int contador=0;
  rewind(archivoDeTexto);
//Mientras no se acabe el archivo vamos a contar los caracteres(Ciclo)
  while(!feof(archivoDeTexto)){

    fgetc(archivoDeTexto); //solo recoge un caracter del archivo, por vez
    contador++;
  }
  return contador;
}
int contar_letras(FILE *archivoDeTexto){
  int contador=0;
  char caracter;
  rewind(archivoDeTexto);

  while(!feof(archivoDeTexto)){

    caracter=fgetc(archivoDeTexto);
    //Las comillas simples hacen referencia a un caracter.
    if((caracter>='a'&&caracter<='z')||(caracter>='A'&& caracter<='Z'))
      contador++;
  }
  return contador;
}
int contar_palabras(FILE *archivoDeTexto){
  int contador=0;
  char caracter;

  rewind(archivoDeTexto);

  while(!feof(archivoDeTexto)){

    caracter=fgetc(archivoDeTexto);
    if(caracter==' '|| caracter==10)
      contador++;
  }
  return contador;
}
int contar_lineas(FILE *archivoDeTexto){
  int contador=0;
  char caracter;

  rewind(archivoDeTexto);
//Nos dice cuando termina un archivo.
  while(!feof(archivoDeTexto)){

    caracter=fgetc(archivoDeTexto);
    if( caracter==10)
      contador++;
  }
  return contador;
}
int contar_palabra(FILE *archivoDeTexto,char *palabra_a_buscar){
  int contador=0;
  char buffer[20];
  //Nos dice el tamaño de la palabra a buscar
  int tam_palabra=strlen(palabra_a_buscar);
  rewind(archivoDeTexto);

  while(!feof(archivoDeTexto)){

    fscanf(archivoDeTexto,"%s",buffer);
    //Convertir caracteres en minusculas.
    for(int i=0;i<20;i++){
      if((buffer[i]>='A'&&buffer[i]<='Z')){
          buffer[i]=buffer[i]+32;
        }
        else{
          buffer[i]=buffer[i];
        }
      }

      //Los caracteres que no sean letras se saltan.
      printf("Esto es lo que tiene buffer en contar_palabra antes de entrar al while: %u\n",buffer[0] );
      while((buffer[0]>0 && buffer[0]<'A')||(buffer[0]>'Z' && buffer[0]<'a')||buffer[0]>'z'){
        //printf("Esto es lo que tiene buffer completo antes del for en contar_palabra: %s\n",buffer );
        //printf("Esto es lo que tiene buffer en contar_palabra: %c\n",buffer[0] );
        for(int i=0;i<19;i++){
          buffer[i]=buffer[i+1];
        }
        //printf("Esto es lo que tiene buffer completo despues del for en contar_palabra: %s\n",buffer );
      }
      //Compara los arreglos de caracteres
      //if(!strcmp(buffer,palabra_a_buscar))
    if(!strncmp(buffer,palabra_a_buscar,tam_palabra)){
      printf("%s\n",buffer );
        contador++;


    }
    for(int i=0;i<20;i++){
      buffer[i]=0;
    }
  }
  return contador;
}
