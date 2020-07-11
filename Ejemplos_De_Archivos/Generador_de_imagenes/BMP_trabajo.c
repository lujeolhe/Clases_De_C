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
// para ver la imagne en hexadecimal se coloca el siguiente comando en la consola "cat .\Imagen.bmp( nombre de la imagen) |format-hex"
//cat= nos muestra lo que tiene un archivo de texto.

/////////////////////////
//Estructuras
/////////////////////////
/*Estructura BMP_HEADER:
*Descripcion: Tiene Los valores del BMP y los tiene en forma de char.
*/
typedef struct BMPH{
  unsigned char ID_field[2];
  unsigned char Size_of_the_BMP_file[4];
  unsigned char Application_specific[2];
  unsigned char Application_specific_2[2];
  unsigned char Offset[4];
} BMP_HEADER;

/*Estructura DIB_HEADER:
*Descripcion: Tiene Los valores del DIB y los tiene en forma de char.
*/
typedef struct DIB{
  unsigned char BIM_header[4];
  unsigned char Width_in_pixels[4];
  unsigned char Height_in_pixels[4];
  unsigned char Number_of_color[2];
  unsigned char Number_of_bits[2];
  unsigned char BI_RGB[4];
  unsigned char Size_of_the_raw[4];
  unsigned char Print_resolution_horizontal[4];
  unsigned char Print_resolution_vertical[4];
  unsigned char Number_of_colors_in_the_palette[4];
  unsigned char Means[4];
} DIB_HEADER;

/*Estructura RGB_COLOR:
*Descripcion: Tiene Los colores principales del RGB.
*/
typedef struct RGB{
  unsigned char Azul;
  unsigned char Verde;
  unsigned char Rojo;
} RGB_COLOR;

/*Estructura CELDA_RGB:
*Descripcion: Contiene la estructura RGB_COLOR y el Padding.
*/
typedef struct Celda_RGB{
  RGB_COLOR colores[2];
  unsigned char Padding [2];
} CELDA_RGB;

/*Estructura MATRIZ_DE_PIXELES:
*Descripcion: Contiene lo parametros de columna y renglon de los pixeles, un puntero a la estructura RGB_COLOR.
*/
typedef struct MP{
  RGB_COLOR *colores;
  int renglon_de_pixeles;
  int columna_de_pixeles;
}MATRIZ_DE_PIXELES;

