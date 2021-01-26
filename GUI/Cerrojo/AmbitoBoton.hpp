#ifndef WIN32_AMBITOBOTTON_H
#define WIN32_AMBITOBOTTON_H
#include "Botones.hpp"
#include <time.h>
namespace WIN32API{
  class AmbitoBoton{
    char pantalla[50];
    char boton[10];
    static int bandera;
    static float ans;
    static HWND hwndButton_panel;
    static ptrBoton ptrListaBotones[30];
    static int num_botones;
    static int num_aleatorio[11];
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
    int *get_num_aleatorio(){
      return num_aleatorio;
    }
    int get_num_botones(){
      return num_botones;
    }
    ptrBoton *get_ptrLista(){
      return ptrListaBotones;
    }
    float get_ans(){
      return ans;
    }
    HWND get_hwndButton_panel(){
      return hwndButton_panel;
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
    void set_num_botones(int num){
      num_botones=num;
    }
    void set_num_aleatorio(int num,int i){
      num_aleatorio[i]=num;
    }
    void set_ptrLista(ptrBoton lis[30]){
      for(int i=0;i<30;i++){
        ptrListaBotones[i]=lis[i];
      }
    }
    void set_hwndButton_panel(HWND hwndButton_a){
      hwndButton_panel=hwndButton_a;
    }
    AmbitoBoton(){
      
      strcpy(pantalla,"");
      strcpy(boton,"");
      for(int i=0;i<10;i++){
        num_aleatorio[i]=rand()%10;
      }
    }
  };
  int AmbitoBoton::bandera=0;
  int AmbitoBoton::num_aleatorio[11];
  int AmbitoBoton::num_botones=0;
  float AmbitoBoton::ans=0;
  HWND AmbitoBoton::hwndButton_panel=NULL;
  ptrBoton AmbitoBoton:: ptrListaBotones[30];
};
#endif
