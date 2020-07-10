#ifndef TVector_H
#define TVector_H

#include <iostream>

class TVector{
  
   public: // accesible en todos los ambitos
    TVector();
    TVector(double, double);
   ~TVector();

    void SetX(double x_);
    void SetY(double y_);

    double GetX();
    double GetY();

    virtual void Print();

    friend std::ostream & operator << (std::ostream &out, const TVector &V);


   private: // accesible solo por metodos de la misma clase

   protected: // accesible por metodos propios y por clases heredadas.

    double x;
    double y;    

};

class TVector3 : public TVector{ // Heredar todos los metodos publicos y protected de la clase madre

   public:
    TVector3();
    TVector3(double, double, double); // respetar orden cronologico
    ~TVector3();  

    void SetZ(double z_);
    double GetZ();  
    void Print();

    friend std::ostream & operator << (std::ostream &out, const TVector3 &V);


    friend TVector3 operator+( const TVector3 &V1, const TVector3 &V2 );
    friend TVector3 operator-( const TVector3 &V1, const TVector3 &V2 );
    
    friend bool operator==(const TVector3 &V1, const TVector3 &V2 );
    friend bool operator!=(const TVector3 &V1, const TVector3 &V2 ); 

    private:
     double z;    
  
};



#endif
