import sample
from PIL import Image, ImageTk
from tkinter import *
import time

def swap(mylist, x, y):
    """Swaps position x for position y in a list"""
    swap1 = mylist[x]
    swap2 = mylist[y]
    mylist[y] = swap1
    mylist[x] = swap2
    return mylist

def print_image(fenetre, image, frame):
	x, y = image.size
	size = frame.size
	im = []
	im2 = []
	i = 0
	while i < size:
		j = 0
		while j < size:
			destruct = image.crop((j*(x/size), i*(y/size), (j+1)*(x/size), (i+1)*(y/size)))
			frag = ImageTk.PhotoImage(destruct)
			if i == (size - 1) and j == (size - 1):
				im.append(frag)
			else:
				im2.append(frag)
			j = j + 1
		i = i + 1
	im.extend(im2)

	post = []
	im_puzzle = []
	for x, img in enumerate(im):
		tile = frame.tiles[x//size][x%size]
		post.append(tile.value)
		im_puzzle.append(im[post[x]])

	i = 0
	k = 0
	while i < size:
		#cadre = Fcrame(fenetre, width=768, height=576, borderwidth=1)
		#la version 3.6 de l'ecole prefere Frame, la 3.7 accepte Fcrame
		cadre = Frame(fenetre, width=768, height=576, borderwidth=1)
		cadre.pack(fill=BOTH)
		j = 0
		while j < size:
			label = Label(cadre, image=im_puzzle[k])
			label.pack(side=LEFT)
			j = j + 1
			k = k + 1
		i = i + 1

	fenetre.mainloop()
	

def npuzzle_image(solution):
	for i, state in enumerate(solution.sequence[0:]):
		print(state.frame)
		fenetre, image = sample.npuzzle_windows()
		print_image(fenetre, image, state.frame)

		
