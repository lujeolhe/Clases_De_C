#ifndef WIN32_AMBITOBOTTON_H
#define WIN32_AMBITOBOTTON_H
#include "Botones.hpp"
#include <time.h>
namespace WIN32API{
  class AmbitoBoton{
    char pantalla[50];
    char boton[10];
    static int bandera;
    static HWND hwndButton_panel;
    static ptrBoton ptrListaBotones[30];
    static int num_botones;
    static int num_aleatorio[11];
    static HWND DESKTOP;
    static int contrasena;
    static char codigo_boton[10];
  public:
    char *get_pantalla(){
      return pantalla;
    }
    char *get_boton(){
      return boton;
    }
    char *get_codigo_boton(){
      return codigo_boton;
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
    int get_contrasena(){
      return contrasena;
    }
    ptrBoton *get_ptrLista(){
      return ptrListaBotones;
    }
    HWND get_hwndButton_panel(){
      return hwndButton_panel;
    }
    HWND get_hwnd_desktop(){
      return DESKTOP;
    }
    void set_pantalla(char a[50]){
      strcpy(pantalla,a);
    }
    void set_boton(char a[50]){
      strcpy(boton,a);
    }
    void set_codigo_boton(char a[10]){
      strcpy(codigo_boton,a);
    }
    void set_bandera(int a){
      bandera=a;
    }
    void set_contrasena(int a){
      contrasena=a;
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
    void set_hwnd_DESkTOP(HWND hwndButton_a){
      DESKTOP=hwndButton_a;
    }
    void generarNumerosAleatorios(){
      for(int i=0;i<10;i++){
        num_aleatorio[i]=rand()%10;
      }
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
  int AmbitoBoton::contrasena=12345;
  int AmbitoBoton::num_aleatorio[11];
  char AmbitoBoton::codigo_boton[10];
  int AmbitoBoton::num_botones=0;
  HWND AmbitoBoton::hwndButton_panel=NULL;
  HWND AmbitoBoton::DESKTOP=NULL;
  ptrBoton AmbitoBoton:: ptrListaBotones[30];
};
#endif
