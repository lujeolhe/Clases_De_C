////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
#include <math.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////
void multiplo(int m,int n);
/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
int m,n;
printf("Dame dos numeros de la forma a,b\n");
scanf("%d,%d",&m,&n );
multiplo(m,n);
}
void multiplo(int m,int n){
  if(m%n==0){
    printf("%d es multplo de %d\n",m,n );
  }
  else if(n%m==0){
    printf("%d es multiplo de %d\n",n,m );
  }
  else{
    printf("%d y %d no son multiplos\n",m,n );
  }
}
