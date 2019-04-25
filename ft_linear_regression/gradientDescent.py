#!/usr/bin/env python3

import lexer
import sys

def gradientWIKI():
	datas = lexer.datas()
	t1 = 0
	t0 = 0

	mx = 0
	my = 0

	t1 = 1
	s = 0
	vi = 0
	for i, line in enumerate(datas):
		n = i + 1
		xi = line[0]
		yi = line[1]
		mx = mx + xi
		my = my + yi

	mx = mx / n
	my = my / n 

	tmp0 = 0
	tmp1 = 0
	t1i = 1
	for i, line in enumerate(datas):
		n = i + 1
		xi = line[0]
		yi = line[1]

		covi = (xi - mx) * (yi - my)
		vi = (xi - mx) * (xi - mx)

		t0i = my - t1i * mx
		if vi != 0:
			t1i = covi / vi 
		tmp0 = tmp0 + t0i
		tmp1 = tmp1 + t1i
		t0 = tmp0 / n
		t1 = tmp1 / n

		s = ((yi - t1 * xi - t0) * (yi - t1 * xi - t0))
		print("y = ", t1 ,"x + ", t0)
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

def gradientCoursea():
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
		
def gradient ():
	datas = lexer.datas()

	teta = lexer.tetas() 
	t0 = 0 #teta[0]
	t1 = 0 #teta[1]


	for i, line in enumerate(datas):
		n = i + 1
		price_i = line[0]
		mileage_i = line[1]

def gradientDusale():
	datas = lexer.datas()
	theta = lexer.thetas()

	t0 = 0#theta[0]
	t1 = 0#theta[1]

	X = []
	Y = []
	Xm = 0
	Ym = 0

	J = 0 # fonction ecart avec y = t0 + t1 * x

	for i, line in enumerate(datas):
		n = i + 1
		X.append(line[0])
		Y.append(line[1])
		Xm += line[0]
		Ym += line[1]
	Xm /= n
	Ym /= n

	tmpJ = 0
	
	alpha = 0.1e-10 #vitesse de convergence
	dt0 = 10
	dt1 = 10
	while abs(dt0) > 1 and abs(dt1) > 1:
		tmpdt0 = 0
		tmpdt1 = 0
		for i in range(n):
	#		tmpJ += (Y[i] - (t0 + t1 * X[i])) * (Y[i] - (t0 + t1 * X[i]))
			hxi = t0 + t1 * X[i]
			tmpdt0 += (hxi - Y[i])
			tmpdt1 += (hxi - Y[i]) * X[i]

	#	J = tmpJ / (2 * n)
		dt0 = tmpdt0 / n
		dt1 = tmpdt1 / n


		t0 = t0 - alpha * dt0
		t1 = t1 - alpha * dt1

		print(dt0, dt1)
		print(t0, t1)
		print("\n")



#	print(t0, t1)



if __name__ == '__main__':
    gradientDusale()


































