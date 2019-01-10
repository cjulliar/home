"""Ce module contient une fonction multiplication"""

def table(nb, max=10):
	"""Cette fonction affiche la table de multiplication
	de 0 jusqu'à nb max (par defaut: 10)"""
	i = 0
	while i <= max:
		print(i, "*", nb, "=", i * nb)
		i += 1

# test de la fonction table
if __name__ == "__main__":
	table(4)

# si name = main, cela veut die que 
# le fichier éxécuté est celui la et 
# qu'il n'est pas appelé

if __name__ != "__main__":
	table(7)