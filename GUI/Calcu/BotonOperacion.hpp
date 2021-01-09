#ifndef WIN32_BOTTONOPERACION_H
#define WIN32_BOTTONOPERACION_H

#include "AmbitoBoton.hpp"

namespace WIN32API{
  class BotonOperacion:public AmbitoBoton,public Boton{
  public:
    BotonOperacion(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){}
    void pushAction(){
      char operacion;
      if(get_bandera()){
        set_bandera(0);
        set_pantalla("");
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
      Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
      //strlen: es para dar el tamanio de la cadena
      printf("Tamanio de cadena: %d\n",strlen(get_pantalla()));
      char *p=get_pantalla();
      printf("ultimo elemento de pantalla: %c\n",*(p+strlen(get_pantalla())-1));
      operacion=*(p+strlen(get_pantalla())-1);
      if(operacion=='/'||operacion=='+'||operacion=='-'||operacion=='*'){
        *(p+strlen(get_pantalla())-1)='\0';
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }//strcmp: es para comparar dos cadenas
      if(strcmp(get_pantalla(),"")==0){
        set_pantalla("0");
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
      Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
      Button_GetText(get_hwndButton(),get_boton(),6);//se lee el manejador
      strcat(get_pantalla(),get_boton());//es para concatenar
      Button_SetText(get_hwndButton_resu(),get_pantalla());
    }
  };
};
#endif
