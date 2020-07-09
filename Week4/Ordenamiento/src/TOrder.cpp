#include "../inc/TOrder.h"

TOrder::TOrder(){
}

TOrder::TOrder( double A_[], int size_ ): size(size_){

   A = new double[size];
    for(int i = 0; i < size; i++){
    	A[i] = A_[i];
   }

}

void TOrder::SetArray(double A_[], int size_){

  size = size_;
  A = new double[size];
  for(int i = 0; i < size; i++)
	A[i] = A_[i];  

}

void TOrder::PrintArray(){

  if(A == nullptr){
    std::cout << " Array empty " << std::endl;
  } 
  else{
  for(int i = 0; i < size; i++)
 	std::cout << A[i] << std::endl;
  }

}

std::vector<double> TOrder::GetArray(){
  return ArrayOrdenado;
}

void TOrder::FillVector(){

  for(int i = 0; i < size; i++){
	ArrayOrdenado.push_back(A[i]);
  }

}

void TOrder::GetBySelection(){

  std::cout << " --- Running by selection --- " << std::endl;

  for(int i = 0; i < size; i++){
   minimun = i; // suponemos que el primero es el menor
   	for(int j = i+1; j < size; j++){
           if(A[j] < A[minimun]){
             minimun = j;
           }		   
   	}
   	auxiliar = A[i];
   	A[i] = A[minimun];
   	A[minimun] = auxiliar;   
  }
  TOrder::FillVector();

}

void TOrder::GetBurbuja(){

   std::cout << " --- Running bubble sort --- " << std::endl;

   for(int i = 0; i < size; i++){

     for(int j = 0; j < size; j++){

     	 if(A[i] < A[j]){
     	 	auxiliar = A[i];
     	 	A[i] = A[j];
     	 	A[j] = auxiliar;
     	 }
     }

   }
   TOrder::FillVector();

}

void TOrder::GetInsercion(){

	std::cout << " --- Running by insertion --- " << std::endl;

    for(int i = 0; i < size; i++){
        posicion = i;
        auxiliar = A[i];

        while( (posicion > 0) && (A[posicion-1] > auxiliar) ){
        	A[posicion] = A[posicion-1];
        	posicion--;
        	//std::cout << i << "  "<<  A[posicion-1] <<std::endl;
        }
        A[posicion] = auxiliar;

    }
    TOrder::FillVector();
}


TOrder::~TOrder(){
}
