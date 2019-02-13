from sample import Vector2

def manhattan_distance(state):
	total_distance = 0
	for i, row in enumerate(state.frame.tiles):
		for j, tile in enumerate(row):
			if tile.value != 0:
				vdir = Vector2(j, i) - tile.goal
				mdist = abs(vdir.x) + abs(vdir.y)
				total_distance += mdist
	return total_distance

def linear_conflict(state):
	def conflicts(state, tile_coord, tile_goal):
		count = 0
		if tile_coord.y == tile_goal.y:
			for i in range(tile_goal.x, tile_coord.x):
				if state.frame.tiles[tile_coord.y][i].goal.y == tile_goal.y:
					count += 1
		elif tile_coord.x == tile_goal.x:
			for j in range(tile_goal.y, tile_coord.y):
				if state.frame.tiles[j][tile_coord.x].goal.x == tile_goal.x:
					count +=1
		return count

	total_distance = 0
	for i, row in enumerate(state.frame.tiles):
		for j, tile in enumerate(row):
			if tile.value != 0:
				vdir = Vector2(j, i) - tile.goal
				smdist = abs(vdir.x) + abs(vdir.y)
				smdist += conflicts(state, Vector2(j, i), tile.goal)
				total_distance += smdist
	return total_distance

def hamming_distance(state):
	hdist = 0
	for i, row in enumerate(state.frame.tiles):
		for j, tile in enumerate(row):
			if tile.value != 0 and Vector2(j, i) != tile.goal:
				hdist += 1
	return hdist


