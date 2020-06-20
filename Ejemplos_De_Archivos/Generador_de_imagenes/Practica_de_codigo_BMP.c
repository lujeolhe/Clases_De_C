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

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  FILE *archivoBinario;
  archivoBinario=fopen("Imagen.bmp", "wb");
  if(!archivoBinario){
    printf("No se pude abrir o crear el archivo\n" );
    exit(1);
    }
    char header_BMP[14];
    char header_DIB[40];
    char Pixel_array[16];

    header_BMP[0]=0x42;
    header_BMP[1]=0x4D;
    header_BMP[2]=0x46;
    header_BMP[3]=0x00;
    header_BMP[4]=0x00;
    header_BMP[5]=0x00;
    header_BMP[6]=0x00;
    header_BMP[7]=0x00;
    header_BMP[8]=0x00;
    header_BMP[9]=0x00;
    header_BMP[10]=0x36;
    header_BMP[11]=0x00;
    header_BMP[12]=0x00;
    header_BMP[13]=0x00;

    header_DIB[0]=0x28;
    header_DIB[1]=0x00;
    header_DIB[2]=0x00;
    header_DIB[3]=0x00;
    header_DIB[4]=0x02;
    header_DIB[5]=0x00;
    header_DIB[6]=0x00;
    header_DIB[7]=0x00;
    header_DIB[8]=0x02;
    header_DIB[9]=0x00;
    header_DIB[10]=0x00;
    header_DIB[11]=0x00;
    header_DIB[12]=0x01;
    header_DIB[13]=0x00;
    header_DIB[14]=0x18;
    header_DIB[15]=0x00;
    header_DIB[16]=0x00;
    header_DIB[17]=0x00;
    header_DIB[18]=0x00;
    header_DIB[19]=0x00;
    header_DIB[20]=0x10;
    header_DIB[21]=0x00;
    header_DIB[22]=0x00;
    header_DIB[23]=0x00;
    header_DIB[24]=0x13;
    header_DIB[25]=0x0B;
    header_DIB[26]=0x00;
    header_DIB[27]=0x00;
    header_DIB[28]=0x13;
    header_DIB[29]=0x0B;
    header_DIB[30]=0x00;
    header_DIB[31]=0x00;
    header_DIB[32]=0x00;
    header_DIB[33]=0x00;
    header_DIB[34]=0x00;
    header_DIB[35]=0x00;
    header_DIB[36]=0x00;
    header_DIB[37]=0x00;
    header_DIB[38]=0x00;
    header_DIB[39]=0x00;

    Pixel_array[0]=0x00;
    Pixel_array[1]=0x00;
    Pixel_array[2]=0xFF;
    Pixel_array[3]=0xFF;
    Pixel_array[4]=0xFF;
    Pixel_array[5]=0xFF;
    Pixel_array[6]=0x00;
    Pixel_array[7]=0x00;
    Pixel_array[8]=0xFF;
    Pixel_array[9]=0x00;
    Pixel_array[10]=0x00;
    Pixel_array[11]=0x00;
    Pixel_array[12]=0xFF;
    Pixel_array[13]=0x00;
    Pixel_array[14]=0x00;
    Pixel_array[15]=0x00;

    fwrite(header_BMP,sizeof(char),14,archivoBinario);
    fwrite(header_DIB,sizeof(char),40,archivoBinario);
    fwrite(Pixel_array,sizeof(char),16,archivoBinario);

    printf("%d\n",sizeof(char) );

    fclose(archivoBinario);
}
