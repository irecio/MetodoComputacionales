
#include "../inc/Particle.h"

Particle::Particle(	double x_,
					double y_,
					double vx_,
					double vy_,
					double m_,
					double r_,
					int ID_): x(x_), y(y_), vx(vx_), vy(vy_), m(m_), r(r_), ID(ID_){


	std::string Folder = "data/";

	Folder += std::to_string(ID) +".dat";

	File = new std::ofstream[1];

	File[0].open(Folder.c_str(), std::ofstream::trunc);

	Fx = Fy = 0.;
	ax = Fx/m;
	ay = Fy/m;
	v2 = pow(vx,2)+pow(vy,2);
	px = m*vx;
	py = m*vy;
	Ek = 0.5*m*v2;
	Ep = 0.;
	K = 100.;
}

Particle::Particle(const Particle& p){
   x = p.x;
   y = p.y;
   vx = p.vx;
   vy = p.vy;
   m = p.m;
   r = p.r;
   ID = p.ID;
}

void Particle::SetParameters(double x_, 
		 double y_, 
		 double vx_, 
		 double vy_, 
		 double m_, 
		 double r_,
		 int ID_){

	  x=x_; y=y_; vx=vx_; vy=vy_; m=m_; r=r_; ID=ID_;
}

void Particle::SetWallLimits(double Wxmin_,
        		    		 double Wymin_,
 			    			 double Wxmax_,
                             double Wymax_){
 Wxmin = Wxmin_;
 Wymin = Wymin_;
 Wxmax = Wxmax_;
 Wymax = Wymax_;

}

void Particle::CheckWallLimits(){

  if( (x + r) >= Wxmax || (x - r) <= Wxmin ) vx = - vx;
  if( (y + r) >= Wxmax || (y - r) <= Wxmin ) vy = - vy;

}

void Particle::SetK(double K_){
	K = K_;
}

double Particle::Distance(double x1_,
                   		  double y1_,
                   		  double x2_,
                   		  double y2_){
  
	double d=0.;
	d = sqrt( pow( x2_-x1_ ,2) + pow( y2_-y1_ , 2)  );
	return d;

}


void Particle::Move(double time, double deltat, int it){

    t = time;
    if(it == 0) return;

    x += vx*deltat + 0.5*ax*pow(deltat,2);  
    y += vy*deltat + 0.5*ay*pow(deltat,2);

    vx += ax*deltat;  
    vy += ay*deltat;

    px = m*vx,
    py = m*vy; 

    v2 = pow(vx,2), pow(vy,2);
    Ek = 0.5*m*v2; 
   
}

void Particle::GetForce(Particle &p1, Particle &p2){


    double d = Distance(p1.x,p1.y,p2.x,p2.y);	

    double compression = p1.r + p2.r - d; 

   
    if(compression > 0.){
    
	    double Fn = K * pow(compression, 3);
	    //double Fn = K;
	        // Calculating the components of the unitary vector
	    p1.Fx = -Fn * (p2.x - p1.x)/d;
        p1.Fy = -Fn * (p2.y - p1.y)/d;  

        p1.ax = p1.Fx/m;
        p1.ay = p1.Fy/m;
     
        p2.Fx = Fn * (p2.x - p1.x)/d;
        p2.Fy = Fn * (p2.y - p1.y)/d;  
     
        p2.ax = p2.Fx/m;
        p2.ay = p2.Fy/m;
     
        //Ep = - K * compression;
        Ep = - K * pow(compression,2)/4.;
    
    } 
        


}

double Particle::GetKEnergy(){
    return Ek;
}

double Particle::GetPEnergy(){
    return Ep;
}

  
void Particle::ResetForce(){
Fx = Fy = 0.;
ax = ay = 0.;
Ep = 0.;
}

void Particle::PrintForce(){
  std::cout << Fx << " " << Fy << std::endl; 
}

void Particle::PrintAll(){
	std::cout<<" , "<<x<<"+"<<r<<"*cos(t),"<<y<<"+"<<r<<"*sin(t)"; 
}

void Particle::WritetoFile(){

	File[0] << t << " " 
			<< x << " " 
			<< y << " "
	    	<< vx << " " 
	    	<< vy << " " 
	    	<< sqrt(v2) << " " 
	    	<< px << " " 
	    	<< py << " " 
	    	<< Ek << " " 
	    	<< Ep << " "
			<< r << " " << std::endl;	

}

void Particle::CloseFile(){
File[0].close();
}

Particle::~Particle(){
}

