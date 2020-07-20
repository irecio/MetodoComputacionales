#ifndef Particle_H
#define Particle_H

#include <iostream>
#include <fstream>
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include <utility>
#include <vector>
#include <random>

class Particle{

	public:

	Particle(double x_, 
		 double y_, 
		 double vx_, 
		 double vy_, 
		 double m_, 
		 double r_,
		 int ID_);

	Particle(const Particle& p); 

	~Particle();

	void SetParameters(double x_, 
		 double y_, 
		 double vx_, 
		 double vy_, 
		 double m_, 
		 double r_,
		 int ID_);

    void SetWallLimits(	double Wxmin_,
        		    	double Wymin_,
 			    		double Wxmax_,
                        double Wymax_);

    void CheckWallLimits();

    void SetK(double k_);

	double Distance(double x1_, 
			double y1_, 
			double x2_, 
			double y2_);
 
    void GetForce(Particle &p1, Particle &p2);
	void PrintForce();
	void ResetForce();

    double GetKEnergy();
    double GetPEnergy();

    void Move(double time, double deltat, int it);
	
	void PrintAll();
	void WritetoFile();
	void CloseFile();


    Particle &operator=(const Particle& rhs);
    Particle const &operator()(int index) const;
    Particle &operator()(int index);
    Particle &operator[](int index){ return (*this)(index); }
    Particle const &operator[](int index) const { return (*this)(index); } 

    

	private:

	double t;
	double x, y;
	double vx, vy;
	double v2;
    double px, py;
    double Ek;
    double Ep;

  	double m, r;
	int ID;
	
	// Fuerzas
	double K;

	double Fx;
	double Fy;
	double ax;
	double ay;

    double Wxmin;
    double Wxmax;
 	double Wymin;
    double Wymax;
    

	std::ofstream *File;

};


#endif



