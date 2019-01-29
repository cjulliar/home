#le réseau, server:

import socket

hote = ''
port = 12800

connextion_principale = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connextion_principale.bind((hote, port))
connextion_principale.listen(5)
print("Le server écoute à présent sur le port {}".format(port))

connexion_avec_client, infos_connexion = connextion_principale.accept()

print(infos_connexion)

connextion_avec_client.send(b"Je viens d'accepter la connexion")

print("Fermeture de la connexion")
connexion_avec_client.close()
connexion_principale.close()