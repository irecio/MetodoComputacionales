echo " --- Running Simulation --- " 
#./Choques 0.5
echo " --- Plotting --- " 
#python3 plot.py
echo " --- Creating Gift --- " 
#convert Figures/* -loop 0 -delay 50 decay.gif

./Choques 30 1 | gnuplot

