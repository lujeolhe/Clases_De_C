#ifndef WIN32_MENU_H
#define WIN32_MENU_H
///Bibliotecas del Framework WINAPI
#include <windows.h>//WINAPI o win32
#include <windowsx.h>
//Blibliotecas estandar de C/C++
#include <stdio.h>
#include <string.h>
namespace WIN32API{
  class Menu{
    HWND hwnd_padre;
    static HMENU m_menu;
    HMENU m_menupop;
    int id_lista[10];
    static const int id_fijo=500;
    static int id_cuenta;
    char m_titulo[20];
    int aux_id_cuenta;
  public:
    Menu(){
      aux_id_cuenta=0;
      m_menupop=CreateMenu();
      hwnd_padre=NULL;
    }
    virtual void pushAction(){}
    
    void agregar_submenu(char *m_nombre){
      AppendMenu(m_menupop, MF_STRING,id_fijo+id_cuenta,m_nombre);
      AppendMenu(m_menupop, MF_SEPARATOR, 0, NULL);
      id_lista[aux_id_cuenta]=id_fijo+id_cuenta;
      aux_id_cuenta++;
      id_cuenta++;
    }
    void Agregar_titulo(){
      AppendMenu(m_menu, MF_STRING | MF_POPUP, (UINT)m_menupop,m_titulo);
    }
    void InsertarMenu(){
      SetMenu (hwnd_padre, m_menu);
    }
    void set_hwnd_padre(HWND hwnd){
      hwnd_padre=hwnd;
    }
    void set_titulo(char *m_nombre){
      strcpy(m_titulo,m_nombre);
    }
    int *get_id_lista(){
      return id_lista;
    }
    int get_aux_id(){
      return aux_id_cuenta;
    }
  };
  int Menu::id_cuenta=0;
  HMENU Menu::m_menu=CreateMenu();
}
#endif
//Un objeto es una instancia de la clase.
