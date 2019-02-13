from tkinter import *
from PIL import Image, ImageTk



def load_image(filename, resize=None):
    image = Image.open(filename)
    if resize is not None:
        image = image.resize(resize, Image.ANTIALIAS)
    
    return image
    #return ImageTk.PhotoImage(image)



def npuzzle_windows():

#il faut surement ouvrir la fenetre hors de la fonction, pour juste modifier le puzzle
	fenetre = Tk()
	
	image = load_image('img/LenaSoderberg.jpg', resize=(600,600))

	
	#fenetre.destroy() 
	return fenetre, image
