from math import inf
from npuzzle import Directions, Solution, State, State_grabber

def in_frame(zero, direction, size):
	new_coord = zero + direction
	if new_coord.x < 0 or new_coord.x >= size:
		return False
	if new_coord.y < 0 or new_coord.y >= size:
		return False
	return True

def expand(state):
	for direction in Directions.ALL:
		if in_frame(state.frame.zero, direction, state.frame.size):
			new_frame = state.frame.copy()
			new_frame.push(direction)
			new_state = State(new_frame, state, state.g + 1)
			new_state.direction = direction
			yield new_state

def check_if_visited(state, path):
	for visited in path:
		if visited.frame == state.frame:
			return True
	return False

def search(path, bound, goal_state, heuristic):
	total_traveled = 1
	state = path[-1]
	state.h = heuristic(state)
	max_depth = len(path)
	if state.f > bound:
		return state.f, max_depth, 1
	if state == goal_state:
		return -1, max_depth, 1
	minf = inf
	for exp_state in expand(state):
		if not exp_state in path:
			path.append(exp_state)
			t, depth, traveled = search(path, bound, goal_state, heuristic)
			max_depth = max(depth, max_depth)
			total_traveled += traveled
			if t == -1:
				return -1, max_depth, total_traveled
			minf = min(t, minf)
			path.pop(-1)
	return minf, max_depth, total_traveled

def npuzzle_idastar(start_state, goal_state, heuristic, strategy = None):
	bound = heuristic(start_state)
	path = [start_state]
	count_traveled = 0
	max_depth = 0
	while True:
		t, depth, traveled = search(path, bound, goal_state, heuristic)
		count_traveled += traveled
		max_depth = max(depth, max_depth)
		if t == -1:
			return Solution(max_depth, count_traveled, path[-1])
		else:
			bound = t
