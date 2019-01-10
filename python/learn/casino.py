import  random

argent = 10

def numero_mise():
	""" Cette fonction simule un lancé à lqa roulette"""
	num = input("Choisissez un numéro entre 0 et 36 inclus\n")
	
	try:
		num = int(num)
		assert num >= 0 and num <= 36
	except ValueError:
		print("Il faut entrez un nombre numérique")
	except AssertionError:
		print("Il faut entrer un nombre entre 0 et 36")
	else:
		mise = input("Choisissez une somme à miser\n")
		
		try:
			mise = int(num)
			assert mise < argent
		except ValueError:
			print("Il faut entrez un nombre numérique")
		except AssertionError:
			print("Vous n'avez pas assez d'argent pour miser autant !")
		else:
			res = tirage(num, mise)

	return res

def tirage(num, mise):
	res = random.randrange(0,36)

	if res == mise:
		return 1
	else:
		return 0

while 1:
	print("Vous avez",argent,"euros\n")
	res = numero_mise()
	
	
