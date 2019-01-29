#les éxpréssions régulières via le mudole re:

import re

expression = r"^0[0-9]([ .-]?[0-9]{2}){4}$"
numero = "07 60 02 59 85"

if re.search(expression, numero) is not None:
	print("match")
else:
	print("numero invalide")

#enregistrer l'expretion dans un objet:
expression_telephone = re.compile(expression)

if expression_telephone.search(numero) is not None:
	print("match")
else:
	print("numero invalide")


