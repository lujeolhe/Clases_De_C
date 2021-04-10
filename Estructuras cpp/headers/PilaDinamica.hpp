#ifndef _PILADINAMICA_HPP
#define _PILADINAMICA_HPP
#include <iostream>
namespace ESTRUCTURAS{ //Nombres de espacio siempre con Mayusculas
  class Nodo{
  public:
    Nodo();
    Nodo(int x);
      //Puntero a la PilaDinamica
      Nodo *siguiente;
      // entero para el indice de la PilaDinamica
      int valor;

      int getSiguinte();
  };
  class PilaDinamica{ //Clases Simepre con la primera letra en Mayuscula
    private:
        //Puntero a la PilaDinamica
        Nodo *cabeza;
        // entero para guardar el tamaño de la PilaDinamica
        int tamanio;
        // entero para el indice de la PilaDinamica
        int index;
    public:
      //El constructor por defecto genera una PilaDinamica de 10 espacios
      PilaDinamica();
      //El constructor genera una PilaDinamica de X espacios
      PilaDinamica(int x);
      //Meter elementos en la PilaDinamica
      void push(int x);
      //Sacar elementos de la PilaDinamica
      int pop();
      //Obtener el tamaño de mi PilaDinamica
      int getTamanio();

      Nodo *getpPilaDinamica();

      int getIndex();
      ~PilaDinamica();
  };
}

#include  "../source/PilaDinamica.cpp"
#include  "../source/Nodo.cpp"
#endif
