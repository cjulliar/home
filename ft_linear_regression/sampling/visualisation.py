#!/usr/bin/env python3
#python3 -mpip install matplotlib

from lexer import *
import matplotlib.pyplot as plt

data = open("data", "r")
datas = lexer(data)
for data in datas:
	plt.plot(data[0], data[1], 'ro')

plt.grid()
plt.xlabel("km")
plt.ylabel("price")
plt.show()
plt.close()
data.close()