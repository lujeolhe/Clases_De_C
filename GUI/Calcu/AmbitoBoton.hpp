#ifndef WIN32_AMBITOBOTTON_H
#define WIN32_AMBITOBOTTON_H
#include "Botones.hpp"

namespace WIN32API{
  class AmbitoBoton{
    char pantalla[50];
    char boton[10];
    static int bandera;
    static float ans;
    static HWND hwndButton_resu;
  public:
    char *get_pantalla(){
      return pantalla;
    }
    char *get_boton(){
      return boton;
    }
    int get_bandera(){
      return bandera;
    }
    float get_ans(){
      return ans;
    }
    HWND get_hwndButton_resu(){
      return hwndButton_resu;
    }
    void set_pantalla(char a[50]){
      strcpy(pantalla,a);
    }
    void set_(char a[50]){
      strcpy(boton,a);
    }
    void set_bandera(int a){
      bandera=a;
    }
    void set_ans(float a){
      ans=a;
    }
    void set_hwndButton_resu(HWND hwndButton_a){
      hwndButton_resu=hwndButton_a;
    }
    AmbitoBoton(){
      static int numerodeobjetos=0;
      strcpy(pantalla,"");
      strcpy(boton,"");
      numerodeobjetos++;
      printf("Valor de numerodeobjetos: %d\n",numerodeobjetos);
    }
  };
  int AmbitoBoton::bandera=0;
  float AmbitoBoton::ans=0;
  HWND AmbitoBoton::hwndButton_resu=NULL;
};
#endif
