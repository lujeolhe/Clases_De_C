//
#ifndef FECHA_H
#define FECHA_H
#include <iostream>
#include "Naturales.hpp"
using namespace std;
namespace NUMEROS{
  class Fecha{
  public:
    Naturales dia,mes,anio;
    Fecha(){
      dia=1;
      mes=1;
      anio=2000;
    }
    Fecha(int m, int a){
      dia=1;
      if (m>12) {
        throw "Solo hay 12 meses";
      }
      this->mes=(int)m;
      anio=a;
    }
    Fecha(int d,int m,int a){
      if (d>31||d<=0) {
        throw "Solo hay 31 dias";
      }
      this->dia=(int)d;
      if (m>12) {
        throw "Solo hay 12 meses";
      }
      this->mes=(int)m;
      anio=a;
    }
    Fecha operator++(int x){
      int mes_30[7]={1,3,4,6,9,10,11};
      int mes_31[4]={5,7,8,12};
      bool fin_de_mes_30=false;
      for(int i=0;i<7;i++){
        if(mes==mes_30[i]&&dia==30){
          fin_de_mes_30=true;
          break;
        }
      }
      bool fin_de_mes_31=false;
      for(int i=0;i<4;i++){
        if(mes==mes_31[i]&&dia==31){
          fin_de_mes_31=true;
          break;
        }
      }
      if((mes==2&&dia==28)||fin_de_mes_30||fin_de_mes_31){
        mes=mes+1;
        dia=1;
        if(mes==13){
          anio=anio+1;
          mes=1;
        }
      }
      else{
        dia=dia+1;
      }
    return *this;
    }
    Fecha operator--(int x){
      if(dia==1){
      mes=mes-1;
      if(mes==0){
        mes=12;
        anio=anio-1;
      }
      switch(mes.n){
        case 1:
          dia=30;
        break;
        case 2:
          dia=28;
        break;
        case 3:
          dia=30;
        break;
        case 4:
          dia=30;
        break;
        case 5:
          dia=31;
        break;
        case 6:
          dia=30;
        break;
        case 7:
          dia=31;
        break;
        case 8:
          dia=31;
        break;
        case 9:
          dia=30;
        break;
        case 10:
          dia=30;
        break;
        case 11:
          dia=30;
        break;
        case 12:
          dia=31;
        break;
      }
    }
    else{
      dia=dia-1;
    }
    return *this;
    }
  };

  Fecha operator+(Fecha a,int b){
    Fecha c;
    for(int i=0;i<b;i++){
      a++;
    }
    c=a;
    return c;
  }
  ostream& operator<<(ostream& os,Fecha a){
    cout<<a.dia<<"/"<<a.mes<<"/";
    return os<<a.anio;
  }
};
#endif
//clase para las horas del dia
//horas del 0->24

//clase para las horas del dia
//horas del 0->24
