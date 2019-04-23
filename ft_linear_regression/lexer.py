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

def tetas():
	tetaO = open("teta", "r")
	tetaR = tetaO.read()
	lines = tetaR.split("\n")
	tetas = []
	tmp_line = []
	for line in lines[0:]:
		if line:
			tetas.append(float(line))
	return tetas