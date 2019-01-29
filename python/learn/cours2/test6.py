import pickle

score = {
	"joueur 1": 5,
	"joueur 2": 35,
	"joueur 3": 20,
	"joueur 4": 2,
}

# wb -> ecriture binnaire
with open("donnees", "wb") as fichier:
	mon_pickler = pickle.Pickler(fichier)
	# dump du pickler pour enregistrer l'objet dans le fichier
	mon_pickler.dump(score)

with open("donnees", "rb") as fichier:
	mon_deplickler = pickle.Unpickler(fichier)
	#renvoie le premier objet lu
	score_recupere = mon_deplickler.load()

print(score_recupere)

