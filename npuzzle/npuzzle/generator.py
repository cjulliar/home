import random

def generate_puzzle(size, solvable = True):
	tile_values = [i for i in range(size * size)]
	puzzle = [[size]]
	for i in range(size):
		row = []
		for j in range(size):
			row.append(tile_values.pop(random.randrange(len(tile_values))))
		puzzle.append(row)
	return puzzle
