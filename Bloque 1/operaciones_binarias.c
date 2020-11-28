////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int dato,mascara,clave,aux;
  dato=5;
  mascara=0x00FF;
  clave=0x0203; //
  printf("%p\n",dato );
  printf("%p\n",dato&mascara );
  printf("%p\n",dato|mascara );
  printf("%p\n",dato^mascara );
  printf("%p\t%d\n",dato>>2,dato>>2);

  aux=dato<<2;
  aux=aux^clave;
  printf("Nuestro dato encriptado es:%d\n",aux);

  aux=aux^clave;
  aux=aux>>2;
  printf("El dato desencriptado es:%d\n",aux);
}
