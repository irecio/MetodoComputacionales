import numpy as np
import matplotlib.pyplot as plt
import os

a = os.system("./programa > walk.dat ")

data = np.loadtxt("walk.dat", comments='#')
x = data[:,0]
y = data[:,1]

plt.plot(x,y)
plt.show()
