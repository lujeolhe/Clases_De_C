#ifndef WIN32_BOTTONES_H
#define WIN32_BOTTONES_H
///Bibliotecas del Framework WINAPI
#include <windows.h>//WINAPI o win32
#include <windowsx.h>
//Blibliotecas estandar de C/C++
#include <stdio.h>
#include <string.h>
//Vamos a crear un namespace llamado WIN32 porque estamos trabajando con WINAPI
namespace WIN32{
  class Rectangulo{
  private:
    int largo;
    int ancho;
  public:
    Rectangulo(){
      largo=10;
      ancho=10;
    }
    Rectangulo(int largo, int ancho){
      this->largo=largo;
      this->ancho=ancho;
    }

    int get_largo(){
      return largo;
    }
    int get_ancho(){
      return ancho;
    }
  };
  class Punto{
  private:
    int x;
    int y;
  public:
    Punto(){
      x=0;
      y=0;
    }
    Punto(int x, int y ){
      //this es apuntador a la propia clase
      this->x=x;
      this->y=y;
    }
    int get_x(){
      return x;
    }
    int get_y(){
      return y;
    }
  };
  class Boton{
    //Atributos///////////////
    private:
    Rectangulo tamanio;
    char texto[20];
    Punto posicion;
    int id_btn;
    HWND hwndButton;
    //Constantes de Clase/////
    static const int id_Botones=200;
    static int num_Boton;
    //Métodos/////////////////
    public:
       /*********************
       *Constructor base
       *********************/
       Boton(){
         num_Boton=0;
         tamanio=Rectangulo(20,20);
         strcpy(texto,"Boton");
         hwndButton=NULL;
        }
       /*********************
       *Constructor con parametros
       *********************/
       Boton(Rectangulo R, char *texto, Punto posicion, HWND hwndButton){
         num_Boton=0;
         this->tamanio=R;
         strcpy(this->texto,texto);
         this->posicion=posicion;
         this->hwndButton=hwndButton;
         id_btn=id_Botones+num_Boton;
         num_Boton++;
        }
        //Boton a(Rectangulo(25,25),"OKEY",Punto(10,10),hwndButton);
        virtual void pushAction();
        void crearBoton(HWND hwnd,HINSTANCE hInstance){
          hwndButton=CreateWindowEx(0,"BUTTON",texto,BS_PUSHBUTTON|BS_CENTER|WS_CHILD|WS_VISIBLE, posicion.get_x(),posicion.get_y(),tamanio.get_largo(),tamanio.get_ancho(),hwnd,(HMENU)id_Botones,hInstance,NULL);
        }
  };
  //Sirve para definir tipos de datos
  typedef Boton *ptrBoton;
}
#endif
