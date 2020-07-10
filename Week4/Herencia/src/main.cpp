#include "../inc/TVector.h"

int main(){

	TVector V1;
	V1.SetX(0.6); V1.SetY(3.8);
//	std::cout << V1.GetX()  << " " << V1.GetY() << std::endl;
	V1.Print();

	TVector3 V2(5.,100.,596.);
	V2.SetZ(6000.);
//	std::cout << V2.GetX() << " "<< V2.GetZ() << std::endl;
//        V2.Print();
        std::cout << V2;              





}
