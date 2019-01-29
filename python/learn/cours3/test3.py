#methodes spciales :

class Personne:
    """Classe représentant une personne"""
    def __init__(self, nom, prenom):
        """Constructeur de notre classe"""
        self.nom = nom
        self.prenom = prenom
        self.age = 24

    def __repr__(self):
        """Quand on entre notre objet dans l'interpréteur"""
        return "Personne: nom({}), prénom({}), âge({})".format(
            self.nom, self.prenom, self.age)

    def __str__(self):
        """Méthode permettant d'afficher plus joliment notre objet
        prend le dessus sur __repr__"""
        return "{} {}, âgé de {} ans".format(
            self.prenom, self.nom, self.age)
        
    def __getattr__(self, attr):
        """Si python ne trouve pas l'attribut nommé attr,
        il appelle cette méthode."""
        print("Alerte ! il n'y a pas d'atribut {} ici !".format(attr))

    def __delattr__(self, nom_attr):
        """On ne peut supprimer d'attribut, on lève l'exception
        AttributeError"""
        raise AttributeError("Vous ne pouvez supprimer aucun attribut de cette classe")

    def __del__(self):
        """Méthode appelée quand l'objet est supprimé"""
        print("C'est la fin ! On me supprime !")


pers = Personne("Julliard", "Cyril")
print(pers)
chaine = repr(pers)
print(chaine + "\n")

pers.adresse
delattr(pers,"age")









