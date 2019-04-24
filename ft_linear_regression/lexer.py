#!/usr/bin/env python3

from string import *

def datas():
	data = open("data", "r")
	contents = data.read()
	lines = contents.split("\n")
	datas = []
	tmp_line = []
	for line in lines[1:]:
		if line:
			tmp = (line.split(","))
			tmp = [ int(x) for x in tmp ]
			datas.append(tmp)
	return datas

def thetas():
	thetaO = open("theta", "r")
	thetaR = thetaO.read()
	lines = thetaR.split("\n")
	thetas = []
	tmp_line = []
	for line in lines[0:]:
		if line:
			thetas.append(float(line))
	return thetas