#include<stdio.h>
#include"Complejos.h"
using namespace myNameSpace;

int main() {
  Complejos c;
  Complejos c2= Complejos(10,2);
  printf("%f\n",c.modulo() );
  printf("%f\n",c2.modulo() );
  c=c2+Complejos(-5,2);
  printf("%f\n",c.modulo() );
  return 0;
}
