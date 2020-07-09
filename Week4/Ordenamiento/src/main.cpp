#include "../inc/TOrder.h"


int main(){

  double MyArray[] = {3.,5.,11.,6.,12.,9.,1.};
  int sizem = sizeof(MyArray)/sizeof(MyArray[0]);

  TOrder MyOrdenamiento;
  MyOrdenamiento.SetArray(MyArray, sizem);
 // MyOrdenamiento.PrintArray();
  MyOrdenamiento.GetBurbuja();

  srand48(8);

  double RandomArray[1000];
  for(int i = 0; i < 1000; i++)
	 RandomArray[i] = 2.*drand48();
  
  int sizer = sizeof(RandomArray)/sizeof(RandomArray[0]); 
  

  TOrder MyOrdenamiento1( RandomArray, sizer );
 // MyOrdenamiento1.PrintArray();
 // MyOrdenamiento1.GetBySelection(); 
  MyOrdenamiento1.GetInsercion(); 

  std::vector<double> Final1 = MyOrdenamiento.GetArray();
  std::vector<double> Final2 = MyOrdenamiento1.GetArray();


  for(auto it : Final2){
	std::cout << it << std::endl;
  }

  return 0;	
}
