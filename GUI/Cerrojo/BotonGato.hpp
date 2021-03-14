#ifndef WIN32_BOTTONGATO_H
#define WIN32_BOTTONGATO_H
#include "AmbitoBoton.hpp"
#include <string>

namespace WIN32API{
  class BotonGato:public AmbitoBoton,public Boton{
  public:
    BotonGato(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){
      //printf("Mi id es: %d\n",get_id_btn());
    }
    void pushAction(){
      int num;
      char aux[10];
      static int bandera_int=0;
      sprintf(get_pantalla(),"");//es para concatenar
      Button_SetText(get_hwndButton_panel(),get_pantalla());
      Button_GetText(get_hwndButton_panel(),get_pantalla(),50);
      sprintf(aux,"%d",get_contrasena());//es para concatenar
      if(bandera_int==1){
        int num2;
        num2=std::stoi(get_codigo_boton(),nullptr,10);
        set_contrasena(num2);
        printf("Valor de contrasena: %d\n",get_contrasena() );
        Button_SetText(get_hwndButton_panel(),get_pantalla());
        MessageBox(get_hwnd_desktop(), /*Manejador del estritorio*/
        "Contrasena guardada con exito",/*Mensaje de la caja*/
        "Seguridad",/*Titulo*/
        MB_ICONEXCLAMATION);/*tipo de caja*/
        bandera_int=0;
        set_codigo_boton("");
      }
      if(strcmp(get_codigo_boton(),aux)==0&&bandera_int==0){
      MessageBox(get_hwnd_desktop(), /*Manejador del estritorio*/
      "Ingrese su nueva contrasena de hasta de 9 digitos",/*Mensaje de la caja*/
      "Seguridad",/*Titulo*/
      MB_ICONQUESTION);/*tipo de caja*/
      set_codigo_boton("");
      bandera_int=1;
      }
      /*
      Button_GetText(get_hwndButton(),get_boton(),6);//se lee el manejador
      sscanf(get_pantalla(),"%d",&num);*/
    }
  };
};
#endif
