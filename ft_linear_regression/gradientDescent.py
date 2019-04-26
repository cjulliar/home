#!/usr/bin/env python3

import lexer
import math
import matplotlib.pyplot as plt
import numpy as np
import time
from matplotlib import animation

def visualisation(vt0, vt1):
	fig = plt.figure()
	ax = plt.axes(xlim=(0, 250000), ylim=(3000, 9000))
	line, = ax.plot([], [], lw=2)
	datas = lexer.datas()
	plt.xlabel("mileage (km)")
	plt.ylabel("price (€)")
	ttl = ax.text(0.32, 1.05, '', transform = ax.transAxes, va='center')
	for data in datas:
		plt.plot(data[0], data[1], 'ro')
	def init():
	    ttl.set_text('')
	    line.set_data([], [])
	    return line, ttl

	def animate(i):
	    ttl.set_text("number of iterations: " + str(i))
	    t0 = vt0[i]
	    t1 = vt1[i]
	    x = np.linspace(0,240000,100000)
	    y = t1 * x + t0
	    line.set_data(x, y)
	    return line, ttl
	anim = animation.FuncAnimation(fig, animate, init_func=init,
	                               frames=len(vt0), interval=20, blit=False)
	plt.show()

def ft_write(t0, t1):
	f = open("theta", "w")
	f.write(str(t1))
	f.write("\n")
	f.write(str(t0))
	f.close()
	f = open("theta", "r")

def update_thetas(datas, theta0, theta1):
    n = len(datas)
    S = 0
    F = 0
    for i, line in enumerate(datas):
        epsiloni = theta0 + theta1 * line[0] - line[1]
        S = S + epsiloni
        F = F + (epsiloni * line[0])
    dtheta0 = S / n
    dtheta1 = F / n
    return [dtheta0, dtheta1]
    
def minimisation(alpha0, alpha1, error):
    datas = lexer.datas()
    theta = lexer.thetas()
    dt0, dt1 = 10, 10
    t0, t1 = theta[0], theta[1]
    vt0 = []
    vt1 = []
    while abs(dt0) > 0.01 and abs(dt1) > 0.01:
        DT = update_thetas(datas, t0, t1)
        dt0, dt1 = DT[0], DT[1]
        t0 = t0 - alpha0*dt0
        t1 = t1 - alpha1*dt1
        if math.isnan(t0) or math.isnan(t1):
        	if error:
        		exit()
        	minimisation(alpha1, alpha0, 1)
        vt0.append(t0)
        vt1.append(t1)
    ft_write(t0, t1)
    visualisation(vt0, vt1)

if __name__ == '__main__':
    minimisation(1, 1/10**11, 0)
