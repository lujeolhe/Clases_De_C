#include<stdio.h>
#include"Automovil.h"
#include "Motocicletas.h"
#include<iostream>
using namespace myNameSpace;
using namespace std;

int main(){
  Vehiculos v;
  Vehiculos v2=Vehiculos("Azul","Nissa",3,2,"Solar");
  printf("\nVehiculo 1\n" );
  v.ver_info();
  printf("Vehiculo 2\n" );
  v2.ver_info();
  v2.setVentanas(4);
  v2.setRuedas(4);
  printf("Vehiculo 2\n" );
  v2.ver_info();
  string b[]={"Luis" ,"Juanita" };
  float c[]={1.5,9.4};
  for(int i=0;i<2;i++){
    cout<<""<<c[i]<<endl;
  }
  /*Automovil a;
  Automovil a2=Automovil("Automatico",1,4,4);
  Automovil a3=Automovil("Estandar",3,2,5,"Gris","Chebrolet",6,6,"Electrico");
  printf("\nAutomovil 1\n" );
  a.ver_info();
  printf("Automovil 2\n" );
  a2.ver_info();
  printf("Automovil 3\n" );
  a3.ver_info();
  Motocicletas mot;
  Motocicletas mot2=Motocicletas(2);
  Motocicletas mot3=Motocicletas(2,"Gris","Audi",0,3,"Electrico");
  printf("\nMotocicleta 1\n" );
  mot.ver_info();
  printf("Motocicleta 2\n" );
  mot2.ver_info();
  printf("Motocicleta 3\n" );
  mot3.ver_info();
  /*char t[30],c[30],m[30],mo[30];
  int b,p,as,ve,r;
  cout<<"Introduce Transmision"<<endl;
  cin>>t;
  cout<<"Introduce  Color\n";
  cin>>c;
  cout<<"Introduce Marca\n";
  cin>>m;
  cout<<"Introduce Motor\n";
  cin>>mo;
  cout<<"Introduce #Bolsas de Aire\n";
  cin>>b;
  cout<<"Introduce #Puertas\n";
  cin>>p;
  cout<<"Introduce #Asientos\n";
  cin>>as;
  cout<<"Introduce #Ventanas\n";
  cin>>ve;
  cout<<"Introduce #Ruedas\n";
  cin>>r;
  Automovil a4=Automovil(t,b,p,as,c,m,ve,r,mo);
  printf("Automovil 4\n" );
  a4.ver_info();*/

//  printf("El color es: %s\n",a.getColor() );
}
