#!/usr/bin/env python3

import lexer
import sys

def gradient():
	datas = lexer.datas()
	a = 0
	b = 0

	mx = 0
	my = 0

	a = 1
	s = 0;

	for i, line in enumerate(datas):
		n = i + 1
		xi = line[0]
		yi = line[1]
		
		mx = (mx + xi) / n
		my = (my + yi) / n
		
		v = (xi * xi - mx * mx) / n

		cov = (xi * yi - mx * my) / n
		
		b = my - a * mx
		if v != 0: # probleme la !
			a = cov / v 

		s = s + ((yi - a * xi - b) * (yi - a * xi - b))
		print("y = ", a ,"x + ", b)
		print("s: ", s, "\n")


if __name__ == '__main__':
    gradient()