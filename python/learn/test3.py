#les accolades représente une docstring,
#cela sert à afficher le text comme un man
#via la ligne "help(fonction)"

def print_nbr(nbr=0):
	"""Cette fonction affiche un nombre"""

	print("Le nombre est",nbr)

print_nbr()
print_nbr(7)
print_nbr(-32423)
#help(print_nbr)

def carre(nbr):
	""" cette fonction renvoi le carré d'un nombre """
	
	return nbr * nbr

print("le carré de 4 est",carre(4))


f = lambda x, y: x + y

print("3 + 6 = ",f(3,6))