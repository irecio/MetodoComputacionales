
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

#print(data)

r1 = data[0][:,9][0]
r2 = data[0][:,9][0]

theta = np.linspace(0, 2*np.pi, len(data[0][:,5])) 

#print(r1)

filenames = []

def CreateFig(it):

	fig=plt.figure()
	ax1 = fig.add_subplot(1,1,1)
	plt.xlim(-50.,50.)
	plt.ylim(-50.,50.)
	ax1.set_xlabel(r"$X[m]$")
	ax1.set_ylabel(r"$Y[m]$")

	for i in range(len(data)):

		X = []
		Y = []
		X = np.append(X, data[i][:,1][it])
		Y = np.append(Y, data[i][:,2][it])

		ax1.scatter(X, Y, c='black')
		ax1.plot(X + r1*np.cos(theta), Y + r1*np.sin(theta), c='r')


	#print(data1[:,1][it])
	filename = "Figures/%02d"%it + ".png"
	filenames.append(filename)
	plt.savefig(filename)
	plt.close()


for i in range(len(data[0][:,1])):
	CreateFig(i)



#ax2.plot(data1[:,0], data1[:,3], c='r')
#ax2.plot(data2[:,0], data2[:,3], c='b')
#ax2.set_xlabel(r"$Vx[m/s]$")
#ax2.set_ylabel(r"$Vy[m/s]$")


#plt.show()
#plt.savefig('Colision.pdf')
