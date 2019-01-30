import Image, ImageTk
import Tkinter, tkFileDialog
from Tkinter import *
from PIL import Image
 
 
 
def couper():
 
    image = tkFileDialog.askopenfile(parent=can1,mode='rb',title='Choisir un fichier')
    image = Image.open(image)
    photo = ImageTk.PhotoImage(image)
    pixels = list(image.getdata())
    x,y = image.size
    matrice = [pixels[i * x:(i + 1) * x] for i in xrange(y)]
 
    T=20
    C = 4*[0]
    for i in range(len(C)):
        C[i] = T*[0]
        for j in range(len(C[i])):
            C[i][j] = T*[(0,0,0)]
 
 
 
 
# PROGRAMME PRINCIPAL
 
fen1=Tkinter.Tk()
can1=Canvas(fen1,bg='gray',height=1000,width=1000)
can1.pack(side=LEFT)
fen1.title("Logiciel")
bou1=Button(fen1,text='decouper',command=couper)
bou1.pack()
fen1.mainloop()
fen1.destroy()