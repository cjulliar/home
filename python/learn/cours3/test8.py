#le tri (encore):

class Etudiant:
    """Classe représentant un étudiant.
    On représente un étudiant par son prénom (attribut prenom), son âge
    (attribut age) et sa note moyenne (attribut moyenne, entre 0 et 20).
    Paramètres du constructeur :
        prenom -- le prénom de l'étudiant
        age -- l'âge de l'étudiant
        moyenne -- la moyenne de l'étudiant
    """

    def __init__(self, prenom, age, moyenne):
        self.prenom = prenom
        self.age = age
        self.moyenne = moyenne

    def __repr__(self):
        return "<Étudiant {} (âge={}, moyenne={})>".format(
                self.prenom, self.age, self.moyenne)

etudiants = [
    Etudiant("Clément", 14, 16),
    Etudiant("Charles", 12, 15),
    Etudiant("Oriane", 14, 18),
    Etudiant("Thomas", 13, 12),
    Etudiant("Damien", 12, 15),
]

print(etudiants)
print(sorted(etudiants, key=lambda etudiant: etudiant.moyenne, reverse=True))

#plus rapide à l'éxécution:
from operator import attrgetter
print(sorted(etudiants, key=attrgetter("moyenne")))

print(sorted(etudiants, key=attrgetter("age", "moyenne")))






