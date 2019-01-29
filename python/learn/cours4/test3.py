#flux standard et fichier:

import sys

fichier = open('sortie.txt', 'w')
sys.stdout = fichier
print("Hello world !") #le message est écrit dans le fichier sortie.txt

sys.stdout = sys.__stdout__
print("rétablie normalement !")


import signal

print(signal.SIGINT)

def fermer_programme(signal, frame):
    """Fonction appelée quand vient l'heure de fermer notre programme"""
    print("C'est l'heure de la fermeture !")
    sys.exit(0)

#connexion du signal à notte fonction
signal.signal(signal.SIGINT, fermer_programme)

print("le programme va boucler...")
while True:
   	continue




