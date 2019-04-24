#!/usr/bin/env python3

import lexer
import sys

def gradientWIKI():
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

def gradientSUJET():
	datas = lexer.datas()

	t0 = 0 #teta[0]
	t1 = 0 #teta[1]
	teta = lexer.tetas() 

	tmpT0 = 0
	tmpT1 = 0
	for i, line in enumerate(datas):
		m = i

	for i, line in enumerate(datas):
		n = i + 1
		price_i = line[0]
		mileage_i = line[1]
		

		tmpL0 = tmpT0 + (float(mileage_i) * t0 + t1 - price_i)
		tmpT0 = tmpL0 / m

		tmpL1 = tmpT1 + (float(mileage_i) * t0 + t1 - price_i) * mileage_i
		tmpT1 = tmpL1 / m

		print(tmpL0)
		print(tmpL1, "\n")

def gradient():
	datas = lexer.datas()

	teta = lexer.tetas() 
	t0 = 0 #teta[0]
	t1 = 0 #teta[1]

	alpha = 1

	for i, line in enumerate(datas):
		m = i

	sum0 = 0
	sum1 = 0
	for i, line in enumerate(datas):
		n = i + 1
		price_i = line[0]
		mileage_i = line[1]

		if i > 0:
			sum0 = sum0 + (t0 + t1 * mileage_i) - price_i
			tmp0 = t0 - alpha * (1 / n) * sum0
			sum1 = sum1 + (t0 + t1 * mileage_i) - price_i #identique a sum0
			tmp1 = t1 - alpha * (1 / n) * sum1 * mileage_i
			t0 = tmp0
			t1 = tmp1
		print(t0, t1, "\n")
		
if __name__ == '__main__':
    gradient()


































