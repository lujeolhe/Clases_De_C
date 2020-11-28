#ifndef _OPERACIONES_EN_MATRICES
#define _OPERACIONES_EN_MATRICES
//////////////////////////////////////////
#ifndef valor_max
#define valor_max 10
#endif
/////////////////////////////////////////

void suma(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
/*Funcion Suma:
*Descripcion: Suma dos matrices bidimencionales.
*Parametros: matriztotal=matriz1+matriz2, tambien se requieren los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna.
*Retorno: No regesa nada. La suma se realiza por punteros.
*/

void resta(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
/*Funcion Resta:
*Descripcion: Suma dos matrices bidimencionales.
*Parametros: matriztotal=matriz1-matriz2, tambien se requieren los tamaños de las matrices a sumar, almacenando en Las
*             variables tam_renglon y tam_columna.
*Retorno: No regesa nada. La suma se realiza por punteros.
*/

void multiplicacion2(int matriz[][valor_max], int matriz2[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna,int tam_renglon2,int tam_columna2);
/*Funcion Multiplicacion:
*Descripcion: Multiplica dos matrices bidimencionales.
*Parametros: aux=aux+matriz[i][aux2]*matriz2[aux2][j]; matriztotal[i][j]=aux, tambien se requieren los tamaños de las matrices a multiplicar, almacenando en Las
*             variables tam_renglon y tam_columna,tam_renglon2,tam_columna2.
*Retorno: No regesa nada. La multiplicacion se realiza por punteros.
*/

void escalar(int n, int matriz[][valor_max],int matriztotal[][valor_max],int tam_renglon,int tam_columna);
/*Funcion escalar:
*Descripcion: multiplica un numero escalar con una matrices bidimencionales.
*Parametros: matriztotal[i][j]=n*matriz[i][j], tambien se requieren los tamaños de la matriz a multiplicar, almacenando en Las
*             variables tam_renglon y tam_columna.
*Retorno: No regesa nada. La funcion escalar se realiza por punteros.
*/

int determinante(int dimension,int matriz[][valor_max]);
/*Funcion determinante:
*Descripcion: reduce una matriz bidimencional y multiplica sus determinantes.
*Parametros: aux=aux+pow(-1,1+i)*matriz[0][i-1]*determinante(dimension-1, matrizAux); tambien se requieren el tamaño de la matriz a multiplicar, almacenando en Las
*             variables tam_renglon y tam_columna.
*Retorno: Si regresa. El determinante con funciones recursivas.
*/

void imprimir_matriz(int matriz[][valor_max],int tam_renglon,int tam_columna);
/*Funcion imprimir_matriz:
*Descripcion: Imprime las matrices bidimencionales.
*Parametros:   printf("%d ",matriz[i][j]); tambien se requieren los tamaños de la matriz a imprimir, almacenando en Las
*             variables tam_renglon y tam_columna.
*Retorno: No regesa nada. La Funcion imprimir_matriz se realiza por punteros.
*/
////////////////////////////////////////
void f_imprimir_matriz(FILE *f,int matriz[][valor_max],int tam_renglon,int tam_columna);
#include "operaciones_en_matrices.c"
#endif
