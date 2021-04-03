//
#ifndef HORA_H
#define HORA_H
#include <iostream>
#include "Naturales.hpp"
using namespace std;
namespace NUMEROS{
  class Hora{
  public:
    Naturales segundo,minuto,hora;
    char *turno;
    Hora(){
      segundo=1;
      minuto=1;
      hora=1;
    }
    Hora(int h,int m,int s){
      if (s>60||s<=0) {
        throw "Solo hay 60 segundos en un minuto";
      }
      this->segundo=(int)s;
      if (m>60) {
        throw "Solo hay 60 minutos en una hora";
      }
      this->minuto=(int)m;
      if (h>24) {
        throw "Solo hay 24 horas en un dia";
      }
      this->hora=(int)h;
    }
    Hora operator++(int x){
      int minuto_30=60;
      int segundo_30=60;
      bool fin_de_minuto=false;
        if(minuto==minuto_30&&segundo==60){
          fin_de_minuto=true;
        }
      bool fin_de_segundo=false;
        if(segundo==segundo_30){
          fin_de_segundo=true;
        }
      if(fin_de_minuto||fin_de_segundo){
        minuto=minuto+1;
        segundo=1;
        if(minuto==61){
          hora=hora+1;
          minuto=1;
        }
      }
      else{
        segundo=segundo+1;
      }
    return *this;
    }
    Hora operator--(int x){
      if(segundo==0){
      minuto=minuto-1;
      if(minuto==0){
        minuto=minuto-1;
        hora=hora-1;
      }
    }
    else{
      segundo=segundo-1;
    }
    return *this;
    }
  };

  Hora operator+(Hora a,int b){
    Hora c;
    for(int i=0;i<b;i++){
      a++;
    }
    c=a;
    return c;
  }
  Hora operator+(Hora a,Hora b){
    Hora c;
    c.segundo=a.segundo+b.segundo;
    c.minuto=a.minuto+b.minuto;
    c.hora=a.hora+b.hora;
    if(c.segundo==60){
      c.segundo=0;
      c.minuto=c.minuto+1;
    }
    if(c.minuto==60){
      c.minuto=0;
      c.hora=c.hora+1;
    }
    if(c.hora>24){
      c.hora=1;
    }
    return c;
  }
  ostream& operator<<(ostream& os,Hora a){
    if(a.hora>12){
      a.turno="pm";
      cout<<a.hora<<":"<<a.minuto<<":"<<a.segundo<<" ";
      return os<<a.turno;
    }
    else{
      a.turno="am";
      cout<<a.hora<<":"<<a.minuto<<":"<<a.segundo<<" ";
      return os<<a.turno;
    }
  }
};
#endif
