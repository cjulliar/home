from sample import Vector2, State, Frame

def get_goal(value, size):
	x = (value - 1) % size
	y = int((value - x) / size)
	return Vector2(x, y)

def fetch_tile(value, tiles):
	for i, col in enumerate(tiles):
		for j, tile in enumerate(col):
			if tile.value == value:
				return tile, Vector2(j, i)
	return None

def compute_zero_distance(frame):
	zero_goal = Vector2(frame.size - 1, frame.size - 1)
	frame.tiles[frame.zero.y][frame.zero.x].goal = zero_goal
	vdist = zero_goal - frame.zero
	return abs(vdist.x) + abs(vdist.y)

def organize_goal_frame(frame):
	count_swaps = 0
	zero_distance = compute_zero_distance(frame)
	for value in range(1, frame.size * frame.size):
		goal = get_goal(value, frame.size)
		tile, coord = fetch_tile(value, frame.tiles)
		if coord != goal:
			frame.tiles[coord.y][coord.x] = frame.tiles[goal.y][goal.x]
			frame.tiles[goal.y][goal.x] = tile
			count_swaps += 1
		tile.goal = goal
	if count_swaps % 2 == zero_distance % 2:
		solvable = True
	else:
		solvable = False
	return frame, solvable

def npuzzle_init_states(start_frame):
	start_state = State(start_frame, None, 0)
	goal_frame, solvable = organize_goal_frame(start_state.frame.copy())
	goal_frame.zero = Vector2(goal_frame.size - 1, goal_frame.size - 1)
	goal_state = State(goal_frame, None, -1)
	return start_state, goal_state, solvable
