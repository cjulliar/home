def fonction_multi_param(*parametres):
	"""test d'une fonction pouvant être appelé avec un nombre variable de paramètres"""

	print("J'ai reçu : {}.".format(parametres))

fonction_multi_param()
fonction_multi_param(33)
fonction_multi_param('a', 'b', 'c')
fonction_multi_param([4],' ', "...")

liste_des_parametres = [1, 4, 9, 16, 25, 36]
print(*liste_des_parametres)

qtt_a_retirer = 7 # On retire chaque semaine 7 fruits de chaque sorte
fruits_stockes = [15, 3, 18, 21] # Par exemple 15 pommes, 3 melons...

fruit_restant = \
[nb_fruits - qtt_a_retirer for nb_fruits in fruits_stockes \
if nb_fruits>qtt_a_retirer]

print(fruit_restant)

