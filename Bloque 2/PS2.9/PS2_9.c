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
  int opc,opc2,opc3,opc4;
  float n,m,j,aux=0,aux2=0,aux3=0;
  printf("Dime que es lo que quieres convertir\n" );
  printf("1.- Medidas de Longitud\n" );
  printf("2.- Medidas de Volumen\n" );
  printf("3.- Medidas de Peso\n" );
  scanf("%d",&opc );
  switch (opc) {
      case 1:
        printf("Dime que es lo que quieres convertir\n" );
        printf("1.- pulgadas a milimetros\n" );
        printf("2.- yardas a metros\n" );
        printf("3.- millas a kilometros\n" );
        printf("4.- pulgadas cuadradas a centrimetros cuadrados\n" );
        printf("5.- pies cuadrados a metros cuadrados\n" );
        printf("6.- yardas cuadradas a metros cuadrados\n" );
        printf("7.- acres a hectareas cuadradas\n" );
        printf("8.- millas cuadradas a kilometros cuadrados\n" );
        printf("9.- Salir\n" );
        scanf("%d",&opc2 );
        switch (opc2) {
          case 1:
          printf("Dime cuantas pulgadas quieres convertir\n");
          scanf("%f",&n );
          aux=n*25.40;
          printf("Son: %.3f milimetros\n",aux );
          break;
          case 2:
          printf("Dime cuantas yardas quieres convertir\n");
          scanf("%f",&n );
          aux=n*0.9144;
          printf("Son: %.3f metros\n",aux );
          break;
          case 3:
          printf("Dime cuantas millas quieres convertir\n");
          scanf("%f",&n );
          aux=n*1.6093;
          printf("Son: %.3f kilometros\n",aux );
          break;
          case 4:
          printf("Dime cuantas pulgadas cuadradas quieres convertir\n");
          scanf("%f",&n );
          aux=n*6.452;
          printf("Son: %.3f centrimetros cuadrados\n",aux );
          break;
          case 5:
          printf("Dime cuantas pies cuadrados quieres convertir\n");
          scanf("%f",&n );
          aux=n*0.09290;
          printf("Son: %.3f metros cuadrados\n",aux );
          break;
          case 6:
          printf("Dime cuantas yardas cuadradas quieres convertir\n");
          scanf("%f",&n );
          aux=n*0.8361;
          printf("Son: %.3f metros cuadrados\n",aux );
          break;
          case 7:
          printf("Dime cuantas acres quieres convertir\n");
          scanf("%f",&n );
          aux=n*0.4047;
          printf("Son: %.3f hectareas cuadradas\n",aux );
          break;
          case 8:
          printf("Dime cuantas millas cuadradas quieres convertir\n");
          scanf("%f",&n );
          aux=n*2.59;
          printf("Son: %.3f kilometros cuadrados\n",aux );
          break;
          default:
          break;
        }
      break;
      case 2:
        printf("Dime que es lo que quieres convertir\n" );
        printf("1.- pies cubicos a metros cubicos\n" );
        printf("2.- yardas cubicas a metros cubicos\n" );
        printf("3.- pintas a litros\n" );
        printf("4.- galones a  litros\n" );
        printf("5.- Salir\n" );
        scanf("%d",&opc3 );
        switch (opc3) {
          case 1:
          printf("Dime cuantas pies cubicos quieres convertir\n");
          scanf("%f",&j );
          aux2=j*0.02832;
          printf("Son: %.3f metros cubicos\n", aux2);
          break;
          case 2:
          printf("Dime cuantas yardas cubicas quieres convertir\n");
          scanf("%f",&j);
          aux2=j*0.7646;
          printf("Son: %.3f metros cubicos\n", aux2);
          break;
          case 3:
          printf("Dime cuantas pinta quieres convertir\n");
          scanf("%f",&j );
          aux2=j*0.56826;
          printf("Son: %.3f litros\n", aux2);
          break;
          case 4:
          printf("Dime cuantas galon quieres convertir\n");
          scanf("%f",&j );
          aux2=j*4.54609;
          printf("Son: %.3f litros\n",aux2 );
          break;
          default:
          break;
        }
      break;
      case 3:
        printf("Dime que es lo que quieres convertir\n" );
        printf("1.- onzas a gramos\n" );
        printf("2.- libras a kilos\n" );
        printf("3.- toneladas inglesas a toneladas metricas\n" );
        printf("4.- Salir\n" );
        scanf("%d",&opc4 );
        switch (opc4) {
          case 1:
          printf("Dime cuantas onzas quieres convertir\n");
          scanf("%f",&m );
          aux3=m*28.35;
          printf("Son: %.3f gramos\n",aux3 );
          break;
          case 2:
          printf("Dime cuantas libras quieres convertir\n");
          scanf("%f",&m );
          aux3=m*0.45359;
          printf("Son: %.3f kilogramos\n",aux3 );
          break;
          case 3:
          printf("Dime cuantas toneladas inglesas quieres convertir\n");
          scanf("%f",&m );
          aux3=m*1.01604;
          printf("Son: %.3f toneladas metricas\n",aux3 );
          break;
          default:
          break;
        }
      break;
      default:
      break;
  }
}
