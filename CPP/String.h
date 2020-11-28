#include<stdio.h>
#include <string.h>
#include<stdlib.h>
namespace myNameSpace{
//Clase///////////////////////
  class String{

    //Métodos/////////////////
	  public:
       /*********************
       *Constructor base
       *********************/
       String(){
         //malloc reserva memoria en tiempo de ejecucion
         //reserva menoria
         pString=(char *)malloc(50);
           printf("Contructor por defecto\n");
        }
       /*********************
       *Constructor con parametros
       *********************/
       String(int tam){
         pString=(char *)malloc(tam);
       }

       /*********************
       *Metodos
       *********************/
       void setString(char *cadena){
         strcpy(pString,cadena);
       }
       const char *getString(){
         return pString;
       }
       int ssize(){
         //strlen tamaño de cadena
         return strlen(pString);
       }
       /*********************
       *Destructor base
       *********************/
  public:
	     ~String(){
         free(pString);
         printf("Objeto borrado\n");
       }
   //Atributos///////////////
    public:
      char *pString;
    };
  //Sobre carga de Operadores//////////////

}
