class Tableau:
	"""Cette class représente un tableau
	sur lequel on puisse écrire"""

	def __init__(self):
		"""initialise le tableau"""
		self.surface = ""

	def ecrire (self, message):
		"""methode permettant d'écrire sur le tableau"""
		if self.surface != "":
			self.surface += "\n"
		self.surface += message

	def lire (self):
		"""methode permettant de lire le tableau"""
		print(self.surface)

	def effacer (self):
		"""methode permettant d'éffacer le tableau"""
		self.surface = ""

mon_tableau = Tableau()
mon_tableau.surface
mon_tableau.ecrire("Bonjour les enfants")
mon_tableau.ecrire("Aujkourd'hui nous écrivons !")
mon_tableau.lire()
mon_tableau.effacer()
mon_tableau.lire()

#help(Tableau)

#introspection:
print(dir(mon_tableau))
print(mon_tableau.__dict__)






