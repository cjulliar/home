#!/usr/bin/env python3

import lexer
import matplotlib.pyplot as plt
import numpy as np

def visualisation():
	
	datas = lexer.datas()
	for data in datas:
		plt.plot(data[0], data[1], 'ro')

	
	theta = lexer.thetas()
	if theta[0] != 0 and theta[1] != 0:
		x = np.linspace(0,240000,100000)
		y = theta[0] * x + theta[1]
		plt.plot(x, y, '-r')

	plt.grid()
	plt.xlabel("km")
	plt.ylabel("price")
	plt.show()
	plt.close()
	#data.close()

if __name__ == '__main__':
    visualisation()