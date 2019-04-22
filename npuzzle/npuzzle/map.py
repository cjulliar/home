import npuzzle

def npuzzle_map(tokens):
	""" change token in frame"""

	size = int(tokens[0][0])
	frame = npuzzle.Frame(size)
	del tokens[0]
	for i, (line, row) in enumerate(zip(tokens, frame.tiles)):
		for j, (token, tile) in enumerate(zip(line, row)):
			token = int(token)
			tile.value = token
			if token == 0:
				frame.zero = npuzzle.Vector2(j, i)
	return frame
