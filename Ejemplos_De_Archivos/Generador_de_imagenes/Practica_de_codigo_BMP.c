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
typedef struct BMPH{
  char ID_field[2];
  char Size_of_the_BMP_file[4];
  char Application_specific[2];
  char Application_specific_2[2];
  char Offset[4];
} BMP_HEADER;

typedef struct DIB{
  char BIM_header[4];
  char Width_in_pixels[4];
  char Height_in_pixels[4];
  char Number_of_color[2];
  char Number_of_bits[2];
  char BI_RGB[4];
  char Size_of_the_raw[4];
  char Print_resolution_horizontal[4];
  char Print_resolution_vertical[4];
  char Number_of_colors_in_the_palette[4];
  char Means[4];
} DIB_HEADER;

typedef struct RGB{
  char Azul;
  char Verde;
  char Rojo;
} RGB_COLOR;

typedef struct Celda_RGB{
  RGB_COLOR colores[2];
  char Padding [2];
} CELDA_RGB;

typedef struct MP{
  RGB_COLOR *colores;
  int renglon_de_pixeles;
  int columna_de_pixeles;
}MATRIZ_DE_PIXELES;

int main(){
  /// Para conocer el numero de bytes que va tener nuestra imagen hay multiplicar el numero de pixeles por 3 mas 54 (que es el tamaño de los encabezados de bits)
  FILE *archivoBinario;
  archivoBinario=fopen("Imagen.bmp", "wb");
  if(!archivoBinario){
    printf("No se pude abrir o crear el archivo\n" );
    exit(1);
    }
    BMP_HEADER a;
    a.ID_field[0]=0x42;
    a.ID_field[1]=0x4D;
    a.Size_of_the_BMP_file[0]=0x54; //Aqui se cambian los bytes cuando se aumenta de tamaño
    a.Size_of_the_BMP_file[1]=0x00;
    a.Size_of_the_BMP_file[2]=0x00;
    a.Size_of_the_BMP_file[3]=0x00;
    a.Application_specific[0]=0x00;
    a.Application_specific[1]=0x00;
    a.Application_specific_2[0]=0x00;
    a.Application_specific_2[1]=0x00;
    a.Offset[0]=0x36;
    a.Offset[1]=0x00;
    a.Offset[2]=0x00;
    a.Offset[3]=0x00;

    DIB_HEADER b;
    b.BIM_header[0]=0x28;
    b.BIM_header[1]=0x00;
    b.BIM_header[2]=0x00;
    b.BIM_header[3]=0x00;
    b.Width_in_pixels[0]=0x04; //Largo del tamaño de los pixeles, menor que 4 es con padding
    b.Width_in_pixels[1]=0x00;
    b.Width_in_pixels[2]=0x00;
    b.Width_in_pixels[3]=0x00;
    b.Height_in_pixels[0]=0x02; //ALto del tamaño de los pixeles
    b.Height_in_pixels[1]=0x00;
    b.Height_in_pixels[2]=0x00;
    b.Height_in_pixels[3]=0x00;
    b.Number_of_color[0]=0x01;
    b.Number_of_color[1]=0x00;
    b.Number_of_bits[0]=0x18;
    b.Number_of_bits[1]=0x00;
    b.BI_RGB[0]=0x00;
    b.BI_RGB[1]=0x00;
    b.BI_RGB[2]=0x00;
    b.BI_RGB[3]=0x00;
    b.Size_of_the_raw[0]=0x20; // Tamaño de la matriz en bytes
    b.Size_of_the_raw[1]=0x00;
    b.Size_of_the_raw[2]=0x00;
    b.Size_of_the_raw[3]=0x00;
    b.Print_resolution_horizontal[0]=0x13;
    b.Print_resolution_horizontal[1]=0x0B;
    b.Print_resolution_horizontal[2]=0x00;
    b.Print_resolution_horizontal[3]=0x00;
    b.Print_resolution_vertical[0]=0x13;
    b.Print_resolution_vertical[1]=0x0B;
    b.Print_resolution_vertical[2]=0x00;
    b.Print_resolution_vertical[3]=0x00;
    b.Number_of_colors_in_the_palette[0]=0x00;
    b.Number_of_colors_in_the_palette[1]=0x00;
    b.Number_of_colors_in_the_palette[2]=0x00;
    b.Number_of_colors_in_the_palette[3]=0x00;
    b.Means[0]=0x00;
    b.Means[1]=0x00;
    b.Means[2]=0x00;
    b.Means[3]=0x00;

    // En el formato BMP se le de izauierda a derecha y de abajo hacia arriba

    CELDA_RGB c[4];
    c[0].colores[0].Azul=0xFF;
    c[0].colores[0].Verde=0x00;
    c[0].colores[0].Rojo=0xE5;
    c[0].colores[1].Azul=0x00;
    c[0].colores[1].Verde=0xFF;
    c[0].colores[1].Rojo=0xB3;
    c[1].colores[0].Azul=0x00;
    c[1].colores[0].Verde=0x83;
    c[1].colores[0].Rojo=0xFF;
    c[1].colores[1].Azul=0x00;
    c[1].colores[1].Verde=0x00;
    c[1].colores[1].Rojo=0x00;

    c[2].colores[0].Azul=0xFF;
    c[2].colores[0].Verde=0x0A;
    c[2].colores[0].Rojo=0x00;
    c[2].colores[1].Azul=0xF2;
    c[2].colores[1].Verde=0xFF;
    c[2].colores[1].Rojo=0x00;
    c[3].colores[0].Azul=0xFC;
    c[3].colores[0].Verde=0x5F;
    c[3].colores[0].Rojo=0xFF;
    c[3].colores[1].Azul=0x8E;
    c[3].colores[1].Verde=0xD9;
    c[3].colores[1].Rojo=0xFF;

    // El padding controla como se ve la imagen, horizontal o vertical.

    MATRIZ_DE_PIXELES m;
    RGB_COLOR vector_de_pixeles[8];
    m.colores=vector_de_pixeles;
    m.renglon_de_pixeles=2;
    m.columna_de_pixeles=4;
    vector_de_pixeles[0].Azul=0xFF;
    vector_de_pixeles[0].Verde=0x00;
    vector_de_pixeles[0].Rojo=0xE5;
    vector_de_pixeles[1].Azul=0x00;
    vector_de_pixeles[1] .Verde=0xFF;
    vector_de_pixeles[1].Rojo=0xB3;
    vector_de_pixeles[2].Azul=0x00;
    vector_de_pixeles[2].Verde=0x83;
    vector_de_pixeles[2].Rojo=0xFF;
    vector_de_pixeles[3].Azul=0x00;
    vector_de_pixeles[3].Verde=0x00;
    vector_de_pixeles[3].Rojo=0x00;

    vector_de_pixeles[4].Azul=0xFF;
    vector_de_pixeles[4].Verde=0x0A;
    vector_de_pixeles[4].Rojo=0x00;
    vector_de_pixeles[5].Azul=0xF2;
    vector_de_pixeles[5].Verde=0xFF;
    vector_de_pixeles[5].Rojo=0x00;
    vector_de_pixeles[6].Azul=0xFC;
    vector_de_pixeles[6].Verde=0x5F;
    vector_de_pixeles[6].Rojo=0xFF;
    vector_de_pixeles[7].Azul=0x8E;
    vector_de_pixeles[7].Verde=0xD9;
    vector_de_pixeles[7].Rojo=0xFF;

    //Los colores necesitan 4 bytes para generarse.

    /*Como a y b no son punteros o arreglos se les coloca & para mandar
    la dirreccion, como si duera un puntero*/
    fwrite(&a,sizeof(BMP_HEADER),1,archivoBinario);
    fwrite(&b,sizeof(DIB_HEADER),1,archivoBinario);
    fwrite(c,sizeof(CELDA_RGB),4,archivoBinario);
    //fwrite(vector_de_pixeles,sizeof(RGB_COLOR),8,archivoBinario);


  /* char header_BMP[14];
    char header_DIB[40];
    char Pixel_array[16];
//el "0x" sirve para hacer que c en tienda que se esta usando numeros hexadecimales.

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
*/

    fclose(archivoBinario);
}
