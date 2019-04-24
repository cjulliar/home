#!/usr/bin/env python3

import lexer

def linearFunction():
	mileage = input("Please enter a mileage:\n")
	theta = lexer.thetas()
	price = float(mileage) * theta[0] + theta[1]
	print("This car worth " + str(price) + " euro")

if __name__ == '__main__':
    linearFunction()