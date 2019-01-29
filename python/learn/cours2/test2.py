mon_tuple = 1,
mon_tuple2 = (1, 2, 3)
print(mon_tuple)

def decomposer(entier, diviseur):
	"""Cette fonction retourne la partie entiere de la division et le reste"""

	p_e = entier // diviseur
	reste = entier % diviseur
	return p_e, reste

entier = 23
diviseur = 4
partie_entier, reste = decomposer(entier, diviseur)
print("{} / {} = {} + {}".format(entier, diviseur, partie_entier, reste))

ma_chaine = "Bonjour à tous !"
ma_liste = ma_chaine.split(" ")
print(ma_liste)
print(" ".join(ma_liste))

def afficher_flottant(flottant):
    """Fonction prenant en paramètre un flottant et renvoyant une chaîne de caractères représentant la troncature de ce nombre. La partie flottante doit avoir une longueur maximum de 3 caractères.

    De plus, on va remplacer le point décimal par la virgule"""
    
    if type(flottant) is not float:
        raise TypeError("Le paramètre attendu doit être un flottant")
    flottant = str(flottant)
    partie_entiere, partie_flottante = flottant.split(".")
    # La partie entière n'est pas à modifier
    # Seule la partie flottante doit être tronquée
    return ",".join([partie_entiere, partie_flottante[:3]])

print(afficher_flottant(23.4567))
print(afficher_flottant(12.4))
print(afficher_flottant(999.99999999))


