/////////////////////////
//Librerias
/////////////////////////
#include<stdio.h>
/////////////////////////
//Prototipos de Func
/////////////////////////

/////////////////////////
// MAIN
/////////////////////////
int main(){
  char  cadena3[50];
	printf("Escribe tu frase: \n");

  for(int i=0;i<=50;i++){
    cadena3[i]=0;
  }

  gets(cadena3);

  int cuenta_espacios=0,principio_palabra=0,fin_palabra=0;
  for(int i=0;i<50;i++){
    if(cadena3[i]==32){
      cuenta_espacios++;
      fin_palabra=i-1;
      if(((cadena3[principio_palabra]>=65&&cadena3[principio_palabra]<=90) || (cadena3[principio_palabra]>=97&&cadena3[principio_palabra]<=122)) &&
         ((cadena3[fin_palabra]>=65&&cadena3[fin_palabra]<=90) || (cadena3[fin_palabra]>=97&&cadena3[fin_palabra]<=122))){

             printf("La palabra %d tiene: %d letras\n",cuenta_espacios,fin_palabra-principio_palabra+1 );
         }
         else{
            printf("La palabra %d tiene: %d letras\n",cuenta_espacios,fin_palabra-principio_palabra );
         }

      principio_palabra=i+1;
    }
    if(cadena3[i]==0){
      fin_palabra=i-1;
      if(((cadena3[principio_palabra]>=65&&cadena3[principio_palabra]<=90) || (cadena3[principio_palabra]>=97&&cadena3[principio_palabra]<=122)) &&
         ((cadena3[fin_palabra]>=65&&cadena3[fin_palabra]<=90) || (cadena3[fin_palabra]>=97&&cadena3[fin_palabra]<=122))){

        printf("La palabra %d tiene: %d letras\n",cuenta_espacios+1,fin_palabra-principio_palabra+1 );
      }
      else{
         printf("La palabra %d tiene: %d\n",cuenta_espacios+1,fin_palabra-principio_palabra);
      }
      break;
    }

    //printf("%d:  %d:\n",i, cadena3[i] );
  }
  int cuenta_letras=0;
  for(int a=0;a<50;a++){
    if((cadena3[a]>=65&&cadena3[a]<=90) || (cadena3[a]>=97&&cadena3[a]<=122)){
      if(cadena3[a]>=65&&cadena3[a]<=90){
        cadena3[a]=cadena3[a]+32;
      }

      else{
        cadena3[a]=cadena3[a]-32;
      }
      cuenta_letras++;
    }
  }


  printf("El numero de palabras es: %d\n",cuenta_espacios+1 );
  printf("El numero de letras total es: %d\n",cuenta_letras );
  printf("La nueva cadeana es: %s\n",cadena3 );



}
