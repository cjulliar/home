from npuzzle.classes import Vector2, Frame, Tile

class State:
	"""
		g : movement cost
		h : heuristic cost
		f : total cost (sum of g and h)
		Setting h value also updates f
		You can't directly update f
	"""
	def __init__(self, frame, parent, g):
		self.frame = frame
		self.parent = parent
		self.index = None
		self._g = g
		self._h = 0
		self._f = g
		self.links = set()
		if parent is not None:
			self.links.add(parent)
		self.direction = Vector2(0, 0)
	
	def __str__(self):
		str_ = 'parent : {}\n'.format(repr(self.parent))
		str_ += 'links : {}\n'.format(self.links)
		str_ += 'g = {} | h = {} | f = {}\n'.format(self.g, self.h, self.f)
		str_ += str(self.frame)
		return str_
	
	def __hash__(self):
		return hash(self.frame)
	
	@property
	def h(self):
		return self._h
	
	@h.setter
	def h(self, h):
		self._h = h
		self._f = self._g + h

	@property
	def g(self):
		return self._g
	
	@g.setter
	def g(self, g):
		self._g = g
		self._f = self._h + g

	@property
	def f(self):
		return self._f

class State_grabber:
	def __init__(self, target):
		self.target = target
	
	def __hash__(self):
		return hash(self.target)
	
	def __eq__(self, other):
		if hash(self.target) == hash(other):
			self.real_value = other
			return True
		return False

class State_queue:
	def __init__(self, start, strategy):
		self.queue = [start]
		self.set = set()
		self.set.add(start)
		if strategy == 'greedy' \
			or (strategy is None and start.frame.size >= 4):
			self.add = self.add_greedy
	
	def add(self, state):
		i = len(self.queue) - 1
		if i <= 0 or self.queue[0].f < state.f:
			self.queue.insert(0, state)
		else:
			while i >= 0 and self.queue[i].f < state.f:
				i -= 1
			while i >= 0 and self.queue[i].h < state.h \
					and self.queue[i].f == state.f:
				i -= 1
			self.queue.insert(i + 1, state)
		self.set.add(state)
	
	def add_greedy(self, state):
		i = len(self.queue) - 1
		if i <= 0 or self.queue[0].h < state.h:
			self.queue.insert(0, state)
		else:
			while i >= 0 and self.queue[i].h < state.h:
				i -= 1
			while i >= 0 and self.queue[i].f < state.f \
					and self.queue[i].h == state.h:
				i -= 1
			self.queue.insert(i + 1, state)
		self.set.add(state)
	
	def remove(self, state):
		self.set.remove(state)
		self.queue.remove(state)

	def pop(self):
		state = self.queue.pop(-1)
		self.set.remove(state)
		return state
	
	def __len__(self):
		return len(self.set)
