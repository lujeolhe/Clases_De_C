#ifndef MYNAMESPACE_AUTOMOVIL_H
#define MYNAMESPACE_AUTOMOVIL_H
#include<math.h>
#include<stdio.h>
#include <string.h>
#include "Vehiculos.h"
namespace myNameSpace{
//Clase///////////////////////
///Herencia-para que una clase herede lo de otras se hace esto///
  class Automovil:public Vehiculos{

    //Métodos/////////////////
	  public:
       /*********************
       *Constructor base
       *********************/
       Automovil(){
          strcpy(transmision,"Estandar");
          bolsasAire=2;
          puertas=4;
          asientos=6;
           printf("Contructor por defecto\n");
        }
       /*********************
       *Constructor con parametros
       *********************/
       Automovil(char *t,int b,int p,int a){
          strcpy(transmision,t);
          bolsasAire=b;
          puertas=p;
          asientos=a;
           printf("Contructor por valores\n");
        }

       /*********************
       *Constructor con parametros
       *********************/
   public:
      //para usar los constructores del padre se hace esto//
     Automovil(char *t,int b,int p,int a,char *c,char *m,int v,int r,char *mo):Vehiculos(c,m,v,r,mo){
       strcpy(transmision,t);
       bolsasAire=b;
       puertas=p;
       asientos=a;
     }
       /*********************
       *Constructor con parametros
       *********************/
   public:

        /*********************
        *Constructor con parametros
        *********************/
    public:

       /*********************
       *Metodo para Obtener el modulo
       *********************/
      void ver_info(){
        //polimorfismo-para poder imprimir la anterior clase//
        Vehiculos::ver_info();
        printf("Transmision: \t%s\n",transmision );
        printf("Bolsas Aire: \t%d\n",bolsasAire );
        printf("#Puertas: \t%d\n",puertas );
        printf("#Asientos: \t%d\n",asientos );
        printf("\n" );
       }
       void setTransmision(char *t){
         strcpy(transmision,t);
       }
       void setBolsasAire(int ba){
         bolsasAire=ba;
       }
       void setPuertas(int p){
         puertas=p;
       }
       void setAsientos(int a){
         asientos=a;
       }
       char *getTransmision(){
         return  transmision;
       }
       int getBolsasAire(){
         return  bolsasAire;
       }
       int getPuertas(){
         return  puertas;
       }
       int getAsientos(){
         return  asientos;
       }
       /*********************
       *Destructor base
       *********************/
  public:
	     ~Automovil(){
         printf("Complejo borrado\n");
       }
   //Atributos///////////////
 private:
      char transmision[30];
      int bolsasAire;
      int puertas;
      int asientos;
  };
  //Sobre carga de Operadores//////////////
}
#endif
