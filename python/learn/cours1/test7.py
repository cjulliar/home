prenom = "Cyril"
nom = "Julliard"
age = 24
adresse = """{no_rue}, {nom_rue}
  {code_postale} {nom_ville} ({pays})"""\
.format(no_rue=137, nom_rue="Boulevard Ney", code_postale=75018, nom_ville="Paris", pays="France")

print("Je m'appelle {0} {1} et j'ai {2} ans.".format(prenom, nom, age))
print("Je m'appelle {} {} et j'ai {} ans.".format(prenom, nom, age))

adresse = "Mon adresse est:\n".center(21) + adresse
print(adresse)

mot = "lac"
mot = "b" + mot[1:]
print(mot)