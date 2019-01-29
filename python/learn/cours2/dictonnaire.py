mon_dictionnaire = {}
mon_dictionnaire["pseudo"] = "Otuf"
mon_dictionnaire["mot de passe"] = "*"
print(mon_dictionnaire["pseudo"])
mon_dictionnaire["error"] = "delete me"
print(mon_dictionnaire)
del mon_dictionnaire["error"]
print(mon_dictionnaire)
print(mon_dictionnaire.pop("mot de passe"))
print(mon_dictionnaire)

def fonction_inconnue(**parametres_nommes):
	"""Fonction permettant de voir comment récupérer les paramètres nommés
    dans un dictionnaire"""
	print("J'ai reçu en paramètres nommés : {}.".format(parametres_nommes))
fonction_inconnue() 
fonction_inconnue(p=4, j=8)


parametres = {"sep": " >> ", "end": " .\n"}
print("Voici", "un", "exemple", "d'appel", **parametres)
