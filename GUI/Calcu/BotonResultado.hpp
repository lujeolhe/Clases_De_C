#ifndef WIN32_BOTTONRESULTADO_H
#define WIN32_BOTTONRESULTADO_H

#include "AmbitoBoton.hpp"

namespace WIN32API{
  class BotonResultado:public AmbitoBoton,public Boton{
    public:
      BotonResultado(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){}
    void pushAction(){
      int num1,num2;
      char operacion;
      float resultado;
      int bandera_int=0;
      Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
      printf("Valor de la operacion: %s\n",get_pantalla());
      char *aux_pantalla=get_pantalla();
      for(int i=0;i<strlen(get_pantalla());i++){
        if(aux_pantalla[i]=='+'||aux_pantalla[i]=='-'||aux_pantalla[i]=='*'||aux_pantalla[i]=='/'){
          bandera_int=1;
          break;
        }
      }
      if(!(aux_pantalla[strlen(get_pantalla())-1]=='+'||aux_pantalla[strlen(get_pantalla())-1]=='-'||aux_pantalla[strlen(get_pantalla())-1]=='*'||aux_pantalla[strlen(get_pantalla())-1]=='/')&&bandera_int==1){
        set_bandera(1);
        /*esta funcion es para capturar los valores del arreglo*/
        sscanf(get_pantalla(),"%d%c%d",&num1,&operacion,&num2);
        printf("Valor de num1: %d\n",num1 );
        printf("Valor de num2: %d\n",num2 );
        printf("Valor de operacion: %c\n",operacion );
        switch (operacion){
          case '+':
            resultado=num1+num2;
            break;
          case '-':
            resultado=num1-num2;
          break;
          case '*':
            resultado=num1*num2;
          break;
          case '/':
            resultado=num1/num2;
          break;
        }
        set_ans(resultado);
        printf("Valor de resultado: %.0f\n",resultado );
        sprintf(get_pantalla(),"%.0f",resultado);//funciona como printf, pero imprime en la cadenas
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
    }
  };
};
#endif
