#include "../inc/TVector.h"

TVector::TVector(){
}

TVector::TVector(double x_, double y_): x(x_), y(y_){
}

void TVector::SetX(double x_){ x = x_; }
void TVector::SetY(double y_){ y = y_; }

double TVector::GetX(){ return x; }
double TVector::GetY(){ return y; }

std::ostream & operator << (std::ostream &out, const TVector &V){
  out << V.x << " " << V.y << std::endl;
  return out;
}

void TVector::Print(){
   std::cout << x << " " << y << std::endl;
}

TVector::~TVector(){
}

// Definicion de la clase heredada

TVector3::TVector3(){
}

TVector3::TVector3(double x_, double y_, double z_): TVector(x_,y_), z(z_){
}

void TVector3::SetZ(double z_){ z = z_;}
double TVector3::GetZ(){ return z; }

std::ostream & operator << (std::ostream &out, const TVector3 &V){
   out << V.x << " " << V.y << " " << V.z << std::endl;
   return out;  
}


TVector3 operator+( const TVector3 &V1, const TVector3 &V2 ){
   TVector3 new_( V1.x+V2.x , V1.y+V2.y, V1.z+V2.z);
   return new_;
}
TVector3 operator-( const TVector3 &V1, const TVector3 &V2 ){
   TVector3 new_( V1.x-V2.x , V1.y-V2.y, V1.z-V2.z);
   return new_;
}

bool operator==(const TVector3 &V1, const TVector3 &V2 ){
   return ( ( V1.x == V2.x ) && ( V1.y == V2.y ) && ( V1.z == V2.z ) ) ;
  // return ( ( V1.x == V2.x ) ) ; // para otro tipo de clases
}

bool operator!=(const TVector3 &V1, const TVector3 &V2 ){
   return ( ( V1.x != V2.x ) || ( V1.y != V2.y ) || ( V1.z != V2.z ) ) ;
}


void TVector3::Print(){  // Forma poco pro- de hacer las cosas
   TVector::Print();	
   std::cout << z << std::endl;
}


TVector3::~TVector3(){
}
