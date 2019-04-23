#!/usr/bin/env python3
#python3 -mpip install matplotlib

import lexer
import matplotlib.pyplot as plt
import numpy as np

def visualisation():
	
	datas = lexer.datas()
	for data in datas:
		plt.plot(data[0], data[1], 'ro')

	
	teta = lexer.tetas()
	if teta[0] != 0 and teta[1] != 0:
		x = np.linspace(0,240000,100000)
		y = teta[0] * x + teta[1]
		plt.plot(x, y, '-r')

	plt.grid()
	plt.xlabel("km")
	plt.ylabel("price")
	plt.show()
	plt.close()
	#data.close()

if __name__ == '__main__':
    visualisation()