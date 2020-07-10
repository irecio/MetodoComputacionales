#include "../inc/TVector.h"

int main(){

	TVector V1;
	V1.SetX(0.6); V1.SetY(3.8);
//	std::cout << V1.GetX()  << " " << V1.GetY() << std::endl;
//	V1.Print();
	std::cout << V1;

	TVector3 V2(5.,100.,596.);
	V2.SetZ(6000.);
//	std::cout << V2.GetX() << " "<< V2.GetZ() << std::endl;
//        V2.Print();
        std::cout << V2;

        TVector3 V3(0.,10.,56.);
        
        TVector3 V4 = V2 - V3;
        std::cout <<  V4;

       if(V2 == V3) std::cout << " Son iguales " << std::endl;
       else std::cout << " Son Diferentes " << std::endl;       

       if(V2 != V3) std::cout << " Son diferentes " << std::endl;
       else std::cout << " Son iguales " << std::endl;       




}
