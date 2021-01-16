#ifndef WIN32_BOTTONTRIGO_H
#define WIN32_BOTTONTRIGO_H
#include <math.h>
#include "AmbitoBoton.hpp"
#include <string.h>

namespace WIN32API{
  class BotonTrigo:public AmbitoBoton,public Boton{
  public:
    BotonTrigo(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){
      //printf("Mi id es: %d\n",get_id_btn());
    }
    void pushAction(){
      char senob[10];//cargarle un flotante en formato string
      char operacion_aux;//ver que operacion tiene la pantalla
      int num,num1,num2;//num1 y num2 para operacion y num para funcion seno
      char operacion;//ver que operacion se hace
      float s;//cargar el valor de las operaciones
      int bandera_int=0;//ver si en la pantalla hay una operacion
      float sen;
      Button_GetText(get_hwndButton_resu(),get_pantalla(),50);
      Button_GetText(get_hwndButton(),get_boton(),6);
      printf("Tamanio de cadena: %d\n",strlen(get_pantalla()));
      char *aux_pantalla=get_pantalla();
      for(int i=0;i<strlen(get_pantalla());i++){
        char *aux_pantalla=get_pantalla();
        if(aux_pantalla[i]=='+'||aux_pantalla[i]=='-'||aux_pantalla[i]=='*'||aux_pantalla[i]=='/'){
        //if(pantalla[i]=='+'||pantalla[i]=='-'||pantalla[i]=='*'||pantalla[i]=='/'){
          bandera_int=1;
          break;
        }
      }
      operacion_aux=aux_pantalla[strlen(get_pantalla())-1];
      if(!(aux_pantalla[strlen(get_pantalla())-1]=='+'||aux_pantalla[strlen(get_pantalla())-1]=='-'||aux_pantalla[strlen(get_pantalla())-1]=='*'||aux_pantalla[strlen(get_pantalla())-1]=='/')&&bandera_int==1){
        set_bandera(1);
        printf("Entre al ultimo if\n" );
        sscanf(get_pantalla(),"%d%c%d",&num1,&operacion,&num2);
        printf("Valor de num1: %d\n",num1 );
        printf("Valor de num2: %d\n",num2 );
        printf("Valor de operacion: %c\n",operacion );
        switch (operacion) {
          case '+':
          printf("Entre al switch\n" );
            s=num1+num2;
            break;
          case '-':
            s=num1-num2;
          break;
          case '*':
            s=num1*num2;
          break;
          case '/':
            s=num1/num2;
          break;
        }

        sen=selector_trigonometrico(s,get_boton());
        printf("Sali del switch\n" );
        printf("Sali del switc, valor sen %f\n",sen );
        sprintf(senob,"%f",sen);//funciona como printf, pero imprime en la cadenas
        set_pantalla(senob);
        Button_SetText(get_hwndButton_resu(),get_pantalla());
        printf("Despues del settex\n" );
      }

       else if(operacion_aux=='/'||operacion_aux=='+'||operacion_aux=='-'||operacion_aux=='*'){
         printf("Entre al segundo if\n" );
        set_bandera(1);
        aux_pantalla[strlen(get_pantalla())-1]='\0';
        aux_pantalla[strlen(get_pantalla())-2]='\0';
        sscanf(get_pantalla(),"%d",&num);
        printf("Valor de num: %d\n",num );
        s=selector_trigonometrico(num,get_boton());
        printf("Valor de seno: %f\n",s );
        sprintf(senob,"%f",s);
        set_pantalla(senob);
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
      else {
        printf("Entre al else\n" );
        set_bandera(1);
        sscanf(get_pantalla(),"%d",&num);
        printf("Valor de num: %d\n",num );
        s=selector_trigonometrico(num,get_boton());
        printf("Valor de seno: %f\n",s );
        sprintf(senob,"%f",s);
        set_pantalla(senob);
        Button_SetText(get_hwndButton_resu(),get_pantalla());
      }
    }
    float selector_trigonometrico(int num,char *c){
      if(strcmp(c,"sin")==0){
        return sin(num);
      }
      if(strcmp(c,"cos")==0){
        return cos(num);
      }
      if(strcmp(c,"tan")==0){
        return tan(num);
      }
      return 0;
    }
  };
};
#endif
