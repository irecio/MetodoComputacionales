#include <iostream>
#include "../inc/cambiar.h"
#include "../inc/cambiarpointer.h"

int main(){

  double a = 5.;
  std::cout << " variable global " << &a << std::endl;

  double *ptr = &a;

  CambiarValor(a);
  CambiarPointer(ptr);

  std::cout << a << std::endl;


return 0;
}

