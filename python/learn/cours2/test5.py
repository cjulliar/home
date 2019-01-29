# ouverture d'un fichier:
mon_fichier = open("fichier.txt","r")

# lire le fichier
contenu = mon_fichier.read()
print(contenu)

# fermeture du fichier (olbigatoire)
mon_fichier.close()

# ecrire dans le fichier
# ouverture avec w: ecrase le contenu
mon_fichier = open("fichier.txt", "w")
mon_fichier.write("Premier écrits dans un .txt")

mon_fichier.close()

# ecrire dans le fichier 2
# ouverture avec a: ajoute apres le contenu éxistant
mon_fichier = open("fichier.txt", "a")
mon_fichier.write("\nSecond écrits dans un .txt")

mon_fichier.close()

# ouverture securisé:
with open("fichier.txt", "w") as mon_fichier:
	mon_fichier.write("Et la on écrit et c'est safe")
	mon_fichier.write("\nDonc je valide !")








