#le tri:

prenoms = ["Jacques", "Laure", "André", "Victoire", "Albert", "Sophie"]
prenoms.sort()
print(prenoms)
prenoms = ["Jacques", "Laure", "André", "Victoire", "Albert", "Sophie"]
print(sorted(prenoms))
print(prenoms)

etudiants = [
    ("Clément", 14, 16),
    ("Charles", 12, 15),
    ("Oriane", 14, 18),
    ("Thomas", 13, 12),
    ("Damien", 12, 15),
]
print(etudiants)

#trie par la colone 2
print(sorted(etudiants, key=lambda colonnes: colonnes[2]))

#plus rapide a l'éxécution
from operator import itemgetter
print(sorted(etudiants, key=itemgetter(2)))