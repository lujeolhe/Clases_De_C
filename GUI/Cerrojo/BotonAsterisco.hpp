#ifndef WIN32_BOTTONASTERISCO_H
#define WIN32_BOTTONASTERISCO_H
#include "AmbitoBoton.hpp"
#include <string>

namespace WIN32API{
  class BotonAsterisco:public AmbitoBoton,public Boton{
  public:
    BotonAsterisco(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){
      //printf("Mi id es: %d\n",get_id_btn());
    }
    void pushAction(){
      int num;
      char aux[10];
      sprintf(get_pantalla(),"");//es para concatenar
      Button_SetText(get_hwndButton_panel(),get_pantalla());
      Button_GetText(get_hwndButton_panel(),get_pantalla(),50);
      sprintf(aux,"%d",get_contrasena());//es para concatenar
      if(strcmp(get_codigo_boton(),aux)==0){
      MessageBox(get_hwnd_desktop(), /*Manejador del estritorio*/
      "Bienvenido a casa",/*Mensaje de la caja*/
      "Seguridad",/*Titulo*/
      MB_ICONQUESTION);/*tipo de caja*/
      set_codigo_boton("");
      }
      else{
        MessageBox(get_hwnd_desktop(), /*Manejador del estritorio*/
        "Acceso no autorizado",/*Mensaje de la caja*/
        "Seguridad",/*Titulo*/
        MB_ICONERROR);/*tipo de caja*/
        set_codigo_boton("");
      }
    }
  };
};
#endif
