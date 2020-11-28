#ifndef MYNAMESPACE_MOTOCICLETA_H
#define MYNAMESPACE_MOTOCICLETA_H
//Esto hace que no se accepten dos librerias del mismo nombre
#include<math.h>
#include<stdio.h>
#include <string.h>
#include"Vehiculos.h"
namespace myNameSpace{
//Clase///////////////////////
  class Motocicletas:public Vehiculos {

    //Métodos/////////////////
	  public:
       /*********************
       *Constructor base
       *********************/
       Motocicletas(){
          cascos=1;
           printf("Contructor por defecto\n");
        }
       /*********************
       *Constructor con parametros
       *********************/
	     Motocicletas(int ca, char *c,char *m,int v,int r,char *mo ):Vehiculos(c,m,v,r,mo){
         cascos=ca;
         printf("Contructor con enteros\n");
        }
        /*********************
        *Constructor con parametros
        *********************/
      public:
 	     Motocicletas(int ca){
          cascos=ca;
          printf("Contructor con enteros\n");
         }

       /*********************
       *Metodo para Obtener el modulo
       *********************/
     public:
       void ver_info(){
         Vehiculos::ver_info();
          printf("#Cascos: \t%d\n",cascos );
          printf("\n");
       }
       void setCascos(int c){
         cascos=c;
       }
       int getCascos(){
         return cascos;
       }
       //seters=para modificar
       //geters=para obtener
       /*********************
       *Destructor base
       *********************/
  public:
	     ~Motocicletas(){
         printf("Complejo borrado\n");
       }
   //Atributos///////////////
 private:
      int cascos;
  };
  //Sobre carga de Operadores//////////////
}
#endif
