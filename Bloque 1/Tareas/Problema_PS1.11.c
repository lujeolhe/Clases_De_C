///////////////////////
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
  float radio,gene,altura;
  printf("Dame el radio, la generatriz y la altura del Cono\n" );
  printf("Radio: " );
  scanf("%f",&radio);
  printf("Generatriz: " );
  scanf("%f",&gene);
  printf("Altura: " );
  scanf("%f",&altura);
  float Ab,Al,At,Vol;
  Ab=3.1416*radio*radio;
  Al=3.1416*radio*gene;
  At=Ab+Al;
  Vol=(Ab*altura)/3;
  printf("El Area de la Base es: %.2f u^2\n",Ab);
  printf("El Area Lateral es: %.2f u^2\n",Al);
  printf("El Area Total es: %.2f u^2\n",At);
  printf("El Volumen es: %.2f u^3\n",Vol);
}
