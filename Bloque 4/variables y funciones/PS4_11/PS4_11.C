////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Comentario
/////////////////////////
/*Mis comentarios estan en el codigo es lo que creo que va a salir*/
/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
/*Primeramente no saldra nada porque no hay funcion principal
Pero si me dice que tengo que decir cuanto sale pues lo pondre en el codigo*/

void trueque(int *x, int *y){
  int tem;
  tem=*x;
  *x=*y;
  *y=tem;
}//x= el valor de y;     Y= el valor de tem;
//asi que se se realizo un cambio de valores

int suma(int x){
  return (x+x);// dos veces el valor de x;
}

/*las llamas que estan bien son:

  3. suma(10);
  4. y=suma(10);
  6. trueque(&x,&y);*/
