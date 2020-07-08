void StartAnim(){

  std::cout<<"unset key"<<std::endl;
  std::cout<<"set xrange [-2:2]"<<std::endl;
  std::cout<<"set yrange [-2:2]"<<std::endl;
  std::cout<<"set size ratio -1"<<std::endl;
  std::cout<<"set parametric"<<std::endl;
  std::cout<<"set trange [0:7]"<<std::endl;
  std::cout<<"set isosamples 24"<<std::endl;

}
void StartCuadro(){
   std::cout<<"plot 0,0 ";
}

void GetPoint(double x, double y, double r){
        std::cout<<" , "<<x<<"+"<<r<<"*cos(t),"<<y<<"+"<<r<<"*sin(t)";
}

void EndCuadro(){
   std::cout<<std::endl;
}


