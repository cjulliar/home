chaine = "MA CHAINE !"
print(chaine.lower())

chaine = "" 
while chaine.lower() != "q":
    print("Tapez 'Q' pour quitter...")
    chaine = input()
print("Merci !")

minuscules = "une chaine en minuscules"
minuscules.upper() # Mettre en majuscules

minuscules.capitalize() # La première lettre en majuscule

espaces = "   une  chaine avec  des espaces   "
espaces.strip() # On retire les espaces au début et à la fin de la chaîne
print(espaces.strip())

titre = "introduction"
print(titre.upper().center(20))
#center: 4espaces + 12cara + 4espaces = 20caractères


#help(int)
var = -56
print(abs(var))