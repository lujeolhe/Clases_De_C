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
           printf("Contructor por defecto\n");
        }
       /*********************
       *Constructor con parametros
       *********************/

	     Complejos(int r, int i){
             real=r;
             imag=i;
             printf("Contructor con enteros\n");
           }
       /*********************
       *Constructor con parametros
       *********************/
   public:
       Complejos(int mag, float angle){
             real=mag*cos(angle);
             imag=mag*sin(angle);
             printf("Contructor con angulo\n");
           }
       /*********************
       *Constructor con parametros
       *********************/
   public:
       Complejos(float a, int b){
             real=a;
             imag=b;
             printf("Contructor con un foltante y un entero\n");
           }
        /*********************
        *Constructor con parametros
        *********************/
      public:
        Complejos(float a,float b){
          real=a;
          imag=b;
          printf("Contructor con flotantes\n");
        }
       /*********************
       *Metodo para Obtener el modulo
       *********************/
       float modulo(){
           return sqrt(real*real+imag*imag);
       }
       float angulo(){
         return atan(imag/real);
       }
       /*********************
       *Destructor base
       *********************/
  public:
	     ~Complejos(){
         printf("Complejo borrado\n");
       }
   //Atributos///////////////
    public:
	    float real;
      float imag;
  };
  //Sobre carga de Operadores//////////////
  Complejos operator +(Complejos a, Complejos b)  {
   Complejos temp = Complejos(a.real+b.real, a.imag+b.imag);
   return temp;
 }
  Complejos operator *(Complejos a, Complejos b){
   Complejos temp=Complejos(a.real*b.real,a.real*b.imag);
   return temp;
 }

}

//#endif
