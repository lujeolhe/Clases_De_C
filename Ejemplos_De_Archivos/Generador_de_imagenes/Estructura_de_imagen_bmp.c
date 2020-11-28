/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <string.h>
/////////////////////////
//Estructuras
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

typedef struct pixel_matrix{
  RGB_COLOR *colores;
  int renglon;
  int columna;
}MATRIZ_DE_PIXELES;
/////////////////////////
//Definicion de Funciones
/////////////////////////
void inicializar_BMP_HEADER(BMP_HEADER *header_a_inicializar);
void inicializar_DIB_HEADER(DIB_HEADER *header_a_inicializar);
void inicializar_MATRIZ_DE_PIXELES(MATRIZ_DE_PIXELES *matriz, RGB_COLOR *vector_de_pixeles, int renglon, int columna);


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
    BMP_HEADER a;
    inicializar_BMP_HEADER(&a);
    DIB_HEADER b;
    inicializar_DIB_HEADER(&b);

    // En el formato BMP se le de izauierda a derecha y de abajo hacia arriba

    MATRIZ_DE_PIXELES matriz;
    RGB_COLOR vector_de_pixeles[256*256];
    int ren=2;
    int col=4;
    inicializar_MATRIZ_DE_PIXELES(&matriz,&vector_de_pixeles,ren,col);

    vector_de_pixeles[0].Azul=0xFF;
    vector_de_pixeles[0].Verde=0x00;
    vector_de_pixeles[0].Rojo=0xE5;

    vector_de_pixeles[1].Azul=0x00;
    vector_de_pixeles[1].Verde=0xFF;
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

//Falta función para no poner el alineamiento de bits
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


    //Los colores necesitan 4 bytes para generarse.

    /*Como a y b no son punteros o arreglos se les coloca & para mandar
    la dirreccion, como si duera un puntero*/
    fwrite(&a,sizeof(BMP_HEADER),1,archivoBinario);
    fwrite(&b,sizeof(DIB_HEADER),1,archivoBinario);
    fwrite(c,sizeof(CELDA_RGB),4,archivoBinario);
    fclose(archivoBinario);
    printf("Imagen Generada\n" );
}

/////////////////////////
//Definicion de Funciones
/////////////////////////

void inicializar_BMP_HEADER(BMP_HEADER *a){
  a->ID_field[0]=0x42;
  a->ID_field[1]=0x4D;
  a->Size_of_the_BMP_file[0]=0x54; //Aqui se cambian los bytes cuando se aumenta de tamaño
  a->Size_of_the_BMP_file[1]=0x00;
  a->Size_of_the_BMP_file[2]=0x00;
  a->Size_of_the_BMP_file[3]=0x00;
  a->Application_specific[0]=0x00;
  a->Application_specific[1]=0x00;
  a->Application_specific_2[0]=0x00;
  a->Application_specific_2[1]=0x00;
  a->Offset[0]=0x36;
  a->Offset[1]=0x00;
  a->Offset[2]=0x00;
  a->Offset[3]=0x00;
}
void inicializar_DIB_HEADER(DIB_HEADER *b){
  b->BIM_header[0]=0x28;
  b->BIM_header[1]=0x00;
  b->BIM_header[2]=0x00;
  b->BIM_header[3]=0x00;
  b->Width_in_pixels[0]=0x02; //Largo del tamaño de los pixeles
  b->Width_in_pixels[1]=0x00;
  b->Width_in_pixels[2]=0x00;
  b->Width_in_pixels[3]=0x00;
  b->Height_in_pixels[0]=0x04;//ALto del tamaño de los pixeles
  b->Height_in_pixels[1]=0x00;
  b->Height_in_pixels[2]=0x00;
  b->Height_in_pixels[3]=0x00;
  b->Number_of_color[0]=0x01;
  b->Number_of_color[1]=0x00;
  b->Number_of_bits[0]=0x18;
  b->Number_of_bits[1]=0x00;
  b->BI_RGB[0]=0x00;
  b->BI_RGB[1]=0x00;
  b->BI_RGB[2]=0x00;
  b->BI_RGB[3]=0x00;
  b->Size_of_the_raw[0]=0x20; // Tamaño de la matriz en bytes
  b->Size_of_the_raw[1]=0x00;
  b->Size_of_the_raw[2]=0x00;
  b->Size_of_the_raw[3]=0x00;
  b->Print_resolution_horizontal[0]=0x13;
  b->Print_resolution_horizontal[1]=0x0B;
  b->Print_resolution_horizontal[2]=0x00;
  b->Print_resolution_horizontal[3]=0x00;
  b->Print_resolution_vertical[0]=0x13;
  b->Print_resolution_vertical[1]=0x0B;
  b->Print_resolution_vertical[2]=0x00;
  b->Print_resolution_vertical[3]=0x00;
  b->Number_of_colors_in_the_palette[0]=0x00;
  b->Number_of_colors_in_the_palette[1]=0x00;
  b->Number_of_colors_in_the_palette[2]=0x00;
  b->Number_of_colors_in_the_palette[3]=0x00;
  b->Means[0]=0x00;
  b->Means[1]=0x00;
  b->Means[2]=0x00;
  b->Means[3]=0x00;
}
void inicializar_MATRIZ_DE_PIXELES(MATRIZ_DE_PIXELES *matriz ,RGB_COLOR *vector_de_pixeles, int renglon, int columna){
  matriz->colores=vector_de_pixeles;
  matriz->renglon=renglon;
  matriz->columna=columna;
}
