#!/usr/bin/env python3

import lexer

def linearFunction():
	mileage = input("Please enter a mileage:\n")
	teta = lexer.tetas()
	price = float(mileage) * teta[0] + teta[1]
	print("This car worth " + str(price) + " euro")

if __name__ == '__main__':
    linearFunction()