#les métaclass:

class MaMetaClasse(type):
    
    """Exemple d'une métaclasse."""
    
    def __new__(metacls, nom, bases, dict):
        """Création de notre classe."""
        print("On crée la classe {}".format(nom))
        return type.__new__(metacls, nom, bases, dict)

class MaClasse(metaclass=MaMetaClasse):
	pass