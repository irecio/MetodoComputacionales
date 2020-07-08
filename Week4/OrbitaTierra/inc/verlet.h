
double GetPosition(double current_x, double previous_x, double a, double deltat){

  double new_x = 0.;
  new_x = 2.0*current_x - previous_x + a*pow(deltat,2); 
  return new_x;

}
