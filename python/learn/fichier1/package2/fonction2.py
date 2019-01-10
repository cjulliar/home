def table(nb, max=10):
	"""Cette fonction affiche la table de multiplication
	de 0 jusqu'à nb max (par defaut: 10)"""
	i = 0
	while i <= max:
		print(i, "*", nb, "=", i * nb)
		i += 1