/////////////////////////
//Definicion de Funciones
/////////////////////////
void inicializar_BMP_HEADER(BMP_HEADER *h);
void inicializar_DIB_HEADER(DIB_HEADER *d);
void asignarcolor_RGB_Color(RGB_COLOR *p,unsigned char rojo, unsigned char verde, unsigned char azul);
void cambiar_tamanio_BMP_bytes(BMP_HEADER *t,int new_size);
void cambiar_tamanio_DIB_HEADER(DIB_HEADER *t, int new_Width,int new_Height);
void cambiar_tamnio_matriz_de_datos(DIB_HEADER *t, int new_mapbit );
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

    cambiar_tamanio_BMP_bytes(&a,0x1EF);//Como saber cuantos bits ocupa el trabajo, pues se multiplica el Width por el Height y al resultado se le multiplica por 3 y se le suma 54.
    a.Size_of_the_BMP_file[0]=0xEF;
    printf("%X\n",a.Size_of_the_BMP_file[0] );
    cambiar_tamanio_DIB_HEADER(&b,21,7);

    cambiar_tamnio_matriz_de_datos(&b,441);//Como saber cuantos bits ocupa el trabajo, pues se multiplica el Width por el Height y al resultado se le multiplica por 3.

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
    RGB_COLOR vector_de_pixeles[147];
    m.colores=vector_de_pixeles;
    m.renglon_de_pixeles=7;
    m.columna_de_pixeles=21;

    //Este for nos da el fondo de la imagen.
    for(int i=0;i<147;i++){
      asignarcolor_RGB_Color(&vector_de_pixeles[i],0xFF,0x00,0x00);
      //asignarcolor_RGB_Color(&vector_de_pixeles[i],0xFF,0xFF,0xFF);
    }
    //Estas funciones nos dan el patron de la imagen.
  /*  for(int a=22;a<41;a++){
      if(a==22||a==26||a==28||a==30||a==31||a==34||a==35||a==36||a==38||a==39||a==40){
        asignarcolor_RGB_Color(&vector_de_pixeles[a],0xFF,0xFE,0x00);
      }
    }
    for(int a=43;a<61;a++){
      if(a==43||a==47||a==49||a==51||a==53||a==55||a==59||a==61){
        asignarcolor_RGB_Color(&vector_de_pixeles[a],0xFF,0xFE,0x00);
      }
    }
    for(int a=64;a<82;a++){
      if(a==64||a==65||a==66||a==68||a==69||a==70||a==72||a==73||a==76||a==80||a==82){
        asignarcolor_RGB_Color(&vector_de_pixeles[a],0xFF,0xFE,0x00);
      }
    }
    for(int a=85;a<103;a++){
      if(a==85||a==87||a==89||a==91||a==93||a==95||a==97||a==101||a==103){
        asignarcolor_RGB_Color(&vector_de_pixeles[a],0xFF,0xFE,0x00);
      }
    }
    for(int a=106;a<124;a++){
      if(a==106||a==107||a==108||a==110||a==111||a==112||a==114||a==115||a==118||a==122||a==123||a==124){
        asignarcolor_RGB_Color(&vector_de_pixeles[a],0xFF,0xFE,0x00);
      }
    }
    */


    /*
    asignarcolor_RGB_Color(&vector_de_pixeles[0],0x00,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[1],0xFF,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[2],0xFF,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[3],0x00,0x00,0x00);

    asignarcolor_RGB_Color(&vector_de_pixeles[4],0xFF,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[5],0x00,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[6],0x00,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[7],0xFF,0x00,0x00);

    asignarcolor_RGB_Color(&vector_de_pixeles[8],0x00,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[9],0xFF,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[10],0xFF,0x00,0x00);
    asignarcolor_RGB_Color(&vector_de_pixeles[11],0x00,0x00,0x00);
*/
    //Los colores necesitan 4 bytes para generarse.

    /*Como a y b no son punteros o arreglos se les coloca & para mandar
    la dirreccion, como si duera un puntero*/
    fwrite(&a,sizeof(BMP_HEADER),1,archivoBinario);
    fwrite(&b,sizeof(DIB_HEADER),1,archivoBinario);
    //fwrite(c,sizeof(CELDA_RGB),4,archivoBinario);
    fwrite(vector_de_pixeles,sizeof(RGB_COLOR),147,archivoBinario);
    fclose(archivoBinario);
}
/////////////////////////
//Funciones
/////////////////////////
/*Funcion inicializar_BMP_HEADER:
*Descripcion: Inicializa la estructura BMP_HEADER.
*Parametros: Un puntero BMP_HEADER *h.
*Retorno: No regesa nada.
*/
void inicializar_BMP_HEADER(BMP_HEADER *h){
  h->ID_field[0]=0x42;
  h->ID_field[1]=0x4D;
  h->Size_of_the_BMP_file[0]=0x54; //Aqui se cambian los bytes cuando se aumenta de tamaño
  h->Size_of_the_BMP_file[1]=0x00;
  h->Size_of_the_BMP_file[2]=0x00;
  h->Size_of_the_BMP_file[3]=0x00;
  h->Application_specific[0]=0x00;
  h->Application_specific[1]=0x00;
  h->Application_specific_2[0]=0x00;
  h->Application_specific_2[1]=0x00;
  h->Offset[0]=0x36;
  h->Offset[1]=0x00;
  h->Offset[2]=0x00;
  h->Offset[3]=0x00;
}
/*Funcion inicializar_DIB_HEADER:
*Descripcion: Inicializa la estructura DIB_HEADER.
*Parametros: Un puntero DIB_HEADER *d.
*Retorno: No regesa nada.
*/
void inicializar_DIB_HEADER(DIB_HEADER *d){
  d->BIM_header[0]=0x28;
  d->BIM_header[1]=0x00;
  d->BIM_header[2]=0x00;
  d->BIM_header[3]=0x00;
  d->Width_in_pixels[0]=0x04; //Largo del tamaño de los pixeles, menor que 4 es con padding
  d->Width_in_pixels[1]=0x00;
  d->Width_in_pixels[2]=0x00;
  d->Width_in_pixels[3]=0x00;
  d->Height_in_pixels[0]=0x03; //ALto del tamaño de los pixeles
  d->Height_in_pixels[1]=0x00;
  d->Height_in_pixels[2]=0x00;
  d->Height_in_pixels[3]=0x00;
  d->Number_of_color[0]=0x01;
  d->Number_of_color[1]=0x00;
  d->Number_of_bits[0]=0x18;
  d->Number_of_bits[1]=0x00;
  d->BI_RGB[0]=0x00;
  d->BI_RGB[1]=0x00;
  d->BI_RGB[2]=0x00;
  d->BI_RGB[3]=0x00;
  d->Size_of_the_raw[0]=0x20; // Tamaño de la matriz en bytes
  d->Size_of_the_raw[1]=0x00;
  d->Size_of_the_raw[2]=0x00;
  d->Size_of_the_raw[3]=0x00;
  d->Print_resolution_horizontal[0]=0x13;
  d->Print_resolution_horizontal[1]=0x0B;
  d->Print_resolution_horizontal[2]=0x00;
  d->Print_resolution_horizontal[3]=0x00;
  d->Print_resolution_vertical[0]=0x13;
  d->Print_resolution_vertical[1]=0x0B;
  d->Print_resolution_vertical[2]=0x00;
  d->Print_resolution_vertical[3]=0x00;
  d->Number_of_colors_in_the_palette[0]=0x00;
  d->Number_of_colors_in_the_palette[1]=0x00;
  d->Number_of_colors_in_the_palette[2]=0x00;
  d->Number_of_colors_in_the_palette[3]=0x00;
  d->Means[0]=0x00;
  d->Means[1]=0x00;
  d->Means[2]=0x00;
  d->Means[3]=0x00;
}
/*Funcion asignarcolor_RGB_Color:
*Descripcion: Se les asigna un color a cada celda RGB.
*Parametros: Un puntero RGB_COLOR *p, char rojo, char verde, char azul.
*Retorno: No regesa nada.
*/
void asignarcolor_RGB_Color(RGB_COLOR *p,unsigned char rojo,unsigned  char verde, unsigned char azul){
  p->Azul=azul;
  p->Verde=verde;
  p->Rojo=rojo;
}
/*Funcion cambiar_tamanio_BMP_bytes:
*Descripcion: Se le cambia el tamaño al Size_of_the_BMP_file, agregando una mascara
*para poder recorrer los valores en el new_size ya que este es un entero .
*Parametros: Un puntero BMP_HEADER *t e int new_size.
*Retorno: No regesa nada.
*/
void cambiar_tamanio_BMP_bytes(BMP_HEADER *t,int new_size){
  int mascara=0x000000FF;
  for(int i=0;i<4;i++){
    t->Size_of_the_BMP_file[i]=(unsigned char)((new_size>>8*i)&mascara);
    printf("Estamos dentro de la funcion ambiar tamanio BMP :%X\n",t->Size_of_the_BMP_file[i] );
  }
  /*
  t->Size_of_the_BMP_file[0]=mascara&new_size;
  t->Size_of_the_BMP_file[1]=(new_size>>8)&mascara;
  t->Size_of_the_BMP_file[2]=(new_size>>16)&mascara;
  t->Size_of_the_BMP_file[3]=(new_size>>24)&mascara;
  */
}
/*Funcion cambiar_tamanio_DIB_HEADER:
*Descripcion: Se le cambia el tamaño al Width_in_pixels y al Height_in_pixels, agregando una mascara
*para poder recorrer los valores en el new_Width y en el new_Height, ya que este es un entero .
*Parametros: Un puntero DIB_HEADER *t, int new_Width e int new_Height.
*Retorno: No regesa nada.
*/
void cambiar_tamanio_DIB_HEADER(DIB_HEADER *t, int new_Width,int new_Height){
  int mascara=0x000000FF;
  for(int i=0;i<4;i++){
    t->Width_in_pixels[i]=(new_Width>>i*8)&mascara;
    t->Height_in_pixels[i]=(new_Height>>i*8)&mascara;
  }
}
/*Funcion cambiar_tamanio_DIB_HEADER:
*Descripcion: Se le cambia el tamaño al  Size_of_the_raw, agregando una mascara
*para poder recorrer los valores en el new_mapbit, ya que este es un entero .
*Parametros: Un puntero DIB_HEADER *t, int new_mapbit.
*Retorno: No regesa nada.
*/
void cambiar_tamnio_matriz_de_datos(DIB_HEADER *t, int new_mapbit ){
  int mascara=0x000000FF;
  for(int i=0;i<4;i++){
    t->Size_of_the_raw[i]=(unsigned char)((new_mapbit>>i*8)&mascara);
    printf("%X\n",t->Size_of_the_raw[i] );
  }
}

///tarea hacer una imagen de 3x4
