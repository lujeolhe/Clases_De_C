#ifndef _COMPLEJOS
#define _COMPLEJOS
#include<math.h>
#include<stdio.h>
namespace myNameSpace{
//Clase///////////////////////
  class Complejos{

    //Métodos/////////////////
	  public:
       /*********************
       *Constructor base
       *********************/
       Complejos(){
           real=0;
           imag=0;
        }
       /*********************
       *Constructor con parametros
       *********************/
	     Complejos(int r, int i){
             real=r;
             imag=i;
           }
       /*********************
       *Metodo para Obtener el modulo
       *********************/
       float modulo(){
           return sqrt(real*real+imag*imag);
       }
       /*********************
       *Destructor base
       *********************/
	     ~Complejos(){
         printf("Complejo borrado\n");
       }
   //Atributos///////////////
    public:
	    int real;
      int imag;
  };
  //Sobre carga de Operadores//////////////
  Complejos operator +(Complejos a, Complejos b)  {
   Complejos temp = Complejos(a.real+b.real, a.imag+b.imag);
   return temp;
 }

}

#endif
