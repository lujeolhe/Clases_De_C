#include<stdio.h>
#include"Complejos.h"
using namespace myNameSpace;

int main() {
  Complejos c;
  Complejos c2= Complejos(10,2);
  Complejos c3=c2+3;
  printf("%f\n",c.modulo() );
  printf("%f\n",c2.modulo() );
  c=c2*c3;
  printf("%f,%f\n",c.real,c.imag );
  c=c2+Complejos(-5,2);
  printf("%f\n",c.modulo() );
  printf("%.2f|%f\n",c.modulo(),c.angulo());
  printf("%f,%f\n",c3.real,c3.imag );
  return 0;
}
