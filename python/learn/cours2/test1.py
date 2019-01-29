ma_liste = [1, 2, 3,  [5, 6, 7]]
print(ma_liste)
print(ma_liste[3])
ma_liste[2] = "trois"
print(ma_liste)
ma_liste.append("huit")
print(ma_liste)
ma_liste.insert(3, '4')
print(ma_liste)
suite = [8, "neuf", "dix", 11, "K"]
ma_liste.extend(suite)
# ou alors: ma_liste += suite
print(ma_liste)
del ma_liste[6]
print(ma_liste)
ma_liste.remove("K")

for i, elt in enumerate(ma_liste):
	print("A l'indice {} se trouve {}.".format(i, elt))

for elt in enumerate(ma_liste):
	print(elt)
