#ifndef _PILA_HPP
#define _PILA_HPP

namespace ESTRUCTURAS{ //Nombres de espacio siempre con Mayusculas
  class Pila{ //Clases Simepre con la primera letra en Mayuscula
    private:
        //Puntero a la pila
        int *pPila;
        // entero para guardar el tamaño de la pila
        int tamanio;
        // entero para el indice de la Pila
        int index;
    public:
      //El constructor por defecto genera una pila de 10 espacios
      Pila();
      //El constructor genera una pila de X espacios
      Pila(int x);

      //Meter elementos en la pila
      void push(int x);
      //Sacar elementos de la pila
      int pop();
      //Obtener el tamaño de mi pila
      int getTamanio();
      ~Pila();
  };
}

#include  "../source/Pila.cpp"
#endif
