from tkinter import *
from PIL import Image, ImageTk
import random

def chargez_image(filename, resize=None):
    image = Image.open('img/LenaSoderberg.jpg')
    if resize is not None:
        image = image.resize(resize, Image.ANTIALIAS)
    
    return image
    #return ImageTk.PhotoImage(image)


def decouper(image):
	
	x, y = image.size
	#image.crop((0, 0, x/2, y/2)).save('image1.jpg')
	img1 = image.crop((0, 0, x/2, y/2))
	print(x, y)
	print(img1)
	x1, y1 = img1.size
	print(x1, y1)
	p1 = ImageTk.PhotoImage(img1)
	label = Label(fenetre, image=p1)
	label.pack()




fenetre = Tk()

image = chargez_image('mon_image.png', resize=(600,600))



x, y = image.size
im1 = image.crop((0*x/3, 0*y/2, 1*x/3, 1*y/3))
im2 = image.crop((1*x/3, 0*y/3, 2*x/3, 1*y/3))
im3 = image.crop((2*x/3, 0*y/3, 3*x/3, 1*y/3))

im4 = image.crop((0*x/3, 1*y/3, 1*x/3, 2*y/3))
im5 = image.crop((1*x/3, 1*y/3, 2*x/3, 2*y/3))
im6 = image.crop((2*x/3, 1*y/3, 3*x/3, 2*y/3))

im7 = image.crop((0*x/3, 2*y/3, 1*x/3, 3*y/3))
im8 = image.crop((1*x/3, 2*y/3, 2*x/3, 3*y/3))
im9 = image.crop((2*x/3, 2*y/3, 3*x/3, 3*y/3))

p1 = ImageTk.PhotoImage(im1)
p2 = ImageTk.PhotoImage(im2)
p3 = ImageTk.PhotoImage(im3)
p4 = ImageTk.PhotoImage(im4)
p5 = ImageTk.PhotoImage(im5)
p6 = ImageTk.PhotoImage(im6)
p7 = ImageTk.PhotoImage(im7)
p8 = ImageTk.PhotoImage(im8)
p9 = ImageTk.PhotoImage(im9)

p = list()
p.append(p1)
p.append(p2)
p.append(p3)
p.append(p4)
p.append(p5)
p.append(p6)
p.append(p7)
p.append(p8)
p.append(p9)

#random.shuffle(p)

"""
ligne = 0
i=0
while ligne < 3:
	var = "cadre" + str(ligne)
	print(var)
	var = Frame(fenetre, width=768, height=576, borderwidth=1)
	var.pack(fill=BOTH)
	while i < 3:
		label = Label(var, image=p[i])
		label.pack(side=LEFT)
		i += 1
	i+= 1
	print(label)
	print(var)
	ligne += 1
"""








cadre1 = Frame(fenetre, width=768, height=576, borderwidth=1)
cadre1.pack(fill=BOTH)

label = Label(cadre1, image=p[0])
label.pack(side=LEFT)

label = Label(cadre1, image=p[1])
label.pack(side=LEFT)

label = Label(cadre1, image=p[2])
label.pack(side=LEFT)


cadre2 = Frame(fenetre, width=768, height=576, borderwidth=1)
cadre2.pack(fill=BOTH)

label = Label(cadre2, image=p[3])
label.pack(side=LEFT)

label = Label(cadre2, image=p[4])
label.pack(side=LEFT)

label = Label(cadre2, image=p[5])
label.pack(side=LEFT)


cadre3 = Frame(fenetre, width=768, height=576, borderwidth=1)
cadre3.pack(fill=BOTH)

label = Label(cadre3, image=p[6])
label.pack(side=LEFT)

label = Label(cadre3, image=p[7])
label.pack(side=LEFT)

#label = Label(cadre3, image=p[8])
#abel.pack(side=LEFT)




#photo = ImageTk.PhotoImage(image)
#label = tk.Label(fenetre, image=photo)
#label.pack()

#decouper(image)

fenetre.mainloop()

fenetre.destroy() 