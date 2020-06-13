/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Definicion de Funciones
/////////////////////////
int contador_de_caracteres(FILE *archivo);
int contador_de_letras(FILE *archivo);
int contador_de_palabras(FILE *archivo);
int contador_de_palabra(FILE *archivo,char *palabra);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  FILE *archivoDeTexto;

  archivoDeTexto=fopen("archivo_A_Leer.txt", "r");
  if(!archivoDeTexto){
    printf("No se pude abrir\n" );
    exit(1);
  }
  printf("El Archivo se abrio correctamente\n");

  char buffer[40];

  fscanf(archivoDeTexto, "%s ",buffer);
  printf("%s\n",buffer);
  printf("Hay %d caracteres \n",contador_de_caracteres(archivoDeTexto) );
  printf("Hay %d letras \n",contador_de_letras(archivoDeTexto) );
  printf("Hay %d palabras \n",contador_de_palabras(archivoDeTexto) );
  printf("La palabra Hola se repite: %d \n",contador_de_palabra(archivoDeTexto,"Hola") );
  return 0;
}

/////////////////////////
//Funciones
/////////////////////////
int contador_de_caracteres(FILE *archivo){
  rewind(archivo);
  int contador=0;
  while(!feof(archivo)){
    contador++;
    getc(archivo);
  }
  return contador;
}
int contador_de_letras(FILE *archivo){
  rewind(archivo);
  int contador=0;
  char c;
  while(!feof(archivo)){
    c=getc(archivo);
    if((c>'a'&&c<'z')||(c>'A'&&c<'Z')){
      contador++;
    }
  }
  return contador;
}
int contador_de_palabras(FILE *archivo){
  rewind(archivo);
  int contador=0;
  char c;
  while(!feof(archivo)){
    c=getc(archivo);
    if(c==' '){
      contador++;
    }
  }
  return contador;
}
int contador_de_palabra(FILE *archivo,char *palabra){
  rewind(archivo);
  printf("La palabra a buscar es: %s\n",palabra );
  int contador=0;
  char buffer[30];
  while(!feof(archivo)){
    fscanf(archivo,"%s",buffer);
    if(!strcmp(buffer,palabra)){
      contador++;
    }
  }
  return contador;
}
