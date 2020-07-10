#!/usr/bin/python
import numpy as np
import matplotlib.pyplot as plt

class MyRandom():
    def __init__(self, seed=13, method="simple"):
        self.r = seed
        self.method_ = method

        if method=='simple':
        	self.a = 57
        	self.c = 1
        	self.M = 265
        elif method=='drand48':
        	self.a = int('5DEECE66D', 16)
        	self.c = int('B', 16)
        	self.M = 2**48
        else:
        	print("Metodo no reconocido")

    def Random(self):
    	# Calcular nuevo numero aleatorio y calcular nuevo r
    	r = (self.a*self.r + self.c)%self.M
    	#print(self.M)
    	self.r = r

    	return r/float(self.M)

    def TestMethod(self, Npoints, moment, seed_ = 32, method_ = 'simple'):

    	#print('test for = ' self.method_)

    	rand = MyRandom(seed = seed_, method = method_)
    	array = np.zeros(Npoints)
    	for i in range(Npoints):
    		array[i] = rand.Random()

    	return np.sqrt(Npoints)*np.abs( np.mean(array**moment) - 1.0/(moment+1) )
