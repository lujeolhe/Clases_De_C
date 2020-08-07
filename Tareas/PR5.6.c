/*Problema PR5.6
Busqueda Binaria. La busqueda binaria consiste en dividir el intervalo de busqueda en dos partes,
comparando el elemento buscado con el central. En caso de ser diferentes se redefinen los extremos
del intervalo, segun sea el elemento central mayor o menor que el buscado, disminuyendo de esta forma
el espacio de busqueda. El proceso concluye cuando el elemento es encontrado, o bien, cuando el intervalo
de busqueda se anula. Esto implica que  el elemento no se encuentra en el arreglo. Cabe destacar que el
metodo funciona unicamente para arreglos ordenados. Con cada iteracion del metodo, el espacio de busqueda
se reduce a la mitad, por lo tanto, el numero de comparaciones que se deben realizar disminuya notablemente.
Esta disminucion resulta mas significativa cuanto mas grnade es el tamaño del arreglo.*/
////////////////////////
//Librerias
/////////////////////////
#include <stdio.h>
/////////////////////////
//Definiciones
/////////////////////////
#define tam_max 100
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
  int n;
  printf("Cuantos numeros quieres poner \n" );
  scanf("%d",&n );

  int a[tam_max];
  for(int i=0;i<100;i++){
    a[i]=0;
  }

  printf("Dame los numeros de la forma a,b\n" );
  for(int i=0;i<n;i++){
    scanf("%d,",&a[i] );
  }

  int i=0;
  while(i<n-1){
    int aux=0;
    if(a[i]>a[i+1]){
      aux=a[i];
      a[i]=a[i+1];
      a[i+1]=aux;
      i=0;
    }
    else{
      i++;
    }
  }

  for(int i=0;i<n;i++){
    printf("%d ",a[i] );
  }
  printf("\n" );

  int buscar;
  printf("Que numero quieres buscar\n" );
  scanf("%d",&buscar );

  int tam=n;
  int tam_aux=0;
  while(1){
    if((tam/2)>n||(tam/2)<0){
        printf("No esta\n" );
        break;
    }
    else{
       if(buscar==a[tam/2]){
        printf("Si esta\n" );
        break;
        }
      else{
        if(buscar<a[tam/2]){
          if(tam_aux!=(tam/2-1)*2){
              tam_aux=tam;
              tam=(tam/2-1)*2;
        }
          else{
            printf("No esta\n" );
            break;
          }
        }
        else{
          if(buscar>a[tam/2]){
            if(tam_aux!=(tam/2+1)*2){
                tam_aux=tam;
                tam=(tam/2+1)*2;
          }
            else{
              printf("No esta\n" );
              break;
            }
          }
        }
      }
    }
  }
}
