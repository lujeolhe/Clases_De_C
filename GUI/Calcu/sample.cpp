#include <stdio.h>

#include "Botones.hpp"
using namespace WIN32API;
void func_sample(Rectangulo r);

int main() {
  Rectangulo *r;
  r=new Rectangulo(50,120);
  func_sample(*r);
  return 0;
}

void func_sample(Rectangulo r){
  printf("%d, %d\n",r.get_largo(),r.get_ancho() );
}
