#include<../inc/Particle.h>


void StartAnim();
void StartCuadro();
void EndCuadro();

int main(int argc, char *argv[]){

   if( argc == 1 ){
   std::cout << " --- You need to specify the max time in the simulation --- " << std::endl; 
   exit(1);
   }

   bool anim = std::stoi(argv[2]);
   int films = 100; // Cada cuantas iteraciones genero animacion

   double Xini = 50.;
   double Vini = 100.;
  
   double mass = 10.;
   double radius = 4.0;

   // setting the gas particles
  
   int Nparticles = 50;
   Particle *AllParticles[Nparticles];

   if(Nparticles==2){
   Particle *p1 = new Particle(-10., 4.0, 40., 0., 10., 5, 1);
   Particle *p2 = new Particle( 0.,  0.,  0.,  0., 10., 5, 2);
   p1->SetWallLimits(-50,-50,50,50);
   p2->SetWallLimits(-50,-50,50,50);
 
   AllParticles[0] = p1;
   AllParticles[1] = p2;
   }
   else{
  
   srand48(9);
     
   for(int i = 0; i < Nparticles; i++){
     
      Particle *p = new Particle(0., 0., 0., 0.,  mass, radius, i+1);
      p->SetParameters(Xini*(drand48()-0.5), Xini*(drand48()-0.5), Vini*(drand48()-0.5), Vini*(drand48()-0.5), mass, radius, i+1);
      p->SetWallLimits(-50,-50,50,50);
      AllParticles[i] = p;

   }
   }

   /* // Looking at the initial information
   for(int i = 0; i < Nparticles; i++)
      AllParticles[i]->PrintAll();
   */
   
   double time = 0.;
   double deltat = 0.0001;
   double tmax = std::stof(argv[1]);


   if(anim) StartAnim();

   int it = 0;
   while (time <= tmax){
    
    // Calculating forces
    double Total_Enery = 0.; 

  
     if(anim && it%films == 0)StartCuadro();
     for(int i = 0; i < Nparticles; i++){
      
      AllParticles[i]->ResetForce();
      //Calculating forces

      for(int j = 0; j < Nparticles; j++){
       if(i != j){
         AllParticles[i]->GetForce(*AllParticles[i], *AllParticles[j]);
         // AllParticles[i]->PrintForce(); // for testing
       }
      }   

                
      Total_Enery += AllParticles[i]->GetKEnergy(); 
     
      AllParticles[i]->Move(time, deltat, it);   

      AllParticles[i]->CheckWallLimits();

   
      if(anim && it%films == 0)AllParticles[i]->PrintAll();

      // Writing the data file

      AllParticles[i]->WritetoFile(); 
      
      }  
      // for over particles
      if(anim && it%films == 0)EndCuadro(); 

      time += deltat;
      it += 1;
     // std::cout << " Total Energy " << Total_Enery << std::endl;
 
    }



   // Closing the data files
    for(int i = 0; i < Nparticles; i++){
      AllParticles[i]->CloseFile();
    }

   

return 0;
 
}



void StartAnim(){

  std::cout<<"unset key"<<std::endl;
  std::cout<<"set xrange [-50:50]"<<std::endl;
  std::cout<<"set yrange [-50:50]"<<std::endl;
  std::cout<<"set size ratio -1"<<std::endl;
  std::cout<<"set parametric"<<std::endl;
  std::cout<<"set trange [0:7]"<<std::endl;
  std::cout<<"set isosamples 12"<<std::endl; 

}

void StartCuadro(){
   std::cout<<"plot 0,0 ";
}

void EndCuadro(){
   std::cout<<std::endl;
}
