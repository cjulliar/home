from npuzzle import Vector2, State, Frame

def get_goal(value, goal):
	for j, col in enumerate(goal):
		for i, cell in enumerate(col):
			if value == cell:
				return Vector2(i, j)
	raise Exception

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

def set_goals(frame, goal):
	for value in range(frame.size * frame.size):
		tile_goal = get_goal(value, goal)
		tile, coord = fetch_tile(value, frame.tiles)
		tile.goal = tile_goal

def push_the_snail(goal):
	for j, col in enumerate(goal):
		for i, v in enumerate(col):
			if v == 0:
				zero = Vector2(i, j)
	while zero.x < len(goal) - 1:
		goal[zero.y][zero.x] = goal[zero.y][zero.x + 1]
		goal[zero.y][zero.x + 1] = 0
		zero.x += 1
	while zero.y < len(goal) - 1:
		goal[zero.y][zero.x] = goal[zero.y + 1][zero.x]
		goal[zero.y + 1][zero.x] = 0
		zero.y += 1
	return goal

def fetch_tile(value, tiles):
	for i, col in enumerate(tiles):
		for j, tile in enumerate(col):
			if tile.value == value:
				return tile, Vector2(j, i)
	return None

def make_goal_frame(frame):
	goal = gen_that_fin_snail_goal(frame.size)
	for value in range(frame.size * frame.size):
		tile_goal = get_goal(value, goal)
		tile, coord = fetch_tile(value, frame.tiles)
		if coord != tile_goal:
			frame.tiles[coord.y][coord.x] = frame.tiles[tile_goal.y][tile_goal.x]
			frame.tiles[tile_goal.y][tile_goal.x] = tile
		tile.goal = tile_goal
		if tile.value == 0:
			frame.zero = tile_goal
	return frame

def check_solvable(frame):
	def is_even(n):
		return n % 2 == 0

	set_goals(frame, push_the_snail(gen_that_fin_snail_goal(frame.size)))
	values = []
	for row in frame.tiles:
		for tile in row:
			if tile.value != 0:
				values.append(tile.goal.x + tile.goal.y * frame.size)
	inversions = 0
	for i, v1 in enumerate(values):
		for j in range(i + 1, len(values)):
			if v1 > values[j]:
				inversions += 1
	set_goals(frame, gen_that_fin_snail_goal(frame.size))
	if is_even(frame.size):
		return is_even(frame.size - frame.zero.y) != is_even(inversions)
	else:
		return is_even(inversions)

def npuzzle_init_states(start_frame):
	start_state = State(start_frame, None, 0)
	goal_frame = make_goal_frame(start_state.frame.copy())
	solvable = check_solvable(start_frame)
	goal_state = State(goal_frame, None, -1)
	return start_state, goal_state, solvable
