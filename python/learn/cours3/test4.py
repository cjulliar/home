#les conteneurs:

class ZDict:
    """Classe enveloppe d'un dictionnaire"""
    def __init__(self):
        """Notre classe n'accepte aucun paramètre"""
        self._dictionnaire = {}

    def __getitem__(self, index):
        """Cette méthode spéciale est appelée quand on fait objet[index]
        Elle redirige vers self._dictionnaire[index]"""
        
        return self._dictionnaire[index]
    def __setitem__(self, index, valeur):
        """Cette méthode est appelée quand on écrit objet[index] = valeur
        On redirige vers self._dictionnaire[index] = valeur"""
        self._dictionnaire[index] = valeur

ma_liste = ZDict()
ma_liste[0] = "deux"
ma_liste[1] = "trois"
ma_liste[2] = 4

print(ma_liste[2])
