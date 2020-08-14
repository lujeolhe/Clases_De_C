////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
/////////////////////////
//Definiciones
/////////////////////////

/////////////////////////
//Estructuras
/////////////////////////

/////////////////////////
//Declaracion de Funciones
/////////////////////////

/////////////////////////
//Funcion Principal
/////////////////////////
int main(){
  int n,m=0,c=0,d=0,u=0;
  printf("Dame un numero de 4 digitos\n" );
  scanf("%d",&n );
  printf("\n" );
  m=n/1000;
  c=(n%1000)/100;
  d=(n%100)/10;
  u=n%10;
  if(m%2==0&&c%2==0){
    if(d%2==0&&u%2==0){
      printf("Todos los digitos son pares \n" );
    }
    else if(d%2!=0){
      if(u%2!=0){
        printf("Solo %d y %d son pares\n",m,c );
      }
      else{
        printf("El numero %d no es par\n", d);
      }
    }
    else if(u%2!=0){
      printf("El numero %d no es par\n", u);
    }
  }
  else if(m%2!=0){
    if(c%2!=0){
      if(d%2!=0&&u%2!=0){
        printf("Ninguno de los digitos es par\n" );
      }
      else if(d%2==0){
        if(u%2!=0){
          printf("Solo el %d es par\n",d );
        }
        else{
          printf("Solo %d y %d son pares\n",d,u );
        }
      }
      else if(u%2==0){
        printf("Solo  %d es par\n",u );
      }
    }
      else if(c%2==0){
            if(d%2!=0&&u%2!=0){
              printf("Solo %d es par\n",c );
            }
            else if(d%2==0){
              if(u%2!=0){
                printf("Solo %d y %d son pares\n",c,d );
              }
              else{
                printf("Solo el %d no es par\n",m);
              }
            }
          }
        }
  else if(m%2==0){
        if(c%2==0){
          if(d%2!=0&&u%2!=0){
            printf("Solo %d es par\n",m );
          }
          else if(d%2==0){
            if(u%2!=0){
              printf("Solo %d y %d son pares\n",m,d );
            }
            else if(u%2==0){
              printf("Solo %d y %d son pares\n",m,u);
            }
          }
        }
      }
}
