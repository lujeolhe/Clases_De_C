#ifndef MYNAMESPACE_VEHICULOS_H
#define MYNAMESPACE_VEHICULOS_H
#include<math.h>
#include<stdio.h>
#include <string.h>
namespace myNameSpace{
//Clase///////////////////////
  class Vehiculos{

    //Métodos/////////////////
	  public:
       /*********************
       *Constructor base
       *********************/
       Vehiculos(){
          strcpy(color,"Blanco");
          strcpy(marca,"Toyota");
          ventanas=4;
          ruedas=4;
          strcpy(motor,"Gasolina");
           printf("Contructor por defecto\n");
        }
       /*********************
       *Constructor con parametros
       *********************/
	     Vehiculos(char *c,char *m,int v,int r,char *mo ){
         strcpy(color,c);
         strcpy(marca,m);
         ventanas=v;
         ruedas=r;
         strcpy(motor,mo);
         printf("Contructor con enteros\n");
        }

       /*********************
       *Metodo para Obtener el modulo
       *********************/
       void ver_info(){
          printf("Color: \t%s\n",color );
          printf("Marca: \t%s\n",marca );
          printf("#Ventanas: \t%d\n",ventanas );
          printf("#Ruedas: \t%d\n",ruedas );
          printf("Motor: \t%s\n",motor );
          printf("\n");
       }
       void setColor(char *c){
         strcpy(color,c);
       }
       void setMarca(char *m){
         strcpy(color,m);
       }
       void setVentanas(int v){
         ventanas=v;
       }
       void setRuedas(int r){
         ruedas=r;
       }
       void setMotor(char *mo){
         strcpy(color,mo);
       }
       char *getColor(){
         return  color;
       }
       char *getMarca(){
         return  marca;
       }
       int getVentanas(){
         return  ventanas;
       }
       int getRuedas(){
         return  ruedas;
       }
       char *getMotor(){
         return  motor;
       }
       //seters=para modificar
       //geters=para obtener
       /*********************
       *Destructor base
       *********************/
  public:
	     ~Vehiculos(){
         printf("Complejo borrado\n");
       }
   //Atributos///////////////
 private:
      char color[30];
      char marca[30];
      int ventanas;
      int ruedas;
      char motor[30];
  };
  //Sobre carga de Operadores//////////////
}
#endif
//tarea
//todos lo metodos estaticos del problema 5 de la tarea 2
