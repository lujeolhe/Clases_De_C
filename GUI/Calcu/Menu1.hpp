#ifndef WIN32_MENU1_H
#define WIN32_MENU1_H
///Bibliotecas del Framework WINAPI
#include <windows.h>//WINAPI o win32
#include <windowsx.h>
//Blibliotecas estandar de C/C++
#include <stdio.h>
#include <string.h>
#include "Menu.hpp"
namespace WIN32API{
  class Menu1:public Menu{

  public:
    Menu1():Menu(){}
    virtual void pushAction(){
      int *lista;
      lista=get_id_lista();
      for(int i=0;i<get_aux_id();i++){

      }
    }
  };
}
#endif
void funcion1(HWND hWnd);
//Un objeto es una instancia de la clase.
