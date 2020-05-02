#ifndef _OPERACIONES_EN_MATRICES
#define _OPERACIONES_EN_MATRICES
//////////////////////////////////////////
#ifndef valor_max
#define valor_max 10
#endif
/////////////////////////////////////////
void suma(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
void multiplicacion2(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2);
void escalar(int n, int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
int determinante(int dimension,int matriz[][valor_max]);
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
////////////////////////////////////////
#include "operaciones_en_matrices.c"
#endif
