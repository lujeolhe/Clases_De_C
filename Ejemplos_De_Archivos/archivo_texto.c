/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Definicion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  FILE *archivoDeTexto;
  FILE *archivoBinario;
  archivoDeTexto=fopen("Mi_Archivo_De_Texto.txt", "a+");
  archivoBinario=fopen("Mi_Archivo_Binario.bin", "a+b");
  if(!archivoDeTexto||!archivoBinario){
    printf("No se pude abrir o crear el archivo\n" );
    exit(1);
  }

  fprintf(archivoDeTexto, "Hola, Archivo\n");
  fclose(archivoDeTexto);

  int a=5, b=3, suma=0, *puntero=0;
  int a2=0,b2=0, suma2=0;
  suma=a+b;

  fwrite(puntero=&a,sizeof(int),1,archivoBinario);
  fwrite(puntero=&b,sizeof(int),1,archivoBinario);
  fwrite(puntero=&suma,sizeof(int),1,archivoBinario);

  rewind(archivoBinario);

  fread(puntero=&a2,sizeof(int),1,archivoBinario);
  fread(puntero=&b2,sizeof(int),1,archivoBinario);
  fread(puntero=&suma2,sizeof(int),1,archivoBinario);
  suma2=a2+b2;
  printf("La suma guardada es: %d+%d=%x\n",a2,b2,suma2);

  fclose(archivoBinario);
  return 0;
}

/////////////////////////
//Funciones
/////////////////////////
