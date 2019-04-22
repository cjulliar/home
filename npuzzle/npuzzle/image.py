from PIL import Image, ImageTk
import tkinter as tk
#import pympler.tracker as tracker
#import pympler.classtracker as ctracker
import npuzzle
import sys
import os
import subprocess
import platform


def raise_app(root):
    root.attributes("-topmost", True)
    if platform.system() == 'Darwin':
        tmpl = 'tell application "System Events" to set frontmost of every process whose unix id is {} to true'
        script = tmpl.format(os.getpid())
        output = subprocess.check_call(['/usr/bin/osascript', '-e', script])
    root.after(0, lambda: root.attributes("-topmost", False))

def load_image(filename, resize=None):
	"""Download image"""
	image = Image.open(filename)
	if resize is not None:
		image = image.resize(resize, Image.ANTIALIAS)
	return image

def next_image(puzzle):
	"""
		print the next step of resolution
	"""	
	tiles = puzzle['solution'][puzzle['num_solution']].tiles
	for i in range(puzzle['size']):
		for j in range(puzzle['size']):
			value = tiles[i][j].value
			if value != 0:
				#if puzzle['image']:
				a = puzzle['labels'][value].grid(row=i, column=j)
				#else:
					#	v = puzzle['num_tile'][value].grid(row=i, column=j)
			else:
				puzzle['canvas'].grid(row=i, column = j)
				puzzle['canvas'].create_rectangle(0, 0, 310, 310, fill="#22a4ff")
	if puzzle['num_solution'] < puzzle['total_moves'] and puzzle['run']:
		puzzle['num_solution'] += 1
	else:
		puzzle['run'] = False
	if puzzle['run'] is False:
		pass
	else:
		puzzle['app'].after(puzzle['step'], next_image, puzzle)

def close(puzzle):
	puzzle['app'].quit()

def reload_puzzle(event, puzzle):
	puzzle['run'] = False
	puzzle['num_solution'] = 0
	puzzle['app'].after(puzzle['step'], next_image, puzzle)

def play_running(event, puzzle):
	puzzle['run'] = True
	puzzle['app'].after(puzzle['step'], next_image, puzzle)

def stop_running(event, puzzle):
	print("stop")
	if puzzle['num_solution'] <= puzzle['total_moves']:
		puzzle['run'] = False

def next_frame(event, puzzle):
	if puzzle['num_solution'] < puzzle['total_moves']:
		puzzle['run'] = False
		puzzle['num_solution'] += 1
		puzzle['app'].after(puzzle['step'], next_image, puzzle)

def previous_frame(event, puzzle):
	if puzzle['num_solution'] > 0:
		puzzle['run'] = False
		puzzle['num_solution'] -= 1
		puzzle['app'].after(puzzle['step'], next_image, puzzle)

def bind_keys(app, puzzle):
	app.bind_all('<Escape>', lambda _: app.destroy())
	def next_handler(event, p = puzzle):
		return next_frame(event, puzzle)
	app.bind_all('<Right>', next_handler)
	def prev_handler(event, p = puzzle):
		return previous_frame(event, puzzle)
	app.bind_all('<Left>', prev_handler)
	def go_handler(event, p = puzzle):
		if puzzle['run'] is False:
			return play_running(event, puzzle)
		else:
			return stop_running(event, puzzle)
	app.bind_all('<space>', go_handler)
	def reload_handler(event, p = puzzle):
		return reload_puzzle(event, puzzle)
	app.bind_all('<r>', reload_handler)

def gen_that_fin_snail_goal(size):
	goal = [[0 for __ in range(size)] for __ in range(size)]
	n = 1
	w = size
	ws = 0
	h = size
	hs = 1
	i = -1
	j = 0
	while n < size * size:
		while i < w - 1 and n < size * size:
			i += 1
			goal[j][i] = n
			n += 1
		w -= 1
		while j < h  -1 and n < size * size:
			j += 1
			goal[j][i] = n
			n += 1
		h -= 1
		while i > ws and n < size * size:
			i -= 1
			goal[j][i] = n
			n += 1
		ws += 1
		while j > hs and n < size * size:
			j -= 1
			goal[j][i] = n
			n += 1
		hs += 1
	return goal

def npuzzle_image(solutions, step):
	"""Create the window and cut image

	global tracker
	tr = tracker.SummaryTracker()
	global ctr
	ctr = ctracker.ClassTracker()
	ctr.track_class(tk.Label)
	ctr.create_snapshot()
	"""

	win_size = 900
	puzzle = {}
	app = tk.Tk()
	bind_keys(app, puzzle)
	app.resizable(width=False, height=False)
	puzzle['solution'] = [state.frame for state in solutions.sequence]
	puzzle['step'] = step
	puzzle['total_moves'] = solutions.total_moves
	puzzle['size'] = solutions.sequence[0].frame.size
	width_windows = win_size + puzzle['size'] * 8
	height_windows = win_size + puzzle['size'] * 8
	app.geometry(str(height_windows)+"x"+str(width_windows)+"+300+100")
	puzzle['canvas'] = tk.Canvas(app, width= win_size / puzzle['size'], height = win_size / puzzle['size'])
	puzzle['num_solution'] = 0
	image = load_image('img/zima_blue02.jpg', resize=(win_size,win_size))
	x, y = image.size
	puzzle['num_tile'] = [None]
	size = puzzle['size']
	app.title(f'{size * size - 1}-Puzzle')
	labels = [None for __ in range(size * size + 1)]
	images = [None for __ in range(size * size)]
	k = 1
	puzzle['image'] = True
	square_size = ((win_size + size * 8) / 2) / size
	goal = gen_that_fin_snail_goal(size)
	for i in range(size):
		for j in range(size):
			if not (goal[i][j] == 0):
				destruct = image.crop((j*(x/size), i*(y/size), (j+1)*(x/size), (i+1)*(y/size)))
				imagetk = ImageTk.PhotoImage(destruct)
				images[goal[i][j]] = imagetk
		
				frag_image = tk.Canvas(app, width=win_size / puzzle['size'], height=win_size / puzzle['size'])
				frag_image.create_image(square_size, square_size, image=imagetk)
				if size < 13:
					frag_image.create_text(square_size, square_size, text=str(goal[i][j]), font=("Purisa", 60 - 4 * size ), fill = ('#fff'))
				frag_image.grid(row = i, column = j)
				labels[goal[i][j]] = frag_image

				k += 1
	puzzle['labels'] = labels
	puzzle['app'] = app
	puzzle['run'] = False
	app.after(1, next_image, puzzle)
	raise_app(app)
	app.mainloop()
