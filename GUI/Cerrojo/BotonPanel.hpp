#ifndef WIN32_BOTTONPANEL_H
#define WIN32_BOTTONPANEL_H

#include "AmbitoBoton.hpp"
#include <time.h>
namespace WIN32API{
  class BotonPanel:public AmbitoBoton,public Boton{
    public:
    BotonPanel(Rectangulo R, char *texto, Punto posicion, HWND hwndButton):Boton(R,texto,posicion,hwndButton){}
    void pushAction(){
      srand(time(NULL));
      char num_aux[11];
      int *aux=get_num_aleatorio();
      for(int i=0;i<10;i++){
        printf("Valor aux en panel: %d\n",aux[i]);
      }
      aleatorio(aux);
      for(int i=0;i<10;i++){
        printf("Valor aux en panel depues de aleatorio: %d\n",aux[i]);
      }
      for(int i=0;i<=get_num_botones();i++){
        printf("Valor aux en panel depues de aleatorio dentro del otro for: %d\n",aux[i]);
        printf("Numero botones: %d\n",get_num_botones() );
        ptrBoton *resultado=get_ptrLista();
        sprintf(num_aux,"%d",aux[i]);
        //printf("Valor: %s\n",((resultado[i])->get_texto()));
        resultado[i]->set_texto(num_aux);
      }
    }
    void aleatorio( int *aux){
      int num_no[11];
      int num_mas[11];
      printf("Antes\n");
      for(int i=0;i<10;i++){
        printf("Valores de aux: %d\n",aux[i]);
      }
      for(int i=0;i<10;i++){
        num_no[i]=0;
        num_mas[i]=0;
      }
      printf("\n\n");
      int aux_fun[11];
      for(int i=0;i<10;i++){
        aux_fun[i]=i;
      }
      int l=0;
      int h=0;
      int h_2[11];
      for(int j=0;j<10;j++){
        int cont=0;
        for(int i=0;i<10;i++){
          if(aux_fun[j]==aux[i]){
            cont++;
          }
          else {
          }
        }
        if(cont>1){
          num_mas[h]=aux_fun[j];
          h++;
        }
        else if(cont==0){
          num_no[l]=aux_fun[j];
          l++;
        }
      }
      remplazar(h,l,aux,num_mas,num_no);
    }
    void remplazar(int mas, int no, int aux[], int num_mas[],int num_no[]){
      int cont_2=0;
      int cont_3=0;
      for(int f=0,v=0;f<mas,v<no;f++){
          cont_2=0;
          cont_3=0;
        for(int i=0;i<10;i++){
          if(aux[i]==num_mas[f]){
            cont_3++;
          }
          if(cont_3>1){
            aux[i]=num_no[v];
            v++;
            cont_3=1;
          }
        }
      }
      printf("Despues \n");
      for(int i=0;i<10;i++){
        set_num_aleatorio(aux[i],i);
        printf("Valores de aux: %d\n",aux[i]);
      }
    }
  };
};
#endif
