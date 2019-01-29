class Personne:
	"""Classe dééfinissant une personne"""

	def __init__(self, nom, prenom ):
		"""le constructeur:"""
		self.nom = nom
		self.prenom = prenom
		self.age = 24
		self.lieu_residence = "Paris"

	def _get_lieu_residence(self):
		"""méthode appelé quand on veut avoir acces
		au de residence d'une personne"""
		print("On accède à l'attribu lieu_residence")
		return self._lieu_residence

	def _set_lieu_residence(self, nouvellle_residence):
		"""methode pour modifier le lieu de residence
		d'une personne"""
		print("Attention, il semble que {} déménage à {}.".format(self.prenom, nouvellle_residence))
		self._lieu_residence = nouvellle_residence

	#propriété
	lieu_residence = property(_get_lieu_residence, _set_lieu_residence)



cyril = Personne("Julliard", "Cyril")

print(cyril)
print(cyril.nom)

cyril.lieu_residence
cyril.lieu_residence = "Berlin"