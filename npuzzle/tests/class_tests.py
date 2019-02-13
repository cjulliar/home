import random

from sample import Vector2, Tile, Frame, State

def run():
	vector2_test()
	tile_test()
	f = frame_test()
	state_test(f)

def vector2_test():
	print("Vector2 test\n")
	a = Vector2(10, -24)
	print("a vector : ", a)
	print("x : ", a.x)
	print("y : ", a.y)
	print("\nVector2 test : END\n\n\n")

def tile_test():
	print("Tile test\n")
	t = Tile()
	print("no attributes : ", t)
	t.value = 1
	print("added value from int : ", t)
	t.goal = Vector2(1, 1)
	print("changed goal from Vector2 : ", t)
	print("\nTile test : END\n\n\n")

def frame_test():
	print("Frame test\n")
	f = Frame(4)
	print(f)
	print("Now assigning random values for each tile :")
	values = [i for i in range(f.size * f.size)]
	random.shuffle(values)
	for i, row in enumerate(f.tiles):
		for j, tile in enumerate(row):
			tile.value = values[i * f.size + j]
			if tile.value == 0:
				f.zero = Vector2(j, i)
	print(f)
	print("creating a copy :")
	f2 = f.copy()
	print(f2)
	print("hash for f1 : ", hash(f))
	print("hash for f2 : ", hash(f2))
	return f

def state_test(f):
	print("State test\n")
	s = State(f, None, 0)
	print(s)

