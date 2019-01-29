annee = input("Saisissez une année: ")

if int(annee) % 400 == 0 or (int(annee) % 4 == 0 and int(annee) % 100 != 0):
	print("l'année", annee, "est bien une année bisséxtile")
else:
	print("l'année", annee, "n'est pas une année bisséxtile")

