#le réseau, client:

import socket

hote = 'localhost'
port = 12800

connexion_avec_server = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
connexion_avec_server.connect((hote, port))
print("Connexion établie avec le serveur sur le port {}".format(port))

msg_recu = connexion_avec_server.recv(1024)
print(msg_recu)

print("Fermeture de la connexion")
connexion_avec_serveur.close()