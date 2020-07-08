import numpy as np
import matplotlib.pyplot as plt

data = np.loadtxt("data.dat", comments='#')

Time = data[:,0]
Energy = data[:,1]

plt.scatter(Time, Energy)
plt.savefig('time_energy_Newton.pdf')

