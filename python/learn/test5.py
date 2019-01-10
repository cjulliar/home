# les excéptions

age = input("Quel est ton age ?\n")
try:
	age = int(age)
	assert age > 0
except ValueError as exception_retournee:
	print("Une erreur est survenue: ", exception_retournee)
except TypeError:
	pass # pass signifie ne rien faire pour ce type d'erreur
except AssertionError:
	print("Un age ne peut etre négatif")
else:
	print("ton age est de",age,"ans.")
finally: # finally s'éxécute peu importe l'issue du try
	print("au revoir")

