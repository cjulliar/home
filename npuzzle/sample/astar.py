from sample import Directions, Solution, State

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

def check_in_list(item, list_):
	for i in range(len(list_)):
		if item.frame == list_[i].frame:
			item_from_list = list_.pop(i)
			return True, item_from_list
	return False, item

def link_states(cur_state, exp_state):
	if not exp_state in cur_state.links:
		cur_state.links.append(exp_state)
	if not cur_state in exp_state.links:
		exp_state.links.append(cur_state)

def npuzzle_solver(start_state, goal_state, heuristic, strategy):
	"""
		heuristic is a function
		strategy is a lambda function to sort states
	"""
	opened_states = [state for state, __ in expand(start_state)]
	for state in opened_states:
		state.h = heuristic(state)
	closed_states = [start_state]
	select_count = 0
	while len(opened_states) > 0:
		opened_states.sort(key = strategy)
		cur_state = opened_states.pop(0)
		select_count += 1
		if cur_state.frame == goal_state.frame:
			return Solution(opened_states, closed_states, \
				select_count, cur_state)
		closed_states.append(cur_state)
		for exp_state, direction in expand(cur_state):
			in_opened, exp_state = check_in_list(exp_state, opened_states)
			if not in_opened:
				in_closed, exp_state = check_in_list(exp_state, closed_states)
			else:
				in_closed = False
			if not in_opened and not in_closed:
				exp_state.h = heuristic(exp_state)
				exp_state.direction = direction
				opened_states.insert(0, exp_state)
				link_states(exp_state, cur_state)
			elif exp_state.g > cur_state.g + 1:
				exp_state.g = cur_state.g + 1
				exp_state.parent = cur_state
				exp_state.direction = direction
				opened_states.insert(0, exp_state)
				link_states(exp_state, cur_state)
			else:
				closed_states.insert(0, exp_state)
