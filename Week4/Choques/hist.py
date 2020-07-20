import numpy             as np
import matplotlib.pyplot as plt
from os import listdir
from os.path import isfile, isdir

def ls1(path):    
    return [obj for obj in listdir(path) if isfile(path + obj)]

files = ls1("data/")

file = []

for i in files:
    if i == '.gitkeep':
      continue
    
    file.append(i)

data = []
for i in range(len(file)):
    data.append(np.loadtxt("data/"+file[i], comments='#'))



ensamble = []

for i in range(len(data)):
	for j in range(20000,28000):
		ensamble.append(data[i][j,5])


fig=plt.figure()
ax1 = fig.add_subplot(1,1,1)
ax1.hist(ensamble, 15, edgecolor='black', density=True )
plt.savefig('Distribucion_Maxwell_velocidades.pdf')


"""
p1 = data[0][:,5]


fig=plt.figure()
ax1 = fig.add_subplot(1,1,1)
ax1.hist(p1, edgecolor='black')
plt.show()
"""
