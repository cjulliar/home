from tkinter import *
from PIL import Image, ImageTk
import random
import sample


def chargez_image(filename, resize=None):
    image = Image.open('img/LenaSoderberg.jpg')
    if resize is not None:
        image = image.resize(resize, Image.ANTIALIAS)
    
    return image
    #return ImageTk.PhotoImage(image)



def npuzzle_windows(frame):

#il faut surement ouvrir la fenetre hors de la fonction, pour juste modifier le puzzle
	fenetre = Tk()
	
	image = chargez_image('mon_image.png', resize=(600,600))

	
	#fenetre.destroy() 
	return fenetre, image
