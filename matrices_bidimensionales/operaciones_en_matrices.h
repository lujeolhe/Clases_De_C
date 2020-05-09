#ifndef _OPERACIONES_EN_MATRICES
#define _OPERACIONES_EN_MATRICES
//////////////////////////////////////////
#ifndef valor_max
#define valor_max 10
#endif
/////////////////////////////////////////
/*Funcion Suma:
*Descripcion: Suma dos matrices bidimnecionales
*Parametros: matriztotal=matriz1+matriz2, tambien se requieresn los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna
*Retorno: No regesa nada. La suma se realiza por punteros.
*/
void suma(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
/*Funcion Suma:
*Descripcion: Suma dos matrices bidimnecionales
*Parametros: matriztotal=matriz1+matriz2, tambien se requieresn los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna
*Retorno: No regesa nada. La suma se realiza por punteros.
*/
void multiplicacion2(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2);
/*Funcion Suma:
*Descripcion: Suma dos matrices bidimnecionales
*Parametros: matriztotal=matriz1+matriz2, tambien se requieresn los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna
*Retorno: No regesa nada. La suma se realiza por punteros.
*/
void escalar(int n, int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
/*Funcion Suma:
*Descripcion: Suma dos matrices bidimnecionales
*Parametros: matriztotal=matriz1+matriz2, tambien se requieresn los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna
*Retorno: No regesa nada. La suma se realiza por punteros.
*/
int determinante(int dimension,int matriz[][valor_max]);
/*Funcion Suma:
*Descripcion: Suma dos matrices bidimnecionales
*Parametros: matriztotal=matriz1+matriz2, tambien se requieresn los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna
*Retorno: No regesa nada. La suma se realiza por punteros.
*/
void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
////////////////////////////////////////
void f_imprimir_matriz(FILE *f,int matriz[][valor_max],int tam_renglon,int tam_columna);
#include "operaciones_en_matrices.c"
#endif
