#ifndef TOrder_H
#define TOrder_H

#include <iostream>
#include <vector>
#include <random>

class TOrder{

  public:
    TOrder();
    TOrder( double A_[], int size_ );
   ~TOrder();

   void SetArray(double A_[], int size_);
   void PrintArray();
   std::vector<double> GetArray();

   void GetBySelection();
   void GetBurbuja();
   void GetInsercion();

  private:
   double *A = NULL;
   int size;
   std::vector<double> ArrayOrdenado;

   double auxiliar = 0.;
   int posicion = 0;
   int minimun = 0;

   void FillVector();



};


#endif
