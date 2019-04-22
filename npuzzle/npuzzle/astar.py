from npuzzle import Directions, Solution, State, State_grabber, State_queue

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
			yield new_state, direction

def link_states(cur_state, exp_state):
	cur_state.links.add(exp_state)
	exp_state.links.add(cur_state)

def npuzzle_astar(start_state, goal_state, heuristic, strategy):
	closed = set()
	opened = State_queue(start_state, strategy)
	select_count = 0
	while len(opened) > 0:
		current = opened.pop()
		select_count += 1
		if current.frame == goal_state.frame:
			return Solution(len(opened) + len(closed), select_count, current)
		closed.add(current)
		for expanded, direction in expand(current):
			grab = State_grabber(expanded)
			in_opened = grab in opened.set
			in_closed = grab in closed
			if in_opened or in_closed:
				if grab.real_value.g > current.g + 1:
					expanded = grab.real_value
					expanded.g = current.g + 1
					if in_opened:
						opened.remove(expanded)
					if in_closed:
						closed.remove(expanded)
				else:
					continue
			expanded.h = heuristic(expanded)
			expanded.direction = direction
			expanded.parent = current
			link_states(current, expanded)
			opened.add(expanded)
