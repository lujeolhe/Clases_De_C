#ifndef WIN32_PRUEBA_H
#define WIN32_PRUEBA_H
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
using namespace std;
class AmbitoBoton{
  char pantalla[50];
  char boton[10];
  static int bandera;
  static float ans;
  static int num_botones;
  static int num_aleatorio[11];
public:
  char *get_pantalla(){
    return pantalla;
  }
  char *get_boton(){
    return boton;
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
  float get_ans(){
    return ans;
  }
  void set_pantalla(char a[50]){
    strcpy(pantalla,a);
  }
  void set_(char a[50]){
    strcpy(boton,a);
  }
  void set_bandera(int a){
    bandera=a;
  }
  void set_ans(float a){
    ans=a;
  }
  void set_num_botones(int num){
    num_botones=num;
  }
  void set_num_aleatorio(int num,int i){
    num_aleatorio[i]=num;
  }
  AmbitoBoton(){
    strcpy(pantalla,"");
    strcpy(boton,"");
    for(int i=0;i<10;i++){
      num_aleatorio[i]=rand()%10;
    }
  }
};
int AmbitoBoton::bandera=0;
int AmbitoBoton::num_aleatorio[11];
int AmbitoBoton::num_botones=0;
float AmbitoBoton::ans=0;
class prueba{
public:
void aleatorio(AmbitoBoton b){
  int *aux=b.get_num_aleatorio();
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
    printf("\nFase %d\n",j );
    for(int i=0;i<10;i++){
      if(aux_fun[j]==aux[i]){
        printf("Este valor es igual aux_fun: %d y aux: %d\n",aux_fun[j],aux[i]);
        cont++;
      }
      else {
        printf("Este valor no es igual aux_fun: %d y aux: %d\n",aux_fun[j],aux[i]);
      }
    }
    if(cont>1){
      printf("numero que se repite: %d\n",aux_fun[j] );
      printf("Valor de cont: %d\n",cont );
      num_mas[h]=aux_fun[j];
      h++;
    }
    else if(cont==0){
      num_no[l]=aux_fun[j];
      l++;
    }
  }
  printf("Numeros no aparecen\n");
  for(int i=0;i<l;i++){
    printf(" %d\n",num_no[i]);
  }
  printf("Numeros que se repiten mas de 1 vez\n");
  for(int i=0;i<h;i++){
    printf(" %d\n",num_mas[i]);
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
      printf("Valor de f: %d\n",f );
      printf("Valor de i: %d\n",i );
      if(aux[i]==num_mas[f]){
        cont_3++;
        printf("Valor a comparar: %d\n",num_mas[f] );
          printf("Cont_3: %d\n",cont_3 );
      }
      if(cont_3>1){
        printf("Valor de aux: %d",aux[i]);
        aux[i]=num_no[v];
        printf(" a Num_no: %d\n",num_no[v]);
        v++;
        cont_3=1;
      }
    }
  }
  for(int i=0;i<10;i++){
    printf("Valores de aux: %d\n",aux[i]);
  }
}
};
#endif
int main(){
  srand(time(NULL));
  prueba a;
  AmbitoBoton b;
  a.aleatorio(b);
}